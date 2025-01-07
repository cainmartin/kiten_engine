#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uUvs;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 fragNormal;

void main() {
    mat3 normalMatrix = mat3(transpose(inverse(model)));
    fragNormal = normalize(normalMatrix * normal);

    // projection * view * model *
    gl_Position = projection * view * model * vec4(position, 1.0);
}