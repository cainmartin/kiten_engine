//
// Created by cmartin on 2024/12/11.
//

#include "Entity.h"


void Entity::draw()
{
    if (!m_mesh) return;

    m_mesh->draw();
}