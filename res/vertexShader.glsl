#version 430 core

layout (location = 0) in vec3 aPos;

uniform mat4 MVP;

out vec3 pos;

void main() {
    gl_Position = MVP * vec4(aPos, 1.0);
    pos = gl_Position.xyz;
}
