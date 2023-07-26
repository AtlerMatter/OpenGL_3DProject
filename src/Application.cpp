#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"


const int windowWidth = 1280;
const int windowHeight = 720;
const char *windowTitle = "OpenGL WIP Voxel Game";


int main(){

    if (!glfwInit()) {
        printf("Failed to initialize GLFW.");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    //glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

    { //Scope to make everything inside be heap allocated and destroyed before ending de OpenGL context
        float vertices[] = {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            -0.5f, 0.5f,
            0.5f, 0.5f
        };

        unsigned int indices[] = {
            0, 1, 2,
            1, 3, 2
        };

        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        VertexArray va;
        VertexBuffer vb(vertices, 4 * 2 * sizeof(float));
        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        Shader shader("res/shaders/basic.glsl");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        va.Unbind();
        shader.Unbind();
        vb.Unbind();
        ib.Unbind();

        float r = 0.0f;
        float slew = 0.05f;
        //glViewport(0, 0, windowWidth, windowHeight);
        while (!glfwWindowShouldClose(window)) {

            glClear(GL_COLOR_BUFFER_BIT);
            //glClearColor(r, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);

            shader.Bind();
            shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
            
            va.Bind();
            ib.Bind();
            
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            r += slew;
            if (r > 1.0f) {
                slew = -0.05f;
            }
            else if (r < 0.0f) {
                slew = 0.05f;
            }
            
            

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}