// C++ Resources
#include <iostream>
#include <cmath>

// OpenGL Resources
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// GLM Resources
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Library Resources
#include "libraries/shaders/Shader.h"
#include "libraries/shaders/VertexArrayObject.h"
#include "libraries/shaders/ElementBufferObject.h"
#include "libraries/shaders/VertexBufferObject.h"
#include "libraries/visual/Texture.h"
#include "libraries/stb.h"
#include "libraries/classes/Camera.h"
#include "libraries/engine/Timer.h"

using namespace Vertex3D;

const unsigned int width = 800;
const unsigned int height = 800;

int main()
{
	// Vertices coordinates
	GLfloat vertices[] =
	{
		// POSITION					 COLOR			 TEXTURE	//
		// X,    Y,    Z,	     R,	   G,	 B		 X,	   Y   //
		-0.5f, 0.0f, 0.5f, 	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f, 	1.0f, 1.0f, 0.0f,	5.0f, 1.0f,
		0.5f, 0.0f, -0.5f, 		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,
		0.5f, 0.0f, 0.5f, 		1.0f, 1.0f, 1.0f,	5.0f, 0.0f,
		0.0f, 0.8f, 0.0f, 		1.0f, 1.0f, 1.0f,	2.5f, 5.0f
	};

	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
	};

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Check to make sure glfw was initialized
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// Create a GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(width, height, "Vertex3DEngine", nullptr, nullptr);
	// Error check if the window fails to create
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Setup game timer for deltaTime and other stuff
	extern Timer *timer;

	// Create Shader program and give it the default vertice and default fragment shader
	Shader shaderProgram("src/shaders/default.vert", "src/shaders/default.frag");
	// Generate the VertexArrayObject
	VertexArrayObject VAO1;
	// Bind the VertexArrayObject
	VAO1.Bind();

	// Generates VertexBufferObject and links to the vertices given
	VertexBufferObject VBO1(vertices, sizeof(vertices));
	// Generates ElementBufferObject and links to the indices given
	ElementBufferObject EBO1(indices, sizeof(indices));

	// Links the VertexArrayObject to the VertexBufferObject starting at the index 0
	VAO1.Link(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.Link(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Link(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbinds all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Texture
	Texture testTexture = Texture("src/textures/dev/keryu.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	testTexture.texUnit(shaderProgram, "tex0", 0);

	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		testTexture.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	testTexture.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}