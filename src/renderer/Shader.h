//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_SHADER_H
#define KITEN_ENGINE_SHADER_H

#include <memory>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const std::string& fs_source, const std::string& vs_source);
    ~Shader();

    void bind();
    void unbind();

    void set_int(const std::string& location, int value);
    void set_float(const std::string& location, float value);
    void set_vec(const std::string& location, const glm::vec2& value);
    void set_vec(const std::string& location, const glm::vec3& value);
    void set_vec(const std::string& location, const glm::vec4& value);
    void set_mat(const std::string& location, const glm::mat3& value);
    void set_mat(const std::string& location, const glm::mat4& value);

private:
    class ShaderImpl;
    std::unique_ptr<ShaderImpl> m_impl;
};


#endif //KITEN_ENGINE_SHADER_H
