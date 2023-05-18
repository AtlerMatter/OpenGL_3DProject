#pragma once
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

struct Vertex {
    glm::vec3 pos;
    glm::vec4 color;
};


class Renderer {

    void render(const Vertex* arr, int n_vertex);
    void renderStar();
    void renderSquareArr();
    void renderSquareElem();
    void renderSquareLine();

};
