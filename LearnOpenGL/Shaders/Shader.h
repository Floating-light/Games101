#pragma once


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "glm/glm.hpp"

class Shader
{
public:
	// the program ID
	unsigned int ID;

	// constructor reads and builds the shader
	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	~Shader();

	// use/activate the shader
	void use();

	// utility uniform functions
	void setBool(const std::string& name, bool value) const;

	void setInteger(const std::string& name, int value) const;

	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, const glm::vec3& value);
	void setVec4(const std::string& name, float x, float y, float z, float w);
	void setMat4(const std::string& name, const glm::mat4& ptr);
};

