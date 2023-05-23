#include "Renderer.h"

void Renderer::render(const Vertex* arr, int n_vertex) {
    //Create and bind Vertex Array Buffer
    uint32_t vao;
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //Create and buffer element buffer
    uint32_t ebo;
    glCreateBuffers(1, &ebo);
    glNamedBufferData(ebo, sizeof(Vertex) * n_vertex, NULL, GL_STATIC_DRAW);

    //Create and buffer the vertex buffer
    uint32_t vbo;
    glCreateBuffers(1, &vbo);
    glNamedBufferData(vbo, sizeof(Vertex) * n_vertex, NULL, GL_STATIC_DRAW);
    glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(Vertex));
}

void Renderer::renderStar() {

}

void Renderer::renderSquareArr() {
    Vertex vertArray[] = {
        {glm::vec3(0.4f, 0.4f, 0.0f), glm::vec4(0.9f, 0.8f, 0.2f, 1.0f)},
        {glm::vec3(0.6f, 0.4f, 0.0f), glm::vec4(0.4f, 0.9f, 0.2f, 1.0f)},
        {glm::vec3(0.6f, 0.6f, 0.0f), glm::vec4(0.6f, 0.5f, 0.2f, 1.0f)},
        {glm::vec3(0.4f, 0.6f, 0.0f), glm::vec4(0.2f, 0.8f, 0.2f, 1.0f)}
    };

    uint32_t vao;
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

    
}

void Renderer::renderSquareElem() {

}

void Renderer::renderSquareLine() {

}
