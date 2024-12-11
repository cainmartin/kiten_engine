//
// Created by Cain Martin on 2024/12/06.
//

#ifndef KITEN_ENGINE_MESH_H
#define KITEN_ENGINE_MESH_H

#include <vector>
#include <glad/glad.h>
#include "Vertex.h"
#include "../scene/Transform.h"

class Mesh
{
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);
    ~Mesh();

    void draw();

private:
    void setup_mesh();

    std::vector<Vertex> m_vertices;
    std::vector<uint32_t> m_indices;

    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
};


#endif //KITEN_ENGINE_MESH_H
