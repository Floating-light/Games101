#pragma once 
#include "CoreType.h"
#include <string>
#include <vector>

#include "../Shaders/Shader.h"

struct BVertex
{
	Vector3D Position;
	Vector3D Normal;
	Vector2D TexCoords;
};

struct BTexture
{
	unsigned int id;
	std::string type;
	std::string path; // store path of texture to compare with other textures
};

extern std::vector<BTexture> textures_loaded;

class RMesh
{
public:
	std::vector<BVertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<BTexture> textures;

	// constructor 
	RMesh(std::vector<BVertex> vertices, std::vector<unsigned int> indices, std::vector<BTexture> textures);

	// Draw this mesh
	void Draw(Shader& shader);

private:
	// render data
	unsigned int VAO, VBO, EBO;

	void SetupMesh();

};