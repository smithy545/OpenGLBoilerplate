//
// Created by Philip on 3/1/2020.
//

#include "MeshUtil.h"

#include <iostream>


Mesh::Ptr MeshUtil::generateSphereMesh() {
    return generateSphereMesh(1, 1, 3);
}

Mesh::Ptr MeshUtil::generateSphereMesh(double radius, int horizontalRings, int verticalRings) {
    Mesh::Ptr mesh = std::make_shared<Mesh>();

    float thetaStep = 3.14f / (1.0f + horizontalRings);
    float phiStep = 3.14f / (0.5f * verticalRings);

    // setup top tip
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0);

    // generate sphere verts
    for (int i = 0; i < horizontalRings; i++) {
        float theta = (i + 1) * thetaStep;
        float y = radius * glm::cos(theta);
        for (int j = 0; j < verticalRings; j++) {
            float phi = j * phiStep;
            float x = radius * glm::sin(theta) * glm::cos(phi);
            float z = radius * glm::sin(theta) * glm::sin(phi);
            mesh->vertices.push_back(x);
            mesh->vertices.push_back(y);
            mesh->vertices.push_back(z);
        }
    }

    // setup bottom tip
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(-radius);
    mesh->vertices.push_back(0);

    // connect verts with triangle faces
    int lastIndex = mesh->vertices.size() / 3 - 1;
    // connect bottom and top tips
    for (int i = 0; i < verticalRings; i++) {
        mesh->indices.push_back(0);
        mesh->indices.push_back(i + 1);
        mesh->indices.push_back((i + 1) % verticalRings + 1);

        mesh->indices.push_back(lastIndex);
        mesh->indices.push_back(lastIndex - ((i + 1) % verticalRings) - 1);
        mesh->indices.push_back(lastIndex - i - 1);
    }

    for (int i = 0; i < horizontalRings - 1; i++) {
        int index = i * verticalRings + 1;
        for (int j = 0; j < verticalRings; j++) {
            mesh->indices.push_back(index + verticalRings + j);
            mesh->indices.push_back(index + j);
            mesh->indices.push_back(index + (j + 1) % verticalRings);

            mesh->indices.push_back(index + verticalRings + (j + 1) % verticalRings);
            mesh->indices.push_back(index + verticalRings + j);
            mesh->indices.push_back(index + (j + 1) % verticalRings);
        }
    }

    // load verts/indices into mesh buffers
    mesh->reload();

    return mesh;
}
