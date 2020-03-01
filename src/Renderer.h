//
// Created by Philip on 2/29/2020.
//

#ifndef WORKER_RENDERER_H
#define WORKER_RENDERER_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

#include "BodyModel.h"
#include "Camera.h"
#include "Mesh.h"


class Renderer {
public:
    static const float WIDTH;
    static const float HEIGHT;

    Renderer();

    int init();
    void run();
    void cleanup();
private:
    std::vector<Mesh::Ptr> meshesToRender;
    Camera playerCamera;
    GLuint shaderProgram;
    GLuint mvpUniform;
    GLFWwindow* window;

    static float mouseX;
    static float mouseY;

    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
    static GLuint loadShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    static char* readShader(const std::string& shaderPath);
};


#endif //WORKER_RENDERER_H
