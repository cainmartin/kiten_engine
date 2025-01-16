//
// Created by Cain Martin on 2024/12/04.
//

#include "Window.h"
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../math/DataTypes.h"

Window::Window()
: m_window(nullptr)
{
    if (!glfwInit())
    {
        throw std::runtime_error("Unable to open file\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window = glfwCreateWindow(800, 600, "Donkey Fartbox", nullptr, nullptr);
    if (!m_window)
    {
        throw std::runtime_error("Unable to create the window");
    }

    glfwMakeContextCurrent(m_window);

    // Initialize glad after setting OpenGL context
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
       glViewport(0, 0, width, height);
    });
}

Window::~Window()
{
    shutdown();
}

bool Window::should_close() const
{
    return glfwWindowShouldClose(m_window);
}

void Window::set_window_should_close()
{
    glfwSetWindowShouldClose(m_window, GL_TRUE);
}

void Window::shutdown()
{
    glfwTerminate();

    if (m_window)
    {
        glfwDestroyWindow(m_window);
    }
}

Size2d Window::get_framebuffer_size() const
{
    int width, height;
    glfwGetFramebufferSize(m_window, &width, &height);

    return { width, height };
}

GLFWwindow* Window::get_native_window() const
{
    return m_window;
}
