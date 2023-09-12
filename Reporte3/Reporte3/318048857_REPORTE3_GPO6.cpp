#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
float rotX = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Reporte 3", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shaders/core.vs", "Shaders/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {

		// ---------- Cubo Azul marino  0
		-0.5f, -0.5f, 0.5f, 0.1758f, 0.3438f, 0.5664f,
		0.5f, -0.5f, 0.5f,  0.1758f, 0.3438f, 0.5664f,
		0.5f,  0.5f, 0.5f,  0.1758f, 0.3438f, 0.5664f,
		0.5f,  0.5f, 0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f,  0.5f, 0.5f, 0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f, 0.5f, 0.1758f, 0.3438f, 0.5664f,

		-0.5f, -0.5f,-0.5f, 0.1758f, 0.3438f, 0.5664f,
		 0.5f, -0.5f,-0.5f, 0.1758f, 0.3438f, 0.5664f,
		 0.5f,  0.5f,-0.5f, 0.1758f, 0.3438f, 0.5664f,
		 0.5f,  0.5f,-0.5f, 0.1758f, 0.3438f, 0.5664f,
		-0.5f,  0.5f,-0.5f, 0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f,-0.5f, 0.1758f, 0.3438f, 0.5664f,

		 0.5f, -0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		 0.5f, -0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		 0.5f,  0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		 0.5f,  0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		 0.5f,  0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		 0.5f,  -0.5f, 0.5f, 0.1758f, 0.3438f, 0.5664f,

		-0.5f,  0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f,  0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f,  0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,

		-0.5f, -0.5f, -0.5f, 0.1758f, 0.3438f, 0.5664f,
		0.5f, -0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		0.5f, -0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		0.5f, -0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f,  0.5f, 0.1758f, 0.3438f, 0.5664f,
		-0.5f, -0.5f, -0.5f, 0.1758f, 0.3438f, 0.5664f,

		-0.5f,  0.5f, -0.5f, 0.1758f, 0.3438f, 0.5664f,
		0.5f,  0.5f, -0.5f,  0.1758f, 0.3438f, 0.5664f,
		0.5f,  0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		0.5f,  0.5f,  0.5f,  0.1758f, 0.3438f, 0.5664f,
		-0.5f,  0.5f,  0.5f, 0.1758f, 0.3438f, 0.5664f,
		-0.5f,  0.5f, -0.5f, 0.1758f, 0.3438f, 0.5664f,


		// ---------- Cubo Dorado 36
		-0.5f, -0.5f, 0.5f, 0.9922f, 0.8906f, 0.2461f,
		0.5f, -0.5f, 0.5f,  0.9922f, 0.8906f, 0.2461f,
		0.5f,  0.5f, 0.5f,  0.9922f, 0.8906f, 0.2461f,
		0.5f,  0.5f, 0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f,  0.5f, 0.5f, 0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f, 0.5f, 0.9922f, 0.8906f, 0.2461f,

		-0.5f, -0.5f,-0.5f, 0.9922f, 0.8906f, 0.2461f,
		 0.5f, -0.5f,-0.5f, 0.9922f, 0.8906f, 0.2461f,
		 0.5f,  0.5f,-0.5f, 0.9922f, 0.8906f, 0.2461f,
		 0.5f,  0.5f,-0.5f, 0.9922f, 0.8906f, 0.2461f,
		-0.5f,  0.5f,-0.5f, 0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f,-0.5f, 0.9922f, 0.8906f, 0.2461f,

		 0.5f, -0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		 0.5f, -0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		 0.5f,  0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		 0.5f,  0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		 0.5f,  0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		 0.5f,  -0.5f, 0.5f,  0.9922f, 0.8906f, 0.2461f,

		-0.5f,  0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f,  0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f,  0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,

		-0.5f, -0.5f, -0.5f, 0.9922f, 0.8906f, 0.2461f,
		0.5f, -0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		0.5f, -0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		0.5f, -0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f,  0.5f, 0.9922f, 0.8906f, 0.2461f,
		-0.5f, -0.5f, -0.5f, 0.9922f, 0.8906f, 0.2461f,

		-0.5f,  0.5f, -0.5f, 0.9922f, 0.8906f, 0.2461f,
		0.5f,  0.5f, -0.5f,  0.9922f, 0.8906f, 0.2461f,
		0.5f,  0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		0.5f,  0.5f,  0.5f,  0.9922f, 0.8906f, 0.2461f,
		-0.5f,  0.5f,  0.5f, 0.9922f, 0.8906f, 0.2461f,
		-0.5f,  0.5f, -0.5f, 0.9922f, 0.8906f, 0.2461f,

		// ---------- Cubo Naranja 72
		-0.5f, -0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, -0.5f, 0.5f,  0.9766f, 0.4688f, 0.2188f,
		0.5f,  0.5f, 0.5f,  0.9766f, 0.4688f, 0.2188f,
		0.5f,  0.5f, 0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f,  0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,

		-0.5f, -0.5f,-0.5f, 0.9766f, 0.4688f, 0.2188f,
		 0.5f, -0.5f,-0.5f, 0.9766f, 0.4688f, 0.2188f,
		 0.5f,  0.5f,-0.5f, 0.9766f, 0.4688f, 0.2188f,
		 0.5f,  0.5f,-0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f,  0.5f,-0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f,-0.5f, 0.9766f, 0.4688f, 0.2188f,

		 0.5f, -0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		 0.5f, -0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		 0.5f,  0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		 0.5f,  0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		 0.5f,  0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		 0.5f,  -0.5f, 0.5f,  0.9766f, 0.4688f, 0.2188f,

		-0.5f,  0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f,  0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f,  0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,

		-0.5f, -0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, -0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		0.5f, -0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		0.5f, -0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f,  0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,

		-0.5f,  0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f,  0.5f, -0.5f,  0.9766f, 0.4688f, 0.2188f,
		0.5f,  0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		0.5f,  0.5f,  0.5f,  0.9766f, 0.4688f, 0.2188f,
		-0.5f,  0.5f,  0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f,  0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,


		// ---------- Cubo Azul claro 108
		-0.5f, -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f,  -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f,  0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, 0.5f, 0.1484f, 0.7344f, 0.7813f,

		-0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		0.5f, -0.5f, -0.5f,  0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, -0.5f,	 0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, -0.5f,	 0.1484f, 0.7344f, 0.7813f,
		-0.5f, 0.5f, -0.5f,  0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,

		0.5f, -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, -0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, -0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,

		-0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, 0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,

		-0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		0.5f, -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, -0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, 0.5f, 0.1484f, 0.7344f, 0.7813f,
		-0.5f, -0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,

		-0.5f, 0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, -0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, 0.5f, 0.5f,	0.1484f, 0.7344f, 0.7813f,
		-0.5f, 0.5f, -0.5f, 0.1484f, 0.7344f, 0.7813f,

		// ---------- Cubo Negro 144
		-0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,

		-0.5f, -0.5f, -0.5f,	0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, -0.5f,	0.0547f, 0.1055f, 0.1484f,

		0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,

		-0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, -0.5f,	0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, -0.5f,	0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,

		-0.5f, -0.5f, -0.5f,	0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, -0.5f, -0.5f,	0.0547f, 0.1055f, 0.1484f,

		-0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, 0.5f, 0.5f,		0.0547f, 0.1055f, 0.1484f,
		-0.5f, 0.5f, -0.5f,		0.0547f, 0.1055f, 0.1484f,

		// ---------- Cubo NaranjaAzul 180
		-0.5f, -0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, -0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, 0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, 0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, 0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, -0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,

		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,

		0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,

		-0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f, 

		-0.5f, -0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,//azul marino oscuro
		0.5f, -0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, -0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, -0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		-0.5f, -0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		-0.5f, -0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,
			
		-0.5f, 0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,//naranja
		0.5f, 0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, 0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		0.5f, 0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, 0.5f, 0.5f, 0.9766f, 0.4688f, 0.2188f,
		-0.5f, 0.5f, -0.5f, 0.9766f, 0.4688f, 0.2188f,

		// ---------- Cubo Azul marino oscuro 216
		-0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f, 

		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,

		0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f, 
		0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,

		-0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, -0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, -0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,
		-0.5f, 0.5f, 0.5f, 0.1445f, 0.3203f, 0.5429f,

		-0.5f, -0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, -0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, -0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, -0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		-0.5f, -0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		-0.5f, -0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,

		-0.5f, 0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, 0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, 0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		0.5f, 0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		-0.5f, 0.5f, 0.5f, 0.1406f, 0.293f, 0.5625f,
		-0.5f, 0.5f, -0.5f, 0.1406f, 0.293f, 0.5625f,

	};




	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::rotate(view, glm::radians(rotX), glm::vec3(1.0f, 0.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	
		//0-AzM, 36-Dor, 72-Nar, 108-AzC, 144-Neg, 180-NarAz
		glBindVertexArray(VAO);

		{// ----- CUERPO -----
				//Torso naranja azul
			model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(0.6f, 3.0f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 180, 36);
			model = glm::mat4(1);

			//Torso laterales azul
			model = glm::translate(model, glm::vec3(0.65f, 1.25f, 0.0f));
			model = glm::scale(model, glm::vec3(0.7f, 2.5f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 216, 36);
			model = glm::mat4(1);

			model = glm::translate(model, glm::vec3(-0.65f, 1.25f, 0.0f));
			model = glm::scale(model, glm::vec3(0.7f, 2.5f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 216, 36);
			model = glm::mat4(1);

			//Hombros
			model = glm::translate(model, glm::vec3(-1.125f, 1.15f, 0.0f));
			model = glm::scale(model, glm::vec3(0.25f, 1.3f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 216, 36);
			model = glm::mat4(1);

			model = glm::translate(model, glm::vec3(1.125f, 1.15f, 0.0f));
			model = glm::scale(model, glm::vec3(0.25f, 1.3f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 216, 36);
			model = glm::mat4(1);

			//Cadera
			model = glm::translate(model, glm::vec3(-0.4f, -0.25f, 0.0f));
			model = glm::scale(model, glm::vec3(0.2f, 0.5f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 216, 36);
			model = glm::mat4(1);

			model = glm::translate(model, glm::vec3(0.4f, -0.25f, 0.0f));
			model = glm::scale(model, glm::vec3(0.2f, 0.5f, 0.9f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 216, 36);
			model = glm::mat4(1);
		}

			// ----- CABEZA -----
				//Orejas largas
				model = glm::translate(model, glm::vec3(-1.2f, 2.85f, 0.0f));
				model = glm::scale(model, glm::vec3(0.4f, 1.1f, 0.4f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(1.2f, 2.85f, 0.0f));
				model = glm::scale(model, glm::vec3(0.4f, 1.1f, 0.4f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				//Punta orejas largas
				model = glm::translate(model, glm::vec3(-1.1f, 3.5f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.4f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(1.1f, 3.5f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.4f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				//Ojo negro
				model = glm::translate(model, glm::vec3(0.0f, 2.7f, 0.2f));
				model = glm::scale(model, glm::vec3(0.2f, 0.4f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				//Contorno amarillo ojo
				model = glm::translate(model, glm::vec3(-0.15f, 2.8f, 0.2f));
				model = glm::scale(model, glm::vec3(0.1f, 0.6f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.15f, 2.8f, 0.2f));
				model = glm::scale(model, glm::vec3(0.1f, 0.6f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.0f, 3.0f, 0.2f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				//Laterales naranjas del ojo
				model = glm::translate(model, glm::vec3(0.25f, 2.8f, 0.2f));
				model = glm::scale(model, glm::vec3(0.1f, 0.6f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.25f, 2.8f, 0.2f));
				model = glm::scale(model, glm::vec3(0.1f, 0.6f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				//Parte posterior ojo - Naranja
				model = glm::translate(model, glm::vec3(0.0f, 2.8f, -0.1f));
				model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				//Antenas laterales del ojo
				model = glm::translate(model, glm::vec3(-0.4f, 3.1f, 0.0f));
				model = glm::scale(model, glm::vec3(0.4f, 0.8f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.4f, 3.1f, 0.0f));
				model = glm::scale(model, glm::vec3(0.4f, 0.8f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				//Pico antenas laterales ojo
				model = glm::translate(model, glm::vec3(0.3f, 3.6f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.3f, 3.6f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

			/*      BRAZOS  */
				//Hombros
				model = glm::translate(model, glm::vec3(1.325f, 1.5f, 0.0f));
				model = glm::scale(model, glm::vec3(0.15f, 0.6f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-1.325f, 1.5f, 0.0f));
				model = glm::scale(model, glm::vec3(0.15f, 0.6f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				//Brazos
				model = glm::translate(model, glm::vec3(-1.7f, 0.95f, 0.0f));
				model = glm::scale(model, glm::vec3(0.6f, 1.5f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(1.7f, 0.95f, 0.0f));
				model = glm::scale(model, glm::vec3(0.6f, 1.5f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				//Muñecas
				model = glm::translate(model, glm::vec3(1.7f, 0.1f, 0.0f));
				model = glm::scale(model, glm::vec3(0.6f, 0.2f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-1.7f, 0.1f, 0.0f));
				model = glm::scale(model, glm::vec3(0.6f, 0.2f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				//Dedos mano
				model = glm::translate(model, glm::vec3(-1.9f, -0.2f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.4f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(1.9f, -0.2f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.4f, 0.6f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				//Dedos pulgares
				model = glm::translate(model, glm::vec3(-1.5f, -0.1f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(1.5f, -0.1f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.3f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				//Hombreras laterales
				model = glm::translate(model, glm::vec3(2.1f, 1.3f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 1.6f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-2.1f, 1.3f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 1.6f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				//Hombreras superiores
				model = glm::translate(model, glm::vec3(-1.9f, 1.8f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(1.9f, 1.8f, 0.0f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);
			
			/* PARTE BAJA */
				//Piernas-Femur
				model = glm::translate(model, glm::vec3(0.8f, -0.7f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 1.4f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.8f, -0.7f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 1.4f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				//Rodillas
				model = glm::translate(model, glm::vec3(-0.8f, -1.5f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 0.2f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.8f, -1.5f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 0.2f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				//Espinillas
				model = glm::translate(model, glm::vec3(-0.8f, -1.7f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 0.2f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.8f, -1.7f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 0.2f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 0, 36);
				model = glm::mat4(1);

				//Pies
				model = glm::translate(model, glm::vec3(-0.8f, -2.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 0.4f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.8f, -2.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.65f, 0.4f, 0.65f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				//Dedos
				model = glm::translate(model, glm::vec3(0.98f, -2.1f, 0.425f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.62f, -2.1f, 0.425f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.98f, -2.1f, 0.425f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.62f, -2.1f, 0.425f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

			/* Cara */
				//Boca
				model = glm::translate(model, glm::vec3(0.0f, 0.8f, 0.46f));
				model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.05f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				//Labios
				model = glm::translate(model, glm::vec3(0.4f, 0.8f, 0.555f));
				model = glm::scale(model, glm::vec3(0.2f, 1.0f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.4f, 0.8f, 0.555f));
				model = glm::scale(model, glm::vec3(0.2f, 1.0f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.0f, 1.2f, 0.555f));
				model = glm::scale(model, glm::vec3(0.6f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.0f, 0.4f, 0.555f));
				model = glm::scale(model, glm::vec3(0.6f, 0.2f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 108, 36);
				model = glm::mat4(1);

				//Dientes
				model = glm::translate(model, glm::vec3(0.2f, 0.6f, 0.5f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.1f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.2f, 0.6f, 0.5f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.1f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.2f, 1.0f, 0.5f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.1f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.2f, 1.0f, 0.5f));
				model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.1f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

			/* OJOS*/
				//Parpado
				model = glm::translate(model, glm::vec3(-0.45f, 1.475f, 0.555f));
				model = glm::scale(model, glm::vec3(0.5f, 0.15f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);
				
				model = glm::translate(model, glm::vec3( 0.45f, 1.475f, 0.555f));
				model = glm::scale(model, glm::vec3(0.5f, 0.15f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 72, 36);
				model = glm::mat4(1);

				//Corneas inferior amarilla
				model = glm::translate(model, glm::vec3(0.45f, 1.625f, 0.555f));
				model = glm::scale(model, glm::vec3(0.5f, 0.15f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.45f, 1.625f, 0.555f));
				model = glm::scale(model, glm::vec3(0.5f, 0.15f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				//Corneas lateral izquierda amarilla
				model = glm::translate(model, glm::vec3(-0.29f, 1.925f, 0.555f));
				model = glm::scale(model, glm::vec3(0.18f, 0.45f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.29f, 1.925f, 0.555f));
				model = glm::scale(model, glm::vec3(0.18f, 0.45f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				//Corneas lateral derecha amarilla
				model = glm::translate(model, glm::vec3(-0.61f, 1.925f, 0.555f));
				model = glm::scale(model, glm::vec3(0.18f, 0.45f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(0.61f, 1.925f, 0.555f));
				model = glm::scale(model, glm::vec3(0.18f, 0.45f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 36, 36);
				model = glm::mat4(1);

				//Pupilas negras
				model = glm::translate(model, glm::vec3(0.45f, 1.925f, 0.555f));
				model = glm::scale(model, glm::vec3(0.14f, 0.45f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.45f, 1.925f, 0.555f));
				model = glm::scale(model, glm::vec3(0.14f, 0.45f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				//Cejas
				model = glm::translate(model, glm::vec3(0.45f, 2.225f, 0.555f));
				model = glm::scale(model, glm::vec3(0.5f, 0.15f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

				model = glm::translate(model, glm::vec3(-0.45f, 2.225f, 0.555f));
				model = glm::scale(model, glm::vec3(0.5f, 0.15f, 0.2f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				glDrawArrays(GL_TRIANGLES, 144, 36);
				model = glm::mat4(1);

		glBindVertexArray(0);


		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		 movY += 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		 movY -= 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.005f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.05f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.05f;
	 if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) 
		 rotX += 0.05f;  
	 if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)  
		 rotX -= 0.05f; 

 }


