#include "Render.h"
#include "SceneObject.h"
#include "Model.h"
#include <iostream>
void RRenderer::Render(std::vector<std::shared_ptr<RSceneObject>>& Objects)
{
	for(auto Obj : Objects)
	{
		Obj->GetModelTrasform();
		for (auto& mesh : Obj->Model->meshes)
		{
			
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
