//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_GL_SHADER_H
#define KITEN_ENGINE_GL_SHADER_H

#include "../interface/IShader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

using get_iv_func  = void(*)(GLuint, GLenum, GLint*);
using get_info_log_func = void(*)(GLuint, GLsizei, GLsizei*, GLchar*);

class GL_Shader : public IShader
{
public:
    GL_Shader(const std::string& vs_source, const std::string& fs_source);
    ~GL_Shader() override;

    void bind() override;
    void unbind() override;

private:
    GLuint compile(const std::string& source, GLenum type);
    GLuint link(GLuint vs_shader, GLuint fs_shader);
    bool check_errors(GLuint object, GLenum status_type, get_iv_func get_iv, get_info_log_func get_info_log, std::vector<GLchar>& info_log);

    GLuint m_program_id;
};

#endif //KITEN_ENGINE_GL_SHADER_H
