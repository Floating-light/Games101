#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "CoreType.h"
#include "Mesh.h"

template< typename T>
class RMaterialParameterValue
{
public:
    std::string ParameterName;
    T ParameterValue;
};

using RScalarParameterValue = RMaterialParameterValue<float>;
using RVectorParameterValue = RMaterialParameterValue<Vector3D>;
using RTextureParameterValue = RMaterialParameterValue<BTexture*>;

class Shader;

class Material
{
public:
    Material();
    Material(const std::shared_ptr<Shader>& MyShader);
    void Use();
private:
    std::vector<RScalarParameterValue> ScalarParameters;
    std::vector<RVectorParameterValue> VectorParameters;
    std::vector<RTextureParameterValue> TextureParameters;
    std::shared_ptr<Shader> MyShader;
};

