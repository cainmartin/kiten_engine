#include <iostream>
#include "src/core/FileLoader.h"

int main()
{
    std::cout << "Kiten engine/n";
    ResourceManager::initialize("/Users/cmartin/Development/cpp/kiten_engine/");
    std::string vs_source = KITEN::load_text("assets/shaders/GL/vs_basic.glsl");

    return 0;
}
