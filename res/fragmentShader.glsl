#version 430 core

out vec4 FragColor;

in vec3 pos;

void main() {
    FragColor = vec4(pos.y, 0, 1, 1.0f);
}
