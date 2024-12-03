//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_GL_SHADER_H
#define KITEN_ENGINE_GL_SHADER_H

#include "../interface/IShader.h"
#include <string>

class GL_Shader : public IShader
{
public:
    GL_Shader(const std::string& vs_source, const std::string& fs_source);
    ~GL_Shader();

    void bind() override;
    void unbind() override;

private:
    uint32_t m_renderer_id;
};

#endif //KITEN_ENGINE_GL_SHADER_H
