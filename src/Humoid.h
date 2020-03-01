//
// Created by Philip on 2/29/2020.
//

#ifndef WORKER_HUMOID_H
#define WORKER_HUMOID_H

#include <glm/glm.hpp>
#include <utility>
#include <vector>

#include "Mesh.h"


class Humoid {
public:
    Humoid();

    Humoid(glm::vec3 initialPosition);

private:
    glm::vec3 position;
    std::vector<glm::vec3> joints;
    std::vector<std::pair<int, int>> bones;
};


#endif //WORKER_HUMOID_H
