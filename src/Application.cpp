//
// Created by cmartin on 2024/12/05.
//

#include "Application.h"
#include "renderer/Mesh.h"
#include "renderer/Shader.h"
#include "core/FileLoader.h"

Application::~Application()
{
    m_window->shutdown();
}
void Application::initialize()
{
    m_window = std::make_unique<Window>();
    m_renderer = std::make_unique<Renderer>(m_window->get_native_window());
}

void Application::run()
{

    // Define our triangle vertices
    std::vector<Vertex> vertices = {
            { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f,0.0f,1.0f), glm::vec2(0.0f,0.0f) },
            { glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.0f,0.0f,1.0f), glm::vec2(0.0f,0.0f) },
            { glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec3(0.0f,0.0f,1.0f), glm::vec2(0.0f,0.0f) }
    };

    // Define the indices for the triangle (just 0,1,2 since it's a single triangle)
    std::vector<unsigned int> indices = { 0, 1, 2 };

    Mesh mesh(vertices, indices);
    Shader shader(KITEN::load_text("assets/shaders/GL/vs_basic.glsl"), KITEN::load_text("assets/shaders/GL/fs_basic.glsl"));

    while (!m_window->should_close())
    {
        m_renderer->begin_draw();

        shader.bind();
        mesh.draw();
        shader.unbind();


        m_renderer->end_draw();
    }
}