//
// Created by Philip on 3/1/2020.
//

#ifndef WORKER_MESHOBJECT_H
#define WORKER_MESHOBJECT_H

#include <glm/glm.hpp>
#include <memory>
#include <utility>

#include "Mesh.h"


class MeshObject {
public:
    typedef std::shared_ptr<MeshObject> Ptr;

    Mesh::Ptr mesh;
    glm::mat4 model;

    explicit MeshObject(Mesh::Ptr mesh) : mesh(std::move(mesh)), model(1) {}

    MeshObject(Mesh::Ptr mesh, glm::mat4 model) : mesh(std::move(mesh)), model(model) {}
};


#endif //WORKER_MESHOBJECT_H
