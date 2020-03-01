//
// Created by Philip on 2/29/2020.
//

#ifndef WORKER_HUMOID_H
#define WORKER_HUMOID_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <utility>
#include <vector>

#include "MeshObject.h"


class Humoid {
public:
    Humoid();

    Humoid(glm::vec3 initialPosition);

    std::vector<MeshObject::Ptr> getBodyMeshes();
private:
    glm::vec3 position;
    std::vector<MeshObject::Ptr> bodyParts;
};


#endif //WORKER_HUMOID_H
