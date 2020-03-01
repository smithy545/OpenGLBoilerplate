//
// Created by Philip on 2/29/2020.
//

#include "Camera.h"

Camera::Camera(glm::vec3 initialPosition): Camera(initialPosition, glm::vec3(0, 0, -1), glm::vec3(1, 0, 0)) {}

Camera::Camera(glm::vec3 initialPosition, glm::vec3 initialDirection, glm::vec3 initialRight)
: direction(initialDirection), position(initialPosition), right(initialRight) {}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + direction, glm::cross(right, direction));
}

void Camera::rotate(double radians) {
    horizontalAngle += radians;
    direction = glm::vec3(
            glm::sin(horizontalAngle),
            0,
            glm::cos(horizontalAngle)
            );
    right = glm::vec3(
            glm::sin(horizontalAngle - 3.14f/2.0f),
            0,
            glm::cos(horizontalAngle - 3.14f/2.0f)
            );
}