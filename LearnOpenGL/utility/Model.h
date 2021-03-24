#pragma once 
#include <vector>
#include <string>

#include "../Shaders/Shader.h"
#include "Mesh.h"

#include "assimp/scene.h"


class RModel
{
public:
	RModel(const std::string& path)
	{
		loadModel(path);
	}

	void Draw(Shader& shader);
private:
	// model data 
	std::vector<RMesh> meshes;

	std::string directory;

	void loadModel(const std::string& path);

	void processNode(aiNode* node, const aiScene* scene);

	RMesh processMesh(aiMesh* mesh, const aiScene* scene);

	std::vector<BTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};