#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

const float amplitude = 1.0;
const float frequency = 0.05;
const float PI = 3.14159;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

void main()
{
    float xOffset = amplitude * sin(4.0 * PI * frequency * time);
    float zOffset = amplitude * sin(8.0 * PI * frequency * time);
    
    gl_Position = projection * view * model * vec4(aPos.x + xOffset, aPos.y, aPos.z + zOffset, 1); 
    TexCoords = vec2(aTexCoords.x, aTexCoords.y);
}