#include "Window.h"
#include <stdio.h>
#include "Input.h"

void Window::setupMainCallbacks() {
    if (nativeWindow != nullptr) {
        glfwSetCursorPosCallback(nativeWindow, Input::mouseCallback);
        glfwSetMouseButtonCallback(nativeWindow, Input::mouseButtonCallback);
        glfwSetKeyCallback(nativeWindow, Input::keyCallback);
        glfwSetScrollCallback(nativeWindow, Input::mouseScrollCallback);
    }
}

void Window::close() {
    if (nativeWindow != nullptr) {
        glfwSetWindowShouldClose(nativeWindow, 1);
    }
}

Window *Window::createWindow(int width, int height, const char* title, bool fullScreen) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window *window = new Window();
    GLFWmonitor *primaryMonitor = fullScreen ? glfwGetPrimaryMonitor() : nullptr;
    window->nativeWindow = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);

    if (window->nativeWindow == nullptr) {
        printf_s("Failed to create GLFW Window\n");
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window->nativeWindow);
    return window;
}

void Window::freeWindow(Window *window) {
    if (window) {
        glfwDestroyWindow(window->nativeWindow);
        delete window;
    }
    
}