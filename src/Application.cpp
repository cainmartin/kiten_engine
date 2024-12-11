//
// Created by cmartin on 2024/12/05.
//

#include "Application.h"
#include "core/FileLoader.h"
#include "core/Timer.h"
#include "renderer/Mesh.h"
#include "renderer/Shader.h"
#include "scene/Camera.h"
#include "scene/Entity.h"
#include <iostream>
#include <glm/glm.hpp>

Application::~Application()
{
    m_window->shutdown();
}

void Application::initialize()
{
    m_window = std::make_unique<Window>();
    m_renderer = std::make_unique<Renderer>(m_window->get_native_window());
    m_input_manager = std::make_unique<InputManager>();
    m_input_manager->set_glfw_window(m_window->get_native_window());
}

void Application::run()
{
    std::vector<Vertex> vertices = {
            // Positions            // Normals             // Texture Coords
            { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f) }, // 0
            { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f) }, // 1
            { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f) }, // 2
            { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f) }, // 3

            { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(0.0f, 0.0f) }, // 4
            { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(1.0f, 0.0f) }, // 5
            { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(1.0f, 1.0f) }, // 6
            { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(0.0f, 1.0f) }  // 7
    };

    std::vector<unsigned int> indices = {
            // Back face
            0, 1, 2,
            2, 3, 0,

            // Front face
            4, 5, 6,
            6, 7, 4,

            // Left face
            4, 0, 3,
            3, 7, 4,

            // Right face
            1, 5, 6,
            6, 2, 1,

            // Bottom face
            4, 5, 1,
            1, 0, 4,

            // Top face
            3, 2, 6,
            6, 7, 3
    };

    Mesh cube_mesh(vertices, indices);
    Entity cube_entity(&cube_mesh);
    Shader cube_shader(KITEN::load_text("assets/shaders/GL/vs_basic.glsl"), KITEN::load_text("assets/shaders/GL/fs_basic.glsl"));

    Timer timer;

    // Camera::Camera(const glm::vec3& position, float pitch, float yaw, float fov, float aspect, float near, float far)
    Camera camera({0.0, 0.0, -5.0}, 0.0, 0.0, 60.0, 800.0/600.0, 0.1, 100.0);

    float rot = 0.0f;

    while (!m_window->should_close())
    {
        m_input_manager->update();
        if (m_input_manager->is_key_just_pressed(Key::Esc))
        {
            m_window->set_window_should_close();
        }

        float delta_time = timer.get_delta_time();

        camera.process_input(*m_input_manager, delta_time);

        // Update entity position
        float rotation_speed = 1.0f * delta_time; // 1 radian per second, just as an example
        glm::quat current_rotation = cube_entity.get_transform().get_rotation();
        glm::vec3 axis = glm::vec3(0.0, 1.0, 0.0);
        glm::quat increment = glm::angleAxis(rotation_speed, axis);
        cube_entity.set_rotation(increment * current_rotation);
        cube_entity.set_position({ 0.0, 0.0, 0.0 });

        m_renderer->begin_draw();
        {
            cube_shader.bind();

            auto model = cube_entity.get_transform().get_matrix();

            cube_shader.set_mat("model", model);
            cube_shader.set_mat("view", camera.get_view_matrix());
            cube_shader.set_mat("projection", camera.get_projection_matrix());

            cube_entity.draw();

            cube_shader.unbind();
        }

        m_renderer->end_draw();
    }
}