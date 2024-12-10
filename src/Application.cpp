//
// Created by cmartin on 2024/12/05.
//

#include "Application.h"
#include "renderer/Mesh.h"
#include "renderer/Shader.h"
#include "core/FileLoader.h"
#include "scene/Camera.h"
#include "core/Timer.h"

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

    Mesh mesh(vertices, indices);
    Shader shader(KITEN::load_text("assets/shaders/GL/vs_basic.glsl"), KITEN::load_text("assets/shaders/GL/fs_basic.glsl"));
    Timer timer;

    // Camera::Camera(const glm::vec3& position, float pitch, float yaw, float fov, float aspect, float near, float far)
    Camera camera({0.0, 0.0, -5.0}, 0.0, 0.0, 60.0, 800.0/600.0, 0.1, 100.0);

    while (!m_window->should_close())
    {
        float delta_time = timer.get_delta_time();

        camera.process_input(*m_input_manager, delta_time);
        camera.set_look_at({0.0, 0.0, 0.0});

        m_renderer->begin_draw();

        shader.bind();

        auto model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(45.0f * delta_time), glm::vec3(0.0f, 1.0f, 0.0));
        shader.set_mat("model", model);
        shader.set_mat("view", camera.get_view_matrix());
        shader.set_mat("projection", camera.get_projection_matrix());

        mesh.draw();
        shader.unbind();

        m_renderer->end_draw();
    }
}