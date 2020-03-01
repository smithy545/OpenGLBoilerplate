//
// Created by Philip on 3/1/2020.
//

#include "MeshUtil.h"

#include <iostream>


Mesh::Ptr MeshUtil::generateSphereMesh(double radius, int horizontalSteps, int verticalSteps) {
    Mesh::Ptr mesh = std::make_shared<Mesh>();

    float thetaStep = 3.14f / (1.0f + horizontalSteps);
    float phiStep = 3.14f / (0.5f * verticalSteps);

    // setup top tip
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0);

    // generate sphere verts
    for (int i = 0; i < horizontalSteps; i++) {
        float theta = (i + 1) * thetaStep;
        float y = radius * glm::cos(theta);
        for (int j = 0; j < verticalSteps; j++) {
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
    for (int i = 0; i < verticalSteps; i++) {
        int k = (i + 1) % verticalSteps;
        mesh->indices.push_back(0);
        mesh->indices.push_back(i + 1);
        mesh->indices.push_back(k + 1);

        mesh->indices.push_back(lastIndex);
        mesh->indices.push_back(lastIndex - k - 1);
        mesh->indices.push_back(lastIndex - i - 1);
    }

    for (int i = 0; i < horizontalSteps - 1; i++) {
        int index = i * verticalSteps + 1;
        for (int j = 0; j < verticalSteps; j++) {
            int k = (j + 1) % verticalSteps;
            mesh->indices.push_back(index + verticalSteps + j);
            mesh->indices.push_back(index + j);
            mesh->indices.push_back(index + k);

            mesh->indices.push_back(index + verticalSteps + k);
            mesh->indices.push_back(index + verticalSteps + j);
            mesh->indices.push_back(index + k);
        }
    }

    // load verts/indices into mesh buffers
    mesh->reload();

    return mesh;
}

Mesh::Ptr MeshUtil::generateCylinderMesh(double radius, double length, int lengthSteps, int circumferenceSteps) {
    Mesh::Ptr mesh = std::make_shared<Mesh>();

    float rStep = length / (1.0 * lengthSteps);
    float phiStep = 3.14f / (0.5f * circumferenceSteps);

    // setup top cap
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(-0.5 * length);
    mesh->vertices.push_back(0);

    // generate cylinder verts
    for (int i = 0; i <= lengthSteps; i++) {
        float r = i * rStep - 0.5 * length;
        for (int j = 0; j < circumferenceSteps; j++) {
            float phi = j * phiStep;
            float x = radius * glm::cos(phi);
            float z = radius * glm::sin(phi);
            mesh->vertices.push_back(x);
            mesh->vertices.push_back(r);
            mesh->vertices.push_back(z);
        }
    }

    // setup bottom cap
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(0.5 * length);
    mesh->vertices.push_back(0);

    // connect verts with triangle faces
    int lastIndex = mesh->vertices.size() / 3 - 1;
    // connect bottom and top tips
    for (int i = 0; i < circumferenceSteps; i++) {
        int k = (i + 1) % circumferenceSteps;
        mesh->indices.push_back(0);
        mesh->indices.push_back(i + 1);
        mesh->indices.push_back(k + 1);

        mesh->indices.push_back(lastIndex);
        mesh->indices.push_back(lastIndex - i - 1);
        mesh->indices.push_back(lastIndex - k - 1);
    }

    for (int i = 0; i < lengthSteps; i++) {
        int index = i * circumferenceSteps + 1;
        for (int j = 0; j < circumferenceSteps; j++) {
            int k = (j + 1) % circumferenceSteps;
            mesh->indices.push_back(index + j);
            mesh->indices.push_back(index + circumferenceSteps + j);
            mesh->indices.push_back(index + circumferenceSteps + k);

            mesh->indices.push_back(index + circumferenceSteps + k);
            mesh->indices.push_back(index + k);
            mesh->indices.push_back(index + j);
        }
    }

    // load verts/indices into mesh buffers
    mesh->reload();

    return mesh;
}
