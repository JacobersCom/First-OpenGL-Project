#include <KHR/khrplatform.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Seting the openGL version to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Sets the openGL profile. Here we are using core

	GLFWwindow* window = glfwCreateWindow(800, 600, "My first Window!!!", NULL, NULL); // Starting the processing the creating a windowed, window. 
	// Leaving the last 2 arguments null because we don't want to have the window screened nor share resources.
	
	if (window == NULL) // if the pointer is null cout an error and close the window
	{
		std::cout << "Failed to create GLFW window" << "\n";
		glfwTerminate();
		return 0;
	}

	glfwMakeContextCurrent(window); // Current thing we are wanting to change is the window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Enabling the viewport resize

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // if glad can find the functions for openGL. Send out an error
	{
		std::cout << "Failed to initialize GLAD" << "\n";
		return 0;
	}


	while (!glfwWindowShouldClose(window)) { // This is the main rendering loop. Always processing the rendering info first

		processInput(window); // Always run waiting for the check to return true
		glClear(GL_COLOR_BUFFER_BIT); // Clears the color buffer for glClearColor. A state using function
		glClearColor(0.2f, 0.3f, 0.3f, 1.0); // A state setting function
		glfwSwapBuffers(window); // Swaps the front and back buffer of the chosen window
		glfwPollEvents(); // Processes event that return immediately (input, mouse movement and window updates)
	}

	glfwTerminate();
	return 0;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) // Gives the user the ability to resize his/her window
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) // The application will close when esc is pressed
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
