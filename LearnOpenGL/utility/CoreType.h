#pragma once
#include <functional>

#include "glm/glm.hpp"

struct GLFWwindow;

using Vector3D = glm::vec3;
using Vector2D = glm::vec2;
using Matrix4 = glm::mat4;

// Called when Pressed or Release some key
using KeyEventCallback = std::function<void(int, int)>;
// Called every frame to test if some key is pressed
using KeyProcess = std::function<void(GLFWwindow*, float Rate)>;

using MouseCursorMoveCallBack = std::function<void(double, double)>;

using MouseScrollCallBack = std::function<void(double, double)>;