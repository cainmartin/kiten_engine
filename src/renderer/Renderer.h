//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_RENDERER_H
#define KITEN_ENGINE_RENDERER_H

#include <memory>
#include "interface/IRenderer.h"

class Renderer : IRenderer
{
public:
    Renderer();
    ~Renderer() override = default;

    void initialize() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;
    void shutdown() override;

private:
    std::unique_ptr<IRenderer> m_renderer;
};


#endif //KITEN_ENGINE_RENDERER_H
