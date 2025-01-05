#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "libraries/shaders/Shader.h"
#include "libraries/shaders/VertexArrayObject.h"
#include "libraries/shaders/ElementBufferObject.h"
#include "libraries/shaders/VertexBufferObject.h"
#include "libraries/visual/Texture.h"
#include "libraries/stb.h"

using namespace Vertex3D;

int main()
{
	// Vertices coordinates
	GLfloat vertices[] =
	{
		// POSITION					 COLOR			 TEXTURE	//
		// X,    Y,    Z,	     R,	   G,	 B		 X,	   Y   //
		-0.5f, -0.5f, 0.0f, 	1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower Left Corner
		-0.5f, 0.5f, 0.0f, 		1.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper Left Corner
		0.5f, 0.5f, 0.0f, 		0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper Right Corner
		0.5f, -0.5f, 0.0f, 		1.0f, 1.0f, 1.0f,	1.0f, 0.0f // Lower Left Corner
	};

	GLuint indices[] =
	{
		0, 2, 1,
		0, 3, 2
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
	GLFWwindow* window = glfwCreateWindow(800, 800, "Vertex3DEngine", nullptr, nullptr);
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
	glViewport(0, 0, 800, 800);

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

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	// Texture
	Texture testTexture = Texture("src/textures/dev/keryu.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	testTexture.texUnit(shaderProgram, "tex0", 0);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		glUniform1f(uniID, 0.5f);
		testTexture.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
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