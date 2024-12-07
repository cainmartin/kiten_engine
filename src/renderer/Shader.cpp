//
// Created by Cain Martin on 2024/12/04.
//

#include "Shader.h"
#include <vector>
#include <stdexcept>
#include <glad/glad.h>

using get_iv_func  = void(*)(GLuint, GLenum, GLint*);
using get_info_log_func = void(*)(GLuint, GLsizei, GLsizei*, GLchar*);

class Shader::ShaderImpl
{
public:
    ShaderImpl(const std::string& vs_source, const std::string& fs_source)
    : m_program_id(0)
    {
        // TODO: If we add other renderers - we can use a factory or similar to
        // initialize m_shader
        initialize(vs_source, fs_source);
    }

    ~ShaderImpl();

    void bind();
    void unbind();

    void set_int(const std::string& name, int value);

private:
    void initialize(const std::string& vs_source, const std::string& fs_source);
    GLuint compile(const std::string& source, GLenum type);
    GLuint link(GLuint vs_shader, GLuint fs_shader);
    bool check_errors(GLuint object, GLenum status_type, get_iv_func get_iv, get_info_log_func get_info_log, std::vector<GLchar>& info_log);

    GLuint m_program_id;
};

Shader::Shader(const std::string& fs_source, const std::string& vs_source)
: m_impl(std::make_unique<ShaderImpl>(fs_source, vs_source))
{

}

Shader::~Shader()
{

}

void Shader::bind()
{
    m_impl->bind();
}

void Shader::unbind()
{
    m_impl->unbind();
}

void Shader::ShaderImpl::initialize(const std::string& vs_source, const std::string& fs_source)
{
    GLuint vs_shader = 0;
    GLuint fs_shader = 0;

    try
    {
        vs_shader = compile(vs_source, GL_VERTEX_SHADER);
        fs_shader = compile(fs_source, GL_FRAGMENT_SHADER);
        m_program_id = link(vs_shader, fs_shader);

        glDetachShader(m_program_id, vs_shader);
        glDetachShader(m_program_id, fs_shader);
    }
    catch (std::runtime_error& re)
    {
        if (vs_shader != 0) glDeleteShader(vs_shader);
        if (fs_shader != 0) glDeleteShader(fs_shader);

        throw;
    }

    if (vs_shader != 0) glDeleteShader(vs_shader);
    if (fs_shader != 0) glDeleteShader(fs_shader);
}

Shader::ShaderImpl::~ShaderImpl()
{
    if (m_program_id != 0)
    {
        glDeleteProgram(m_program_id);
    }
}

void Shader::ShaderImpl::bind()
{
    glUseProgram(m_program_id);
}

void Shader::ShaderImpl::unbind()
{
    glUseProgram(0);
}

GLuint Shader::ShaderImpl::compile(const std::string& shader_source, GLenum type)
{
    GLuint shader = glCreateShader(type);
    const char* source = shader_source.c_str();
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    std::vector<GLchar> info_log;
    if (!check_errors(shader, GL_COMPILE_STATUS, glGetShaderiv, glGetShaderInfoLog, info_log))
    {
        glDeleteShader(shader);
        throw std::runtime_error(info_log.data());
    }

    return shader;
}

GLuint Shader::ShaderImpl::link(GLuint vertex_shader, GLuint fragment_shader)
{
    auto program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    std::vector<GLchar> info_log;
    if (!check_errors(program, GL_LINK_STATUS, glGetProgramiv, glGetProgramInfoLog, info_log))
    {
        glDeleteProgram(program);
        throw std::runtime_error(info_log.data());
    }

    return program;
}

bool Shader::ShaderImpl::check_errors(GLuint object, GLenum status_type, get_iv_func get_iv, get_info_log_func get_info_log, std::vector<GLchar>& info_log)
{
    GLint status = 0;
    get_iv(object, status_type, &status);

    if (status == GL_FALSE)
    {
        GLint max_length = 0;
        get_iv(object, GL_INFO_LOG_LENGTH, &max_length);
        info_log.resize(max_length);

        // This is being paranoid
        if (!info_log.empty() && info_log.back() != '\0')
        {
            info_log.push_back('\0');
        }

        get_info_log(object, max_length, &max_length, info_log.data());

        return false;
    }

    return true;
}

void Shader::ShaderImpl::set_int(const std::string& name, int value)
{

}