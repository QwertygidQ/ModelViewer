#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

struct Shader
{
    Shader(const std::string &vertex_path, const std::string &fragment_path);

    void use() const;
    void setMat4(const std::string &uniform_name, const glm::mat4 &matrix) const;

    GLuint program_id;

private:
    GLint getUniformLocation(const std::string &uniform_name) const;
};

#endif