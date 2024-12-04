//
// Created by Cain Martin on 2024/12/04.
//

#include "RendererFactory.h"
#include "gl/GL_Renderer.h"

std::unique_ptr<IRenderer> create_renderer()
{
    // TODO: Will need to add a selector for different renderers
    return std::make_unique<GL_Renderer>();
}