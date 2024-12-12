//
// Created by Cain Martin on 2024/12/12.
//

#ifndef KITEN_ENGINE_ICOMPONENT_H
#define KITEN_ENGINE_ICOMPONENT_H

#include "../Entity.h"

class IComponent
{
public:
    virtual ~IComponent() = 0;

    virtual void on_attach(Entity& entity) {}
    virtual void on_detach(Entity& entity) {}
    virtual void update(float delta_time) {}
};

#endif //KITEN_ENGINE_ICOMPONENT_H
