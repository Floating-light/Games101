#include "Render.h"
#include "SceneObject.h"
#include "Model.h"
#include "utility/LightObject.h"
#include "utility/Camera.h"

#include <iostream>
void RRenderer::Render(std::vector<std::shared_ptr<RSceneObject>>& Objects)
{
	for(auto Obj : Objects)
	{
		Obj->GetModelTrasform();
		for (auto& mesh : Obj->Model->meshes)
		{
			auto MaterialPtr = mesh.GetMaterial();
			MaterialPtr->setOrAddVectorParameterValue("eyePos", Camera->Location);
			MaterialPtr->setOrAddScalarParameter("emissionV", 2);

			MaterialPtr->setOrAddMatrix4ParameterValue("model", Obj->GetModelTrasform());
			MaterialPtr->setOrAddMatrix4ParameterValue("view", Camera->GetViewTransform());
			MaterialPtr->setOrAddMatrix4ParameterValue("projection", Camera->GetPerspective());

			//MaterialPtr->setOrAddVectorParameterValue("InColor", Vector3D(0.828, 0.364, 0.0));
			MaterialPtr->setOrAddVectorParameterValue("pointlight.position", Light->GetWorldLocation());
			MaterialPtr->setOrAddVectorParameterValue("pointlight.ambient", glm::vec3(1.0f, 1.0f, 1.0f));
			MaterialPtr->setOrAddVectorParameterValue("pointlight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
			MaterialPtr->setOrAddVectorParameterValue("pointlight.specular", glm::vec3(0.0f, 0.0f, 0.0f));
			MaterialPtr->setOrAddScalarParameter("pointlight.constant", 1.0f);
			MaterialPtr->setOrAddScalarParameter("pointlight.linear", 0.09f);
			MaterialPtr->setOrAddScalarParameter("pointlight.quadratic", 0.032f);

			mesh.Draw(MaterialPtr);
		}
	}
}

void RRenderer::DepthPass()
{

}


void RRenderer::SetCamera(std::shared_ptr<RCamera> NewCamrea)
{
	Camera = NewCamrea;
}
void RRenderer::SetLight(std::shared_ptr < RLightObject> NewLight)
{
	Light = NewLight;
}



