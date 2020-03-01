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

    float thetaStep = 3.14f / (horizontalRings + 1.0f);
    float phiStep = 3.14f / (0.5f * verticalRings);

    // setup top tip
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0);

    // connect tip to first ring
    float y = radius * glm::cos(thetaStep);
    for (int i = 0; i < verticalRings; i++) {
        float phi = i * phiStep;
        float x = radius * glm::sin(thetaStep) * glm::cos(phi);
        float z = radius * glm::sin(thetaStep) * glm::sin(phi);
        mesh->vertices.push_back(x);
        mesh->vertices.push_back(y);
        mesh->vertices.push_back(z);

        mesh->indices.push_back(0);
        mesh->indices.push_back(((i + 1) % verticalRings) + 1);
        mesh->indices.push_back(i + 1);
    }

    // setup intermediary rings
    int previousIndex = 1;
    for (int i = 1; i < horizontalRings; i++) {
        float theta = (i + 1) * thetaStep;
        float y = radius * glm::cos(theta);
        for (int j = 0; j < verticalRings; j++) {
            float phi = j * phiStep;
            float x = radius * glm::sin(theta) * glm::cos(phi);
            float z = radius * glm::sin(theta) * glm::sin(phi);
            mesh->vertices.push_back(x);
            mesh->vertices.push_back(y);
            mesh->vertices.push_back(z);

            int index = mesh->vertices.size() / 3 - 1;
            mesh->indices.push_back(index);
            mesh->indices.push_back(previousIndex);
            mesh->indices.push_back(index + 1);

            if (j == verticalRings - 1) {
                mesh->indices.push_back(index - j);
                mesh->indices.push_back(previousIndex);
                mesh->indices.push_back(previousIndex - j);
            } else {
                mesh->indices.push_back(index + 1);
                mesh->indices.push_back(previousIndex);
                mesh->indices.push_back(previousIndex + 1);
            }
            previousIndex++;
        }
    }

    // setup bottom tip
    mesh->vertices.push_back(0);
    mesh->vertices.push_back(-radius);
    mesh->vertices.push_back(0);

    // connect bottom tip to last ring
    int lastIndex = mesh->vertices.size() / 3 - 1;
    for (int i = 1; i <= verticalRings; i++) {
        mesh->indices.push_back(lastIndex);
        mesh->indices.push_back(lastIndex - i - 1);
        mesh->indices.push_back(lastIndex - i);
    }

    mesh->reload();

    return mesh;
}
