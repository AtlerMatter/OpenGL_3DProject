#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

#include "Window.h"
#include "Input.h"

const int windowWidth = 1920;
const int windowHeight = 1080;
const char *windowTitle = "OpenGL WIP Voxel Game";

int exitWithError(const char* msg) {
    printf_s(msg);
    glfwTerminate();
    return -1;
}

int main(){
    glfwInit();

    if (!glfwInit()) {
        printf("Failed to initialize GLFW.");
        return -1;
    }

    Window *window = Window::createWindow(windowWidth, windowHeight, windowTitle);

    if (window == nullptr) {
        return exitWithError("Failed to create GLFW window\n");
    }

    window->setupMainCallbacks();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return exitWithError("Failed to initialize GLAD");
    }

    glViewport(0, 0, windowWidth, windowHeight);
    while (!glfwWindowShouldClose(window->nativeWindow)) {

        glClearColor(250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window->nativeWindow);
        glfwPollEvents();
    }

    Window::freeWindow(window);
    glfwTerminate();
    return 0;
}