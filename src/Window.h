#pragma once

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"


struct Window {


    GLFWwindow *nativeWindow;
    int windowWidth, windowHeight;

    //Window();
    //~Window();
    void setupMainCallbacks();
    void close();
    static Window *createWindow(int width, int height, const char* title, bool fullScreen=false);
    static void freeWindow(Window *window);
};