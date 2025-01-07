#version 330 core

in vec3 fragNormal;
out vec4 FragColor;

float inverseLerp(float v, float minValue, float maxValue) {
  return (v - minValue) / (maxValue - minValue);
}

float remap(float v, float inMin, float inMax, float outMin, float outMax) {
  float t = inverseLerp(v, inMin, inMax);
  return mix(outMin, outMax, t);
}

void main() {
    vec3 normal = normalize(fragNormal);

    FragColor = vec4(normal * 0.5 + 0.5, 1.0);
}