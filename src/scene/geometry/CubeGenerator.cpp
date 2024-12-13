//
// Created by Cain Martin on 2024/12/13.
//

#include "../../renderer/MeshData.h"
#include "CubeGenerator.h"

MeshData CubeGenerator::generate()
{
    MeshData data;

    data.vertices = {
            // Positions                      // Normals                    // Texture Coords
            { glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f) }, // 0
            { glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f) }, // 1
            { glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f) }, // 2
            { glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f) }, // 3

            { glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(0.0f, 0.0f) }, // 4
            { glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(1.0f, 0.0f) }, // 5
            { glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(1.0f, 1.0f) }, // 6
            { glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(0.0f, 1.0f) }  // 7
    };

    data.indices = {
            // Back face
            0, 1, 2,
            2, 3, 0,

            // Front face
            4, 5, 6,
            6, 7, 4,

            // Left face
            4, 0, 3,
            3, 7, 4,

            // Right face
            1, 5, 6,
            6, 2, 1,

            // Bottom face
            4, 5, 1,
            1, 0, 4,

            // Top face
            3, 2, 6,
            6, 7, 3
    };

    return data;
}