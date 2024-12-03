//
// Created by Cain Martin on 2024/12/03.
//

#include "ResourceManager.h"

std::filesystem::path ResourceManager::m_base_path;

void ResourceManager::initialize(const std::filesystem::path& base_path)
{
    if (!std::filesystem::exists(base_path) || !std::filesystem::is_directory(base_path))
    {
        throw std::runtime_error("Base path is not valid");
    }

    m_base_path = std::filesystem::absolute(base_path);
}

std::filesystem::path ResourceManager::get_path(const std::filesystem::path &relative_path)
{
    if (relative_path.is_absolute())
    {
        return relative_path;
    }

    return m_base_path / relative_path;
}