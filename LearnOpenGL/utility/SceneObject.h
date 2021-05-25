#pragma once
#include <vector>
#include <memory>

#include <glm/glm.hpp>

class RModel;

class RSceneObject
{
public:
	RSceneObject(std::vector<float>&& V);

	glm::mat4 GetModelTrasform();

	virtual void Tick();

	virtual void InputEvent(int key, int action);

	void ResetTransform();
	static RSceneObject Create3DCube();

	static void CreateVAO(RSceneObject& Obj);

	std::vector<float> Vertices;
	std::shared_ptr<RModel> Model;
public:
	glm::vec3 Rotator;
	glm::vec3 Scale;
	glm::vec3 Translate;
	unsigned int VAO;
	unsigned int VBO;
};