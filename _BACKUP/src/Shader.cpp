#include "Shader.h"
#include <stdio.h>

const char *vertexShaderSource = R"(
    #version 460 core
    layout (location = 0) in vec4 aColor;
    layout (location = 1) in vec3 aPosition;

    out vec4 fColor;

    void main() {
        fColor = aColor;
        gl_Position = vec4(aPosition, 1.0);
    }
)";

const char *fragmentShaderSource = R"(
    #version 460 core
    in vec4 fColor;

    out vec4 fragColor;

    void main() {
        fragColor = fColor;
    }
)";

void Shader::compile() {
    // Adapted from https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.2.hello_triangle_indexed/hello_triangle_indexed.cpp
        uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            printf_s("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n '%s'", infoLog);
        }
        // fragment shader
        uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            printf_s("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n '%s'", infoLog);
        }
        // link shaders
        progID = glCreateProgram();
        glAttachShader(progID, vertexShader);
        glAttachShader(progID, fragmentShader);
        glLinkProgram(progID);
        // check for linking errors
        glGetProgramiv(progID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(progID, 512, NULL, infoLog);
            printf_s("ERROR::SHADER::PROGRAM::LINKING_FAILED\n '%s'", infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Shader::bind()
    {
        glUseProgram(progID);
    }