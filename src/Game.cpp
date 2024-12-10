#include "Game.h"
#include "Chunk.h"
#include <stdexcept>
#include <vector>

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
	create_instance();
	pick_physical_device();
}

void Game::create_instance()
{
	VkApplicationInfo app_info{};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = "Hello Triangle";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "No Engine";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo create_info{};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pApplicationInfo = &app_info;

	uint32_t glfw_extension_count = 0;
	const char** glfw_extensions;

	glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	create_info.enabledExtensionCount = glfw_extension_count;
	create_info.ppEnabledExtensionNames = glfw_extensions;

	create_info.enabledLayerCount = 0;

	VkResult result = vkCreateInstance(&create_info, nullptr, &this->instance);

	if (vkCreateInstance(&create_info, nullptr, &this->instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create instance!");
	}
}

bool is_device_suitable(VkPhysicalDevice device)
{
	VkPhysicalDeviceProperties device_properties;
	vkGetPhysicalDeviceProperties(device, &device_properties);

	VkPhysicalDeviceFeatures device_features;
	vkGetPhysicalDeviceFeatures(device, &device_features);
	return device_properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU && device_features.geometryShader;
}

void Game::pick_physical_device()
{
	VkPhysicalDevice physical_device = VK_NULL_HANDLE;
	uint32_t device_count = 0;
	vkEnumeratePhysicalDevices(this->instance, &device_count, nullptr);

	if (device_count == 0)
	{
		throw std::runtime_error("Failed to find GPUs with vulkan support");
	}

	std::vector<VkPhysicalDevice> devices(device_count);
	vkEnumeratePhysicalDevices(this->instance, &device_count, devices.data());
	for (const auto& device : devices)
	{
		if (is_device_suitable(device))
		{
			break;
		}
	}
	if (physical_device == VK_NULL_HANDLE)
	{
		throw std::runtime_error("Failed to find a suitable GPU");
	}
}

void Game::main_loop(GLFWwindow* window)
{
	chunk my_chunk = make_random_chunk();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

void Game::clean_up(GLFWwindow* window)
{
	vkDestroyInstance(this->instance, nullptr);

	glfwDestroyWindow(window);
	glfwTerminate();
}
