#include "shader_program.hpp"

namespace lb{
    void setup_vertex_shader(shader_program &p, const char* code){
        if(p.vertex>0){
            glDeleteShader(p.vertex);
        }
        p.vertex=glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(p.vertex, 1, &code, NULL);
        glCompileShader(p.vertex);

        int success; char infoLog[512];
        glGetShaderiv(p.vertex, GL_COMPILE_STATUS, &success);
        if(!success){
            glGetShaderInfoLog(p.vertex, 512, NULL, infoLog);
            printf("Vertex Shader Compilation Error: %s\n", infoLog);
        }
    }

    void setup_fragment_shader(shader_program &p, const char* code){
        if(p.fragment>0){
            glDeleteShader(p.fragment);
        }
        p.fragment=glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(p.fragment, 1, &code, NULL);
        glCompileShader(p.fragment);

        int success; char infoLog[512];
        glGetShaderiv(p.fragment, GL_COMPILE_STATUS, &success);
        if(!success){
            glGetShaderInfoLog(p.fragment, 512, NULL, infoLog);
            printf("Fragment Shader Compilation Error: %s\n", infoLog);
        }
    }

    void setup_geometry_shader(shader_program &p, const char* code){
        if(p.geometry>0){
            glDeleteShader(p.geometry);
        }
        p.geometry=glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(p.geometry, 1, &code, NULL);
        glCompileShader(p.geometry);

        int success; char infoLog[512];
        glGetShaderiv(p.geometry, GL_COMPILE_STATUS, &success);
        if(!success){
            glGetShaderInfoLog(p.geometry, 512, NULL, infoLog);
            printf("Geometry Shader Compilation Error: %s\n", infoLog);
        }
    }

    void destroy_vertex_shader(shader_program &p){
        glDeleteShader(p.vertex);
    }
    void destroy_fragment_shader(shader_program &p){
        glDeleteShader(p.fragment);
    }
    void destroy_geometry_shader(shader_program &p){
        glDeleteShader(p.geometry);
    }
    void destroy_program(shader_program &p){
        glDeleteProgram(p.program);
    }

    void create_program(shader_program &p){
        p.program=glCreateProgram();
        glAttachShader(p.program, p.vertex);
        glAttachShader(p.program, p.fragment);
        if(p.geometry>0){
            glAttachShader(p.program, p.geometry);
        }
        glLinkProgram(p.program);

        int success; char infoLog[512];
        glGetProgramiv(p.program, GL_LINK_STATUS, &success);
        if(!success){
            glGetProgramInfoLog(p.program, 512, NULL, infoLog);
            printf("Program Linking Error: %s\n", infoLog);
        }
    }

    void setInt(shader_program &p, const char* name, int value){
        glUniform1i(glGetUniformLocation(p.program, name), value);
    }

    void setFloat(shader_program &p, const char* name, float value){
        glUniform1f(glGetUniformLocation(p.program, name), value);
    }

    void setMat4(shader_program &p, const char* name, glm::mat4 value){
        glUniformMatrix4fv(glGetUniformLocation(p.program, name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void setMat3(shader_program &p, const char* name, glm::mat3 value){
        glUniformMatrix3fv(glGetUniformLocation(p.program, name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void setVec4(shader_program &p, const char* name, glm::vec4 value){
        glUniform4fv(glGetUniformLocation(p.program, name), 1, glm::value_ptr(value));
    }
}