#include <iostream>
#include <cmath>
#include "MathFunctions.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	// Initialize GLFW and create a window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Calculator", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	// ..
	// 
	//ImGui::CreateContext();

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	// io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; -- switch git submodule to docking branch to use

	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
	ImGui_ImplOpenGL3_Init();

	//

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	// Calculator variables
	double firstNumber = 0.0f;
	double secondNumber = 0.0f;
	char operation = '+';
	float result = 0;
	bool return_result = false;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// ImGui::ShowDemoWindow();

		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Calculator", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);

		// Get the current window size
		int windowWidth, windowHeight;
		glfwGetWindowSize(window, &windowWidth, &windowHeight);

		ImGui::SetWindowPos(ImVec2(0, 0));
		ImGui::SetWindowSize(ImVec2(static_cast<float>(windowWidth),static_cast<float>(windowHeight)));
		glViewport(0, 0, static_cast<float>(windowWidth), static_cast<float>(windowHeight));

		// Change

		ImGui::InputDouble("First Number", &firstNumber);
		ImGui::InputDouble("Second Number", &secondNumber);

		ImGui::Text("Select an operation:");

		if (ImGui::Button("+")) {
			operation = '+';
		}
		ImGui::SameLine();
		if (ImGui::Button("-")) {
			operation = '-';
		}
		ImGui::SameLine();
		if (ImGui::Button("*")) {
			operation = '*';
		}
		ImGui::SameLine();
		if (ImGui::Button("/")) {
			operation = '/';
		}
		if (ImGui::Button("%")) {
			operation = '%';
		}
		ImGui::SameLine();
		if (ImGui::Button("^")) {
			operation = '^';
		}
		ImGui::SameLine();
		if (ImGui::Button("!")) {
			operation = '!';
		}

		if (ImGui::Button("Calculate")) {
			switch (operation) {
			case '+':
				result = add(firstNumber, secondNumber);
				break;
			case '-':
				result = add(firstNumber, -secondNumber);
				break;
			case '*':
				result = multiply(firstNumber, secondNumber);
				break;
			case '/':
				result = division(firstNumber, secondNumber);
				break;
			case '%':
				result = mod(firstNumber, secondNumber);
				break;
			case '^':
				result = power(firstNumber, secondNumber);	// secondNumber -> exponent
				break;
			case '!':
				result = factorial(static_cast<unsigned int>(firstNumber)); 
				break;
			default:
				result = 0.0f;
				break;
			}

			return_result = true;
		}

		ImGui::Text("Note: Factorial (!) takes first value as argument");

		ImGui::Text("\nResult: ");

		if (return_result)
		{
			if (operation != '!')
			{
				ImGui::Text("%.2f %c %.2f = %.2f", firstNumber, operation, secondNumber, result);
				//ImGui::Text(firstNumber, " ", operation, " ", secondNumber, "= %.2f", result);
			}
			if (operation == '!')
			{
				ImGui::Text("Factorial of %.2f = %.2f", firstNumber, result);
			}
		}

		ImGui::End();

		// Rendering
		ImGui::Render();

		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		

		glClearColor(0.2, 0.2, 0.2, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();


	std::cout << "addition/subtraction: " << add(100.3453, -30.0234) << std::endl;
	std::cout << "multiplication: " << multiply(34.5, 2.35) << std::endl;
	std::cout << "division: " << division(10, 4) << std::endl;
	std::cout << "power: " << power(2, 4.5) << std::endl;
	std::cout << "modulo: " << mod(2, 4) << std::endl;
	std::cin.get();

	return 0;
}