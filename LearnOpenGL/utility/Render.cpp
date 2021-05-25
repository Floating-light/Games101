#include "Render.h"
#include "SceneObject.h"
#include "Model.h"
void RRenderer::Render(std::vector<std::shared_ptr<RSceneObject>>& Objects)
{
	for(auto Obj : Objects)
	{
		Obj->GetModelTrasform();
		Obj->Model->Draw();
	}
}
