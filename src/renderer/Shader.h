//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_SHADER_H
#define KITEN_ENGINE_SHADER_H

#include <memory>

class Shader
{
public:
    Shader(const std::string& fs_source, const std::string& vs_source);
    void bind();
    void unbind();

    void set_int(const std::string& name, int value);

private:
    class ShaderImpl;
    std::unique_ptr<ShaderImpl> m_impl;
};


#endif //KITEN_ENGINE_SHADER_H
