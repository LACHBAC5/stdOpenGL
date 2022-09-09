#pragma once

#include <stdio.h>
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace lb{
    struct shader_program{
        unsigned int vertex=0, fragment=0, geometry=0;
        unsigned int program=0;
    };
    void setup_vertex_shader(shader_program &p, const char* code);
    void setup_fragment_shader(shader_program &p, const char* code);
    void setup_geometry_shader(shader_program &p, const char* code);
    void destroy_vertex_shader(shader_program &p);
    void destroy_fragment_shader(shader_program &p);
    void destroy_geometry_shader(shader_program &p);
    void destroy_program(shader_program &p);
    void create_program(shader_program &p);
    void setInt(shader_program &p, const char* name, int value);
    void setFloat(shader_program &p, const char* name, float value);
    void setMat4(shader_program &p, const char* name, glm::mat4 value);
    void setMat3(shader_program &p, const char* name, glm::mat3 value);
    void setVec4(shader_program &p, const char* name, glm::vec4 value);
}