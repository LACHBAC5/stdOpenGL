#pragma once
#include <iostream>
#include <string>
#include "shader/shader_program.hpp"

namespace lb{
    class Circle{
        public:
        float r; int pos[2];
        int seg_angle;
        void draw(const glm::mat4& projection);

        static void init();
        static void fina();

        private:
        static lb::shader_program shp;
        static unsigned int VAO;
    };
}
