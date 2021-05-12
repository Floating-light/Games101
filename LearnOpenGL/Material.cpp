#include "Material.h"
Material::Material(EShaderType ShaderType)
{
	MyShader = Shader::GetShader(ShaderType);
	assert(MyShader);
}

void Material::setScalarParameter(const std::string& paramName, float value)
{

}
void Material::setVectorParameterValue(const std::string& paramName, Vector3D value)
{

}
void Material::setTextureParameterValue(const std::string& paramName, BTexture* value)
{

}