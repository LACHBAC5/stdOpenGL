#include "circle.hpp"

namespace lb{
    unsigned int Circle::VAO=0;
    lb::shader_program Circle::shp={0,0,0};

    void Circle::draw(const glm::mat4& projection){
        glUseProgram(shp.program);

        lb::setMat4(shp, "projection", projection);
        lb::setVec4(shp, "position", glm::vec4(pos[0], pos[1], 0.0, 1.0));
        lb::setVec4(shp, "color", glm::vec4(1.0, 1.0, 1.0, 1.0));
        lb::setInt(shp, "angle", seg_angle);
        lb::setFloat(shp, "radius", r);

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, 1);
        glBindVertexArray(0);
    }
    void Circle::init(){
        const std::string vertex_shader_code = 
        "#version 330 core\n"
        "uniform vec4 position;"
        "void main(){\n"
            "gl_Position=position;\n"
        "}\n";
        const std::string geometry_shader_code = 
        "#version 330 core\n"
        "layout (points) in;\n"
        "layout (triangle_strip, max_vertices=256) out;\n"
        "uniform mat4 projection;\n"
        "uniform int angle;\n"
        "uniform float radius;\n"
        "void main(){\n"
            "for(int i = 0; i < 360; i+=angle){\n"
                "gl_Position=projection*vec4(gl_in[0].gl_Position.x, gl_in[0].gl_Position.y, 0.0, 1.0);\n"
                "EmitVertex();\n"
                "gl_Position=projection*vec4(gl_in[0].gl_Position.x+cos(radians(i))*radius, gl_in[0].gl_Position.y+sin(radians(i))*radius, 0.0, 1.0);\n"
                "EmitVertex();\n"
                "gl_Position=projection*vec4(gl_in[0].gl_Position.x+cos(radians(i+angle))*radius, gl_in[0].gl_Position.y+sin(radians(i+angle))*radius, 0.0, 1.0);\n"
                "EmitVertex();\n"
                "EndPrimitive();\n"
            "}\n"
        "}\n";
        const std::string fragment_shader_code = 
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 color;\n"
        "void main(){\n"
            "FragColor=color;\n"
        "}\n";
        lb::setup_vertex_shader(shp, vertex_shader_code.c_str());
        lb::setup_geometry_shader(shp, geometry_shader_code.c_str());
        lb::setup_fragment_shader(shp, fragment_shader_code.c_str());
        lb::create_program(shp);

        glGenVertexArrays(1, &VAO);
    }
    void Circle::fina(){
        lb::destroy_vertex_shader(shp);
        lb::destroy_fragment_shader(shp);
        lb::destroy_program(shp);
        glDeleteVertexArrays(1, &VAO);
    }
}
