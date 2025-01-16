//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_WINDOW_H
#define KITEN_ENGINE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Size2d;

class Window
{
public:
    Window();
    ~Window();

    [[nodiscard]] bool should_close() const;
    void set_window_should_close();
    void shutdown();
    void capture_mouse(bool capture = true);

    [[nodiscard]] Size2d get_framebuffer_size() const;
    [[nodiscard]] GLFWwindow* get_native_window() const;

private:
    GLFWwindow* m_window;
};


#endif //KITEN_ENGINE_WINDOW_H
