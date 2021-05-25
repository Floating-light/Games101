#pragma once
#include <vector>
#include <memory>
class RSceneObject;

class RRenderer
{
public:
	void Render(std::vector<std::shared_ptr<RSceneObject>>& Objects);
};