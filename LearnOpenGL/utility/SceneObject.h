#pragma once
#include <vector>
#include <memory>

#include <glm/glm.hpp>

class RModel;

class RSceneObject
{
public:
	RSceneObject() 
		: Rotator(0.0f, 0.0f, 0.0f)
		, Scale(1.0f, 1.0f, 1.0f)
		, Translate(0.0f, 0.0f,3.0f)
	{

	}
	RSceneObject(std::vector<float>&& V);
	RSceneObject(std::shared_ptr<RModel> NewModel)
	{
		SetModel(NewModel);
	}
	virtual void Tick(float DeltaTime);

	virtual void InputEvent(int key, int action);

	glm::mat4 GetModelTrasform();
	void ResetTransform();

	void SetModel(std::shared_ptr<RModel> NewModel);

	static RSceneObject Create3DCube();

	static void CreateVAO(RSceneObject& Obj);

	std::vector<float> Vertices;
	std::shared_ptr<RModel> Model;
public:
	glm::vec3 Rotator;
	glm::vec3 Scale;
	glm::vec3 Translate;

	// Deprected
	unsigned int VAO;
	unsigned int VBO;
};