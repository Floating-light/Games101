#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "utility/CoreType.h"

#include "Shaders/Shader.h"

template< typename T>
class RMaterialParameterValue
{
public:
    std::string ParameterName;
    T ParameterValue;
};
class BTexture;

using RScalarParameterValue = RMaterialParameterValue<float>;
using RVectorParameterValue = RMaterialParameterValue<Vector3D>;
using RTextureParameterValue = RMaterialParameterValue<BTexture*>;

class Material
{
public:
    Material();
    Material(EShaderType ShaderType);
    void setScalarParameter(const std::string& paramName, float value);
    void setVectorParameterValue(const std::string& paramName, Vector3D value);
    void setTextureParameterValue(const std::string& paramName, BTexture* value);

private:
    std::shared_ptr<class Shader> MyShader;
    std::vector<RScalarParameterValue> ScalarParam;
    std::vector<RVectorParameterValue> VecParam;
    std::vector<RTextureParameterValue> TexParam;
};

