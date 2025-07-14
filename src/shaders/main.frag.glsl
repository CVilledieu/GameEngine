#version 330 core
out vec4 FragColor;
in vec3 mainColor;
in vec2 TexCoord;
void main()
{
    FragColor = vec4(mainColor, 1.0);
}