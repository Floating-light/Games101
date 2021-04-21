#include "Material.h"
Material::Material(EShaderType ShaderType)
{
	MyShader = Shader::GetShader(ShaderType);
	assert(MyShader);
}