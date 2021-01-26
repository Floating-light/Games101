#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoord;

uniform sampler2D baseColorTexture; // 从GL_TEXTURE_2D 绑定的image 读取
uniform sampler2D anotherTex;
void main()
{
    FragColor = texture(baseColorTexture, texCoord) * vec4(vertexColor, 1.0);
}