//
// Created by Philip on 3/1/2020.
//

#ifndef WORKER_TERRAINMAP_H
#define WORKER_TERRAINMAP_H

#include "Mesh.h"


class TerrainMap {
public:
    TerrainMap(int width, int height);

    Mesh::Ptr getMesh();

private:
    int width;
    int height;
    Mesh::Ptr terrainMesh;

    double getHeight(double x, double y);
};


#endif //WORKER_TERRAINMAP_H
