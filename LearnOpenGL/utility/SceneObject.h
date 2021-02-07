#pragma once
#include <vector>
#include <glm/glm.hpp>
class RSceneObject
{
public:
	RSceneObject(std::vector<float>&& V);

	glm::mat4 GetModelTrasform();

	void Tick();

	void InputEvent(int key, int action);

	void ResetTransform();
	static RSceneObject Create3DCube();

	static void CreateVAO(RSceneObject& Obj);

private:
	std::vector<float> Vertices;
public:
	glm::vec3 Rotator;
	glm::vec3 Scale;
	glm::vec3 Translate;
	unsigned int VAO;
	unsigned int VBO;
};