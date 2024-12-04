//
// Created by Cain Martin on 2024/12/04.
//

#include "Window.h"
#include <stdexcept>
#include <glad/glad.h>
#include <glfw/glfw3.h>

Window::Window()
{

}

Window::~Window()
{
    shutdown();
}

void Window::initialize()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Unable to open file\n");
    }

    m_window = glfwCreateWindow(800, 600, "Donkey Fartbox", nullptr, nullptr);
    if (!m_window)
    {
        throw std::runtime_error("Unable to create the window");
    }

    glfwMakeContextCurrent(m_window);
}

void Window::shutdown()
{
    glfwTerminate();

    if (m_window)
    {
        glfwDestroyWindow(m_window);
    }
}