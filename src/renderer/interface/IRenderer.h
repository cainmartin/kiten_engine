//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_IRENDERER_H
#define KITEN_ENGINE_IRENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual void begin_draw() = 0;
    virtual void draw() = 0;
    virtual void end_draw() = 0;
    virtual void shutdown() = 0;
};

#endif //KITEN_ENGINE_IRENDERER_H
