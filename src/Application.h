//
// Created by cmartin on 2024/12/05.
//

#ifndef KITEN_ENGINE_APPLICATION_H
#define KITEN_ENGINE_APPLICATION_H

#include "platform/Window.h"
#include "renderer/Renderer.h"
#include <memory>

class Application
{
public:
    Application() = default;
    ~Application();

    void initialize();
    void run();

private:
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
};


#endif //KITEN_ENGINE_APPLICATION_H
