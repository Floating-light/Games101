#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "utility/Render.h"
#include "utility/SceneObject.h"
#include "Shaders/Shader.h"
#include "utility/Model.h"
#include "utility/Camera.h"
namespace R
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}

int FALSEmain()
{
	// Init glfw
	glfwInit();
	// Specify gl version 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Gl api version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a display window 
	GLFWwindow* window = glfwCreateWindow(800, 600, "RealEngine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate(); // 
		return -1;
	}
	// make a opengl context from previous created window
	glfwMakeContextCurrent(window);

	// load all opengl function by use the function provided by glfw via glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 隐藏鼠标指针
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// 设置指定window 的framebuffer size 的callback.
	glfwSetFramebufferSizeCallback(window, R::framebuffer_size_callback);
	//glfwSetKeyCallback(window, key_callback);
	//glfwSetCursorPosCallback(window, mouse_callback);
	//glfwSetScrollCallback(window, mouse_scroll_callback);

	glViewport(0, 0, 800, 600);

	std::vector<std::shared_ptr<RSceneObject>> SceneObjects;
	// Setup scene 
	{
		std::shared_ptr<RModel> marryModel = std::make_shared<RModel>("./resources/objects/mary/Marry.obj", EShaderType::ShaderMarry);
		std::shared_ptr<RSceneObject> obj1 = std::make_shared<RSceneObject>(marryModel);

		SceneObjects.push_back(obj1);
	}

	RCamera Camera;

	RRenderer render;
	while (!glfwWindowShouldClose(window))
	{
		//peocessInput(SceneObjects);
		glViewport(0, 0, 800, 600);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		render.Render(SceneObjects);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}