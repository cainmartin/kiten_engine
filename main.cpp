#include <iostream>
#include "src/core/FileLoader.h"
#include "src/platform/Window.h"
#include "src/Application.h"

int main()
{
    //ResourceManager::initialize("/Users/cmartin/Development/cpp/kiten_engine/");
    ResourceManager::initialize("c:/dev/cpp/kiten_engine/");

    try
    {
        Application app;
        app.initialize();
        app.run();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
