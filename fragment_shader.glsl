#version 460 core

out vec4 fragColor;
uniform vec3 color; // Allow dynamic color setting

void main() {
    fragColor = vec4(color, 1.0);
}