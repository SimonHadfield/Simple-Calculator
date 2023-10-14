#include <iostream>
#include <cmath>
#include "MathFunctions.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "imgui.h"
//#include "backends/imgui_impl_glfw.h"
//#include "backends/imgui_impl_opengl3.h"

int main()
{
	// Initialize GLFW and create a window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// ..
	// 
	//ImGui::CreateContext();

	std::cout << "addition/subtraction: " << add(100.3453, -30.0234) << std::endl;
	std::cout << "multiplication: " << multiply(34.5, 2.35) << std::endl;
	std::cout << "division: " << division(10, 4) << std::endl;
	std::cout << "power: " << power(2, 4.5) << std::endl;
	std::cout << "modulo: " << mod(2, 4) << std::endl;
	std::cin.get();
}