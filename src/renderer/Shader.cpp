//
// Created by Cain Martin on 2024/12/04.
//

#include "gl/GL_Shader.h"
#include "Shader.h"

class Shader::ShaderImpl
{
public:
    ShaderImpl(const std::string& vs_source, const std::string& fs_source)
    {
        // TODO: If we add other renderers - we can use a factory or similar to
        // initialize m_shader
        m_shader = std::make_unique<GL_Shader>(vs_source, fs_source);
    }

    void bind() { m_shader->bind(); }
    void unbind() { m_shader->unbind(); }

private:
    std::unique_ptr<IShader> m_shader;
};

void Shader::bind()
{
    m_impl->bind();
}

void Shader::unbind()
{
    m_impl->unbind();
}