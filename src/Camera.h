//
// Created by Philip on 2/29/2020.
//

#ifndef WORKER_CAMERA_H
#define WORKER_CAMERA_H

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera {
public:
    explicit Camera(glm::vec3 initialPosition);
    Camera(glm::vec3 initialPosition, glm::vec3 initialDirection, glm::vec3 initialRight);

    glm::mat4 getViewMatrix();
    void rotate(double radians);
private:
    glm::vec3 direction;
    glm::vec3 position;
    glm::vec3 right;
    float horizontalAngle{0.0f};
};


#endif //WORKER_CAMERA_H
