//
// Created by cmartin on 2024/12/05.
//

#include "Application.h"
#include "renderer/RendererFactory.h"

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
    while (!m_window->should_close())
    {
        m_renderer->begin_draw();

        m_renderer->draw();

        m_renderer->end_draw();
    }
}