//
// Created by Cain Martin on 2024/12/03.
//

#ifndef KITEN_ENGINE_RESOURCEMANAGER_H
#define KITEN_ENGINE_RESOURCEMANAGER_H

#include <string>
#include <filesystem>

class ResourceManager
{
public:
    ResourceManager() = delete;
    ~ResourceManager() = delete;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    static void initialize(const std::filesystem::path& base_path);
    static std::filesystem::path get_path(const std::filesystem::path& relative_path);

private:
    static std::filesystem::path m_base_path;
};


#endif //KITEN_ENGINE_RESOURCEMANAGER_H
