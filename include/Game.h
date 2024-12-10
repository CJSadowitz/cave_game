#ifndef GAME_H
#define GAME_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class Game
{
public:
	void run();
private:
	GLFWwindow* init_window();
	void init_vulkan();
	void main_loop(GLFWwindow* window);
	void clean_up(GLFWwindow* window);

	VkInstance instance;
	void create_instance();
	void pick_physical_device();
};

#endif
