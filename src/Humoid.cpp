//
// Created by Philip on 2/29/2020.
//

#include "Humoid.h"

#include "MeshUtil.h"


Humoid::Humoid() : Humoid(glm::vec3(0, 0, 0)) {}

Humoid::Humoid(glm::vec3 initialPosition) : position(initialPosition) {

    // head
    glm::mat4 headModel = glm::translate(glm::mat4(1), position);
    MeshObject::Ptr obj = std::make_shared<MeshObject>(MeshUtil::generateSphereMesh(0.3, 31, 32), headModel);
    bodyParts.push_back(obj);

    // body
    glm::mat4 bodyModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(0, -1.4, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(MeshUtil::generateCylinderMesh(0.4, 2, 10, 10), bodyModel));

    // arms
    Mesh::Ptr armMesh = MeshUtil::generateCylinderMesh(0.1, 1.5, 10, 10);
    glm::mat4 leftArmModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(0.6, -1.2, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(armMesh, leftArmModel));
    glm::mat4 rightArmModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(-0.6, -1.2, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(armMesh, rightArmModel));

    // legs
    Mesh::Ptr legMesh = MeshUtil::generateCylinderMesh(0.2, 2.0, 10, 10);
    glm::mat4 leftLegModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(0.5, -3, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(legMesh, leftLegModel));
    glm::mat4 rightLegModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(-0.5, -3, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(legMesh, rightLegModel));
}

std::vector<MeshObject::Ptr> Humoid::getBodyMeshes() {
    return bodyParts;
}
