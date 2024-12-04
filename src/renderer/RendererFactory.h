//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_RENDERERFACTORY_H
#define KITEN_ENGINE_RENDERERFACTORY_H

#include <memory>
#include "interface/IRenderer.h"

std::unique_ptr<IRenderer> create_renderer();

#endif //KITEN_ENGINE_RENDERERFACTORY_H
