#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoord;

uniform sampler2D baseColorTexture; // ��GL_TEXTURE_2D �󶨵�image ��ȡ
uniform sampler2D anotherTex;
void main()
{
    FragColor = texture(baseColorTexture, texCoord) * vec4(vertexColor, 1.0);
}