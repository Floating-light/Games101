#include "Material.h"
#include <glad/glad.h>

#include <iostream>

Material::Material(const std::shared_ptr<Shader>& InShader)
{

}

void Material::Use()
{
	if (!MyShader)
	{
		std::cout << "ERROR: Shader is nullptr, " << __FUNCTION__ << std::endl;
		return;
	}

	MyShader->use();

	for (auto& ScaleParam : ScalarParameters)
	{
		MyShader->setFloat(ScaleParam.ParameterName, ScaleParam.ParameterValue);
	}

	for (auto& VecParam : VectorParameters)
	{
		MyShader->setVec3(VecParam.ParameterName, VecParam.ParameterValue);
	}

	for (size_t i = 0; i < TextureParameters.size(); ++i)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, TextureParameters[i].ParameterValue->id);
		MyShader->setInteger(TextureParameters[i].ParameterName, i);
	}
		
}
