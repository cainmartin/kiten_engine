//
// Created by Cain Martin on 2024/12/04.
//

#include "Renderer.h"
#include "RendererFactory.h"

Renderer::Renderer()
: m_renderer(create_renderer())
{
}

void Renderer::initialize()
{
    m_renderer->initialize();
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

void Renderer::shutdown()
{
    m_renderer->shutdown();
}