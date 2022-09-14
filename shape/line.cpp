#include "line.hpp"

namespace lb{
    unsigned int Line::VAO=0;
    shader_program Line::shp={0,0,0};

    void Line::draw(const glm::mat4& projection){

        glUseProgram(shp.program);

        lb::setMat4(shp, "projection", projection);
        lb::setVec4(shp, "position", pos);
        lb::setVec4(shp, "color", color);

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, 1);
        glBindVertexArray(0);
    }

    void Line::init(){
        const std::string vertex_shader_code = 
        "#version 330 core\n"
        "uniform vec4 position;"
        "void main(){\n"
            "gl_Position=position;\n"
        "}\n";
        const std::string geometry_shader_code =
        "#version 330 core\n"
        "layout (points) in;\n"
        "layout (line_strip, max_vertices=2) out;\n"
        "uniform mat4 projection;\n"
        "void main(){\n"
            "gl_Position=projection*vec4(gl_in[0].gl_Position.x, gl_in[0].gl_Position.y, 0.0, 1.0);\n"
            "EmitVertex();\n"
            "gl_Position=projection*vec4(gl_in[0].gl_Position.z, gl_in[0].gl_Position.w, 0.0, 1.0);\n"
            "EmitVertex();\n"
            "EndPrimitive();\n"
        "}\n";
        const std::string fragment_shader_code =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 color;"
        "void main(){\n"
            "FragColor=color;\n"
        "}\n\0";

        lb::setup_vertex_shader(shp, vertex_shader_code.c_str());
        lb::setup_geometry_shader(shp, geometry_shader_code.c_str());
        lb::setup_fragment_shader(shp, fragment_shader_code.c_str());
        lb::create_program(shp);

        glGenVertexArrays(1, &VAO);
    }

    void Line::fina(){
        lb::destroy_vertex_shader(shp);
        lb::destroy_fragment_shader(shp);
        lb::destroy_program(shp);
        glDeleteVertexArrays(1, &VAO);
    }
}
