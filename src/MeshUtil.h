//
// Created by Philip on 3/1/2020.
//

#ifndef WORKER_MESHUTIL_H
#define WORKER_MESHUTIL_H

#include <glm/glm.hpp>

#include "Mesh.h"


class MeshUtil {
public:
    static const int MAX_HORIZONTAL_RINGS = 100;
    static const int MAX_VERTICAL_RINGS = 100;

    static Mesh::Ptr generateSphereMesh();

    static Mesh::Ptr generateSphereMesh(double radius, int horizontalRings, int verticalRings);

};


#endif //WORKER_MESHUTIL_H
