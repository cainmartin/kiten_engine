#include <iostream>
#include "src/core/FileLoader.h"
#include "src/platform/Window.h"
#include "src/Application.h"

int main()
{
    // ResourceManager::initialize("/Users/cmartin/Development/cpp/kiten_engine/");
    ResourceManager::initialize("c:/dev/cpp/kiten_engine/");
    Application app;

    app.initialize();
    app.run();

    return 0;
}
