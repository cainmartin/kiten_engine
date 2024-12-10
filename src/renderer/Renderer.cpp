//
// Created by Cain Martin on 2024/12/04.
//

#include "Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Renderer::Renderer(GLFWwindow* window)
        : m_window(window)
{
    glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer()
{
    m_window = nullptr;
    glfwTerminate();
}

void Renderer::begin_draw()
{
    glClearColor(0.2, 0.4, 0.2, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwPollEvents();
}

void Renderer::draw()
{
}

void Renderer::end_draw()
{
    if (!m_window)
    {
        return;
    }

    glfwSwapBuffers(m_window);
}

