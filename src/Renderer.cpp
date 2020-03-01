//
// Created by Philip on 2/29/2020.
//

#include "Renderer.h"
#include "Humoid.h"

// Include standard headers
#include <fstream>
#include <iostream>

#include <glm/glm.hpp>


using std::cerr;
using std::cout;
using std::endl;


const float Renderer::WIDTH = 1028;
const float Renderer::HEIGHT = 768;
float Renderer::mouseX = Renderer::WIDTH / 2;
float Renderer::mouseY = Renderer::HEIGHT / 2;


Renderer::Renderer() : mvpUniform(0),
                       playerCamera(glm::vec3(0, 50, 0)),
                       shaderProgram(0),
                       window(nullptr) {}

int Renderer::init() {
    // Initialise GLFW
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(WIDTH, HEIGHT, "Body Physics", nullptr, nullptr);
    if (window == nullptr) {
        cerr << "Failed to open GLFW window." << endl;
        cleanup();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initialize GLEW" << endl;
        cleanup();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // Setup mouse inputs
    glfwSetCursorPosCallback(window, cursorPosCallback);
    // Hide the mouse and enable unlimited mouvement
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set the mouse at the center of the screen
    glfwPollEvents();
    glfwSetCursorPos(window, mouseX, mouseY);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    // Create and compile our GLSL program from the shaders
    shaderProgram = loadShader("vertexShader.glsl", "fragmentShader.glsl");

    // Get a handle for our "MVP" uniform
    mvpUniform = glGetUniformLocation(shaderProgram, "MVP");

    // setup floor mesh
    int w = 50;
    int h = 50;
    cout << "Generating " << 2 * w << "x" << 2 * h << " floor mesh..." << endl;

    int i = 0;
    Mesh::Ptr floorMesh = std::make_shared<Mesh>();
    for (int z = -h; z < h; z++) {
        for (int x = -w; x < w; x++) {
            // top right
            floorMesh->vertices.push_back(x);
            floorMesh->vertices.push_back(0);
            floorMesh->vertices.push_back(z + 1);
            // bottom right
            floorMesh->vertices.push_back(x);
            floorMesh->vertices.push_back(0);
            floorMesh->vertices.push_back(z);
            // bottom left
            floorMesh->vertices.push_back(x + 1);
            floorMesh->vertices.push_back(0);
            floorMesh->vertices.push_back(z);
            // top left
            floorMesh->vertices.push_back(x + 1);
            floorMesh->vertices.push_back(0);
            floorMesh->vertices.push_back(z + 1);

            // two triangles that make a square at the given tile location
            floorMesh->indices.push_back(i / 2);
            floorMesh->indices.push_back(i / 2 + 3);
            floorMesh->indices.push_back(i / 2 + 1);
            floorMesh->indices.push_back(i / 2 + 1);
            floorMesh->indices.push_back(i / 2 + 3);
            floorMesh->indices.push_back(i / 2 + 2);
            i += 8;
        }
    }
    floorMesh->reload();
    meshesToRender.push_back(std::make_shared<MeshObject>(floorMesh));
    cout << "Floor mesh generated." << endl;

    return 0;
}

void Renderer::cleanup() {
    if(shaderProgram != 0)
        glDeleteProgram(shaderProgram);
    glfwTerminate();
}

void Renderer::run() {

    cout << "Adding jim..." << endl;
    // add humoid body mesh
    Humoid jim(glm::vec3(0, 51, -5));
    for (auto mesh: jim.getBodyMeshes())
        meshesToRender.push_back(mesh);
    cout << "Jim added." << endl;

    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(shaderProgram);

        // 45 degree field-of-view with 4/3 aspect ratio and 0.1/100 z-cutoff
        float FoV = 45.0f;
        glm::mat4 ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
        glm::mat4 ViewMatrix = playerCamera.getViewMatrix();
        glm::mat4 PV = ProjectionMatrix * ViewMatrix;

        // render meshes
        for (const auto &meshObject: meshesToRender) {
            // set mvp
            glm::mat4 MVP = PV * meshObject->model;
            glUniformMatrix4fv(mvpUniform, 1, GL_FALSE, &MVP[0][0]);

            // render mesh
            Mesh::Ptr mesh = meshObject->mesh;
            glBindVertexArray(mesh->vertexArrayId);
            glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, nullptr);
        }

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );


    // Close OpenGL window and terminate GLFW
    cleanup();
}

void Renderer::cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    mouseX = xpos;
    mouseY = Renderer::HEIGHT - ypos;
}

GLuint Renderer::loadShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    const char *vertexShaderSource = readShader(vertexShaderPath);
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        cerr << "Error on vertex compilation: " << infoLog << endl;
        return -1;
    }
    delete[] vertexShaderSource;

    // fragment shader
    const char *fragmentShaderSource = readShader(fragmentShaderPath);
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        cerr << "Error on fragment compilation: " << infoLog << endl;
        return -1;
    }
    delete[] fragmentShaderSource;

    // compile shader program
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        cerr << "Error linking program: " << infoLog << endl;
        return -1;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

char* Renderer::readShader(const std::string& path) {
    std::ifstream shaderStream("../res/" + path, std::ifstream::ate);
    if(shaderStream) {
        // get file length (ifstream::ate flag puts cursor at end of file)
        int shaderLength = shaderStream.tellg();
        shaderStream.seekg(0, std::ios_base::beg);

        // store in buffer
        char* shaderBuffer = new char[shaderLength];
        int count = 0;
        while(shaderStream.read(shaderBuffer + count, shaderLength - count) || shaderStream.gcount() != 0) {
            count += shaderStream.gcount();
        }
        shaderStream.close();

        // null terminate because C++ fucking sucks
        shaderBuffer[count] = '\0';

        return shaderBuffer;
    }

    // open failed for some reason
    std::cout << "Error opening shader at res/" << path << std::endl;
    return nullptr;
}