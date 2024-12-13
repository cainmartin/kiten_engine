//
// Created by Cain Martin on 2024/12/13.
//

#ifndef KITEN_ENGINE_MESHDATA_H
#define KITEN_ENGINE_MESHDATA_H

#include <vector>
#include "Vertex.h"

struct MeshData
{
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
};

#endif //KITEN_ENGINE_MESHDATA_H
