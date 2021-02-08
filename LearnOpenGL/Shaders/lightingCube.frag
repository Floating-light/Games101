#version 330 core

in vec2 TexCoord;
in vec3 fragCoord;
in vec3 Normal;
uniform sampler2D Texture1;
uniform sampler2D Texture2;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform float ambientStrength;
uniform vec3 lightPos;
uniform vec3 eyePos;

out vec4 outColor;
void main()
{
	float specularStrength = 0.5;
	float p = 128.0f;
	vec3 ambient = lightColor* ambientStrength;

	vec3 diffuse = lightColor * max(dot(normalize(lightPos - fragCoord) , normalize(Normal)), 0);

	vec3 specular = lightColor * specularStrength * pow(max(dot(normalize(normalize(lightPos - fragCoord) + normalize(eyePos - fragCoord)), normalize(Normal)), 0), p);

	vec3 result = (diffuse + ambient + specular) * objectColor;


	outColor = vec4(result, 1.0);
}