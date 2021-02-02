#pragma once
#include <string>
#include <map>

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

#include "../Shaders/Shader.h"


struct Character
{
	unsigned int TextureID;
	glm::ivec2 Size;
	glm::ivec2 Bearing;
	unsigned int Advance;
};

class TextRender
{
public:
	TextRender(const std::string& fontPath, const glm::vec3& c);
	
	~TextRender();

	void Initialize(const std::string& fontPath, const glm::vec3& c);

	void RenderText(const std::string& text, float x, float y, float scale);

	void SetTextColor(const glm::vec3& c) { Color = c; }

	void SetFonts(const std::string& fontPath);

private:
	void InitDraw();

private:

	std::map<char, Character> Characters;

	Shader* MyTextShader;

	unsigned int VAO;

	unsigned int VBO;

	glm::vec3 Color;
};