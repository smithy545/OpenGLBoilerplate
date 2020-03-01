//
// Created by Philip on 3/1/2020.
//

#ifndef WORKER_MESHUTIL_H
#define WORKER_MESHUTIL_H


#include "Mesh.h"


class MeshUtil {
public:
    static Mesh::Ptr generateSphereMesh();

    static Mesh::Ptr generateSphereMesh(double radius);

    static Mesh::Ptr generateCylinderMesh();

    static Mesh::Ptr generateCylinderMesh(double radius, double length);
};


#endif //WORKER_MESHUTIL_H
