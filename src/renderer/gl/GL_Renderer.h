//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_GL_RENDERER_H
#define KITEN_ENGINE_GL_RENDERER_H

#include "../interface/IRenderer.h"
#include "../../platform/Window.h"

class GL_Renderer : public IRenderer
{
public:
    explicit GL_Renderer(GLFWwindow* window);
    ~GL_Renderer() override;

    void begin_draw()  override;
    void draw()  override;
    void end_draw()  override;
    void shutdown() override;


private:
    GLFWwindow* m_window;
};


#endif //KITEN_ENGINE_GL_RENDERER_H
