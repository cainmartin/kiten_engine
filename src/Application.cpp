//
// Created by cmartin on 2024/12/05.
//

#include "Application.h"
#include "core/FileLoader.h"
#include "core/Timer.h"
#include "math/DataTypes.h"
#include "renderer/Mesh.h"
#include "renderer/Shader.h"
#include "scene/components/CameraComponent.h"
#include "scene/Entity.h"
#include "scene/geometry/CubeGenerator.h"
#include <iostream>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glm/glm.hpp>

Application::~Application()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    m_window->shutdown();
}

void Application::initialize()
{
    m_window = std::make_unique<Window>();
    m_renderer = std::make_unique<Renderer>(m_window->get_native_window());
    m_input_manager = std::make_unique<InputManager>();
    m_input_manager->set_glfw_window(m_window->get_native_window());

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

// Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_window->get_native_window(), true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();
}

void Application::run()
{
    auto cube = CubeGenerator::generate();
    Mesh cube_mesh(cube);
    Entity cube_entity(&cube_mesh);
    Shader cube_shader(KITEN::load_text("assets/shaders/GL/vs_basic.glsl"), KITEN::load_text("assets/shaders/GL/fs_basic.glsl"));

    Timer timer;

    // Camera::Camera(const glm::vec3& position, float pitch, float yaw, float fov, float aspect, float near, float far)
    Size2d size = m_window->get_framebuffer_size();
    float aspect_ratio = static_cast<float>(size.width) / static_cast<float>(size.height);
    CameraComponent camera({0.0, 0.0, -5.0}, 0.0, 0.0, 60.0, aspect_ratio, 0.1, 100.0);
    camera.set_look_at({0.0, 0.0, 0.0});
    m_window->capture_mouse();

    float rot = 0.0f;

    while (!m_window->should_close())
    {
        glfwPollEvents();
        m_input_manager->update();

        if (m_input_manager->is_key_just_pressed(Key::Esc))
        {
            m_window->set_window_should_close();
        }

        float delta_time = timer.get_delta_time();
        size = m_window->get_framebuffer_size();

        camera.set_aspect_ratio(static_cast<float>(size.width) / static_cast<float>(size.height));
        camera.process_input(*m_input_manager, delta_time);

        // Update entity position
        float rotation_speed = 1.0f * delta_time; // 1 radian per second, just as an example
        glm::quat current_rotation = cube_entity.get_transform().get_rotation();
        glm::vec3 axis = glm::normalize(glm::vec3(1.0, 1.0, 0.0));
        glm::quat increment = glm::angleAxis(rotation_speed, axis);
        cube_entity.set_rotation(increment * current_rotation);
        cube_entity.set_position({ 0.0, 0.0, 0.0 });

        m_renderer->begin_draw();
        {
            imgui_start();

            cube_shader.bind();

            auto model = cube_entity.get_transform().get_matrix();

            cube_shader.set_mat("model", model);
            cube_shader.set_mat("view", camera.get_view_matrix());
            cube_shader.set_mat("projection", camera.get_projection_matrix());

            cube_entity.draw();

            cube_shader.unbind();

            imgui_end();
        }

        m_renderer->end_draw();
    }
}

void Application::imgui_start()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    // ImGui::ShowDemoWindow();
}

void Application::imgui_end()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}