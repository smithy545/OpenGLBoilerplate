//
// Created by Philip on 3/1/2020.
//

#include "MeshUtil.h"


Mesh::Ptr MeshUtil::generateSphereMesh() {
    return generateSphereMesh(1.0);
}

Mesh::Ptr MeshUtil::generateSphereMesh(double radius) {
    Mesh::Ptr mesh = std::make_shared<Mesh>();

    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(0.0f);

    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(0.0f);

    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0.0f);

    mesh->indices.push_back(0);
    mesh->indices.push_back(1);
    mesh->indices.push_back(2);

    mesh->reload();

    return mesh;
}

Mesh::Ptr MeshUtil::generateCylinderMesh() {
    return generateCylinderMesh(1.0, 1.0);
}

Mesh::Ptr MeshUtil::generateCylinderMesh(double radius, double length) {
    Mesh::Ptr mesh = std::make_shared<Mesh>();

    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(0.0f);

    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(0.0f);

    mesh->vertices.push_back(0.0f);
    mesh->vertices.push_back(radius);
    mesh->vertices.push_back(0.0f);

    mesh->indices.push_back(0);
    mesh->indices.push_back(1);
    mesh->indices.push_back(2);

    mesh->reload();

    return mesh;
}