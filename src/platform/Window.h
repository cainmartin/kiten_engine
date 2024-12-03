//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_WINDOW_H
#define KITEN_ENGINE_WINDOW_H

#include <glad/glad.h>
#include <glfw/glfw3.h>

class Window
{
public:
    Window();
    ~Window();

    void initialize();
    void shutdown();

private:
    GLFWwindow* m_window;
};


#endif //KITEN_ENGINE_WINDOW_H
