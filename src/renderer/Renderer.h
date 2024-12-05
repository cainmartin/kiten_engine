//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_RENDERER_H
#define KITEN_ENGINE_RENDERER_H

#include <memory>
#include "interface/IRenderer.h"

class Renderer
{
public:
    explicit Renderer(GLFWwindow* window);
    ~Renderer();

    void begin_draw();
    void draw();
    void end_draw();

private:
    std::unique_ptr<IRenderer> m_renderer;
};


#endif //KITEN_ENGINE_RENDERER_H
