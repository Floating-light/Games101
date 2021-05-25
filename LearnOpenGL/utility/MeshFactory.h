#pragma once 
#include <memory>

class RMesh;
class RMeshFactory
{
	static std::shared_ptr<RMesh> CreateMesh();
};