//
// Created by Cain Martin on 2024/12/07.
//

#ifndef KITEN_ENGINE_VERTEX_H
#define KITEN_ENGINE_VERTEX_H

#include <glm/glm.hpp>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 tex_coords;
};


#endif //KITEN_ENGINE_VERTEX_H
