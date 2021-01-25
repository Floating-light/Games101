#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
	// the program ID
	unsigned int ID;

	// constructor reads and builds the shader
	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	// use/activate the shader
	void use();

	// utility uniform functions
	void setBool(const std::string& name, bool value) const;

	void setInteger(const std::string& name, int value) const;

	void setFloat(const std::string& name, float value) const;

	void setVec4(const std::string& name, float x, float y, float z, float w);
};

