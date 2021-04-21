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

using RScalarParameterValue = RMaterialParameterValue<float>;
using RVectorParameterValue = RMaterialParameterValue<Vector3D>;
using RTextureParameterValue = RMaterialParameterValue<BTexture*>;

class Material
{
public:
    Material();
    Material(EShaderType ShaderType);

private:

    std::shared_ptr<class Shader> MyShader;
};

