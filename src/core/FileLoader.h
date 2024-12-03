//
// Created by Cain Martin on 2024/12/03.
//

#ifndef KITEN_ENGINE_FILELOADER_H
#define KITEN_ENGINE_FILELOADER_H

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "ResourceManager.h"

namespace KITEN
{

    inline std::string load_text(const std::filesystem::path &relative_path)
    {
        std::filesystem::path full_path = ResourceManager::get_path(relative_path);
        std::ifstream file(full_path, std::ios::in);
        if (!file)
        {
            throw std::runtime_error("Unable to open file\n");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        return buffer.str();
    }

    inline void save_text(const std::filesystem::path &relative_path, const std::string &content)
    {
        std::filesystem::path full_path = ResourceManager::get_path(relative_path);
        std::ofstream file(full_path, std::ios::out | std::ios::trunc);
        if (!file)
        {
            throw std::runtime_error("Could not open file " + full_path.string() + " for writing.");
        }

        file << content;
        if (!file)
        {
            throw std::runtime_error("Could not write to file " + full_path.string());
        }
    }

    inline std::vector<char8_t> load_binary(const std::filesystem::path& relative_path)
    {
        std::filesystem::path full_path = ResourceManager::get_path(relative_path);
        std::ifstream file(full_path, std::ios::binary | std::ios::ate);
        if (!file)
        {
            throw std::runtime_error("Unable to open file " + relative_path.string());
        }

        std::streamsize size = file.tellg();
        if (size < 0)
        {
            throw std::runtime_error("Invalid file size");
        }
        file.seekg(0, std::ios::beg);

        std::vector<char8_t> buffer(static_cast<size_t>(size));
        if (!file.read(reinterpret_cast<char *>(buffer.data()), size))
        {
            throw std::runtime_error("Error reading file " + relative_path.string());
        }

        return buffer;
    }

    inline void save_binary(const std::filesystem::path& relative_path, const std::vector<char8_t> &content)
    {
        std::filesystem::path full_path = ResourceManager::get_path(relative_path);
        std::ofstream file(full_path, std::ios::out | std::ios::binary | std::ios::trunc);
        if (!file)
        {
            throw std::runtime_error("Unable to open file for " + relative_path.string() + " for writing.");
        }

        size_t content_size = content.size();
        if (content_size > static_cast<size_t>(std::numeric_limits<std::streamsize>::max()))
        {
            throw std::runtime_error("Content size exceeds maximum stream size");
        }

        file.write(reinterpret_cast<const char *>(content.data()), static_cast<std::streamsize>(content_size));
        if (!file)
        {
            throw std::runtime_error("Error writing to file " + relative_path.string());
        }
    }
}

#endif //KITEN_ENGINE_FILELOADER_H
