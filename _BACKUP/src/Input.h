#pragma once

#include"GLAD/glad.h"
#include"GLFW/glfw3.h"

namespace Input {
    extern bool keyPressedLast[GLFW_KEY_LAST];
    extern bool mouseButtonPressedData[GLFW_MOUSE_BUTTON_LAST];
    extern float mouseX;
    extern float mouseY;
    extern float mouseScrollX;
    extern float mouseScrollY;

    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void mouseCallback(GLFWwindow *window, double xpos, double ypos);
    void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
    void mouseScrollCallback(GLFWwindow *window, double Xoffset, double Yoffset);

    bool isKeyDown(int key);
    bool isMouseButtonDown(int mouseButton);
}