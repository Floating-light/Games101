#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "utility/CoreType.h"
#include "utility/Mesh.h"
#include "Shaders/Shader.h"



template< typename T>
class RMaterialParameterValue
{
public:
    std::string ParameterName;
    T ParameterValue;
};
struct BTexture;

using RScalarParameterValue = RMaterialParameterValue<float>;
using RVectorParameterValue = RMaterialParameterValue<Vector3D>;
using RTextureParameterValue = RMaterialParameterValue<BTexture>;

class Shader;

class Material
{
public:
    Material() {};
    Material(EShaderType ShaderType, const std::vector<BTexture>& InTexParam = {});
    void Use();

    void setOrAddScalarParameter(const std::string& paramName, float value);
    void setOrAddVectorParameterValue(const std::string& paramName, Vector3D value);
    void setOrAddTextureParameterValue(const std::string& paramName, BTexture value);

    //void addTextureParameter(const std::string& paramName, BTexture* value);
private:
    void initTextureParams(const std::vector<BTexture>& InTexture);
private:
    std::vector<RScalarParameterValue> ScalarParameters;
    std::vector<RVectorParameterValue> VectorParameters;
    std::vector<RTextureParameterValue> TextureParameters;
    std::shared_ptr<Shader> MyShader;
};

