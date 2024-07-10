#pragma once

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtx/string_cast.hpp>

#include "shader/shader_program.hpp"

namespace lb{
    class Line{
        public:
        glm::vec4 pos;
        glm::vec4 color;
        void draw(const glm::mat4& projection);

        static void init();
        static void fina();

        private:
        static lb::shader_program shp;
        static unsigned int VAO;
    };
}
