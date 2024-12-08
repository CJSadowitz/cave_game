#include "Game.h"

void Game::run()
{
	glfwInit();

	GLFWwindow* window = init_window();
	init_vulkan();
	main_loop(window);
	clean_up(window);
}

GLFWwindow* Game::init_window()
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	int aspect_ratio[2] = {16, 9};
	int scale = 50;

	return glfwCreateWindow(aspect_ratio[0] * scale, aspect_ratio[1] * scale, "Cave Game", nullptr, nullptr);
}

void Game::init_vulkan()
{

}

void Game::main_loop(GLFWwindow* window)
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

void Game::clean_up(GLFWwindow* window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
