//
// Created by Cain Martin on 2024/12/04.
//

#include "Renderer.h"
#include "RendererFactory.h"

Renderer::Renderer(GLFWwindow* window)
: m_renderer(create_renderer(window))
{
}

Renderer::~Renderer()
{
    m_renderer->shutdown();
}

void Renderer::begin_draw()
{
    m_renderer->begin_draw();
}

void Renderer::draw()
{
    m_renderer->draw();
}

void Renderer::end_draw()
{
    m_renderer->end_draw();
}
