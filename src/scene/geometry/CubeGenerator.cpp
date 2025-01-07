//
// Created by Cain Martin on 2024/12/13.
//

#include "../../renderer/MeshData.h"
#include "CubeGenerator.h"

MeshData CubeGenerator::generate()
{
    MeshData data;

    data.vertices = {
        // Back face
        { glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
        { glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 1.0f) },
        { glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 1.0f) },

        // Front face
        { glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 0.0f) },
        { glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 1.0f) },
        { glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 1.0f) },

        // Left face
        { glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        { glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        { glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },

        // Right face
        { glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        { glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        { glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },

        // Bottom face
        { glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        { glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        { glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },

        // Top face
        { glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        { glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        { glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
    };

    data.indices = {
        0, 1, 2, 2, 3, 0, // Back face
        4, 5, 6, 6, 7, 4, // Front face
        8, 9, 10, 10, 11, 8, // Left face
        12, 13, 14, 14, 15, 12, // Right face
        16, 17, 18, 18, 19, 16, // Bottom face
        20, 21, 22, 22, 23, 20  // Top face
    };

    return data;
}
