#pragma once
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

struct Shader {
    uint32_t progID;

    void bind();
    void compile();
};