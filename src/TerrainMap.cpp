//
// Created by Philip on 3/1/2020.
//

#include "TerrainMap.h"

TerrainMap::TerrainMap(int width, int height) : height(height), terrainMesh(nullptr), width(width) {
    terrainMesh = std::make_shared<Mesh>();
    int i = 0;
    for (int z = 0; z < height; z++) {
        for (int x = 0; x < width; x++) {
            double cx = x - 0.5 * width;
            double cz = z - 0.5 * height;
            // top right
            terrainMesh->vertices.push_back(cx);
            terrainMesh->vertices.push_back(getHeight(cx, cz + 1));
            terrainMesh->vertices.push_back(cz + 1);
            // bottom right
            terrainMesh->vertices.push_back(cx);
            terrainMesh->vertices.push_back(getHeight(cx, cz));
            terrainMesh->vertices.push_back(cz);
            // bottom left
            terrainMesh->vertices.push_back(cx + 1);
            terrainMesh->vertices.push_back(getHeight(cx + 1, cz));
            terrainMesh->vertices.push_back(cz);
            // top left
            terrainMesh->vertices.push_back(cx + 1);
            terrainMesh->vertices.push_back(getHeight(cx + 1, cz + 1));
            terrainMesh->vertices.push_back(cz + 1);

            // two triangles that make a square at the given tile location
            terrainMesh->indices.push_back(i);
            terrainMesh->indices.push_back(i + 3);
            terrainMesh->indices.push_back(i + 1);
            terrainMesh->indices.push_back(i + 1);
            terrainMesh->indices.push_back(i + 3);
            terrainMesh->indices.push_back(i + 2);
            i += 4;
        }
    }
    terrainMesh->reload();
}

double TerrainMap::getHeight(double x, double y) {
    return 0;
}

Mesh::Ptr TerrainMap::getMesh() {
    return terrainMesh;
}
