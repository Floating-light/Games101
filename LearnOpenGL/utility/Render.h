#pragma once
#include <vector>
#include <memory>
#include "utility/Camera.h"

class RSceneObject;

class RRenderer
{
public:
	void Render(std::vector<std::shared_ptr<RSceneObject>>& Objects);
	void SetCamera(std::shared_ptr<RCamera> NewCamrea);
private:
	void DepthPass();

	std::shared_ptr<RCamera> Camera;
};