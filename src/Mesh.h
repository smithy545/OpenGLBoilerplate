//
// Created by Philip on 3/1/2020.
//

#ifndef WORKER_MESH_H
#define WORKER_MESH_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <memory>
#include <vector>


class Mesh {
public:
    typedef std::shared_ptr<Mesh> Ptr;

    std::vector<float> vertices;
    std::vector<int> indices;

    GLuint vertexArrayId;
    GLuint vertexBufferId;
    GLuint elementBufferId;

    Mesh() {
        glGenVertexArrays(1, &vertexArrayId);
        glBindVertexArray(vertexArrayId);
        glEnableVertexAttribArray(0);

        // setup verts to be first attribute with 3 components
        glGenBuffers(1, &vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
        glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
        );

        // gen and bind index buffer
        glGenBuffers(1, &elementBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferId);
    }

    ~Mesh() {
        // optional: de-allocate all resources once they've outlived their purpose:
        // ------------------------------------------------------------------------
        if (vertexArrayId != 0)
            glDeleteVertexArrays(1, &vertexArrayId);
        if (vertexBufferId != 0)
            glDeleteBuffers(1, &vertexBufferId);
        if (elementBufferId != 0)
            glDeleteBuffers(1, &elementBufferId);
    }

    void reload() {
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(int), &indices[0], GL_STATIC_DRAW);
    }
};

#endif //WORKER_MESH_H
