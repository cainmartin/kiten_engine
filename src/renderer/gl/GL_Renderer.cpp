//
// Created by Cain Martin on 2024/12/04.
//

#include "GL_Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GL_Renderer::GL_Renderer(GLFWwindow* window)
: m_window(window)
{

}

GL_Renderer::~GL_Renderer()
{
    m_window = nullptr;
    glfwTerminate();
}

void GL_Renderer::begin_draw()
{
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
}

void GL_Renderer::draw()
{
}

void GL_Renderer::end_draw()
{
    if (!m_window)
    {
        return;
    }

    glfwSwapBuffers(m_window);
}

void GL_Renderer::shutdown()
{
}
