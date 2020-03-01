//
// Created by Philip on 2/29/2020.
//

#include "Humoid.h"

#include "MeshUtil.h"


Humoid::Humoid() : Humoid(glm::vec3(0, 0, 0)) {}

Humoid::Humoid(glm::vec3 initialPosition) : position(initialPosition) {
    // head
    glm::mat4 headModel = glm::translate(glm::mat4(1), position);
    MeshObject::Ptr obj = std::make_shared<MeshObject>(MeshUtil::generateSphereMesh(1, 7, 8), headModel);
    bodyParts.push_back(obj);

    /*
    // arms
    Mesh::Ptr armMesh = MeshUtil::generateCylinderMesh();

    glm::mat4 leftArmModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(1, -1, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(armMesh, leftArmModel));

    glm::mat4 rightArmModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(-1, -1, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(armMesh, rightArmModel));

    // legs
    Mesh::Ptr legMesh = MeshUtil::generateCylinderMesh();

    glm::mat4 leftLegModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(1, -2, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(legMesh, leftLegModel));

    glm::mat4 rightLegModel = glm::translate(glm::mat4(1), initialPosition + glm::vec3(-1, -2, 0));
    bodyParts.push_back(std::make_shared<MeshObject>(legMesh, rightLegModel));
     */
}

std::vector<MeshObject::Ptr> Humoid::getBodyMeshes() {
    return bodyParts;
}
