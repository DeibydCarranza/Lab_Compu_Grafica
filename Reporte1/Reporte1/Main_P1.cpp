#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificación de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);

	//Verificación de errores de creacion  ventana
	if (window == NULL)
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

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	Shader OurShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		-0.75f,  0.8f, 0.0f,    1.0f,0.0f,0.0f,  // A-0
		-0.75f,  0.64f, 0.0f,    1.0f,0.0f,0.0f,  // B-1
		-0.6f,  0.5f, 0.0f,    1.0f,0.0f,0.0f,  //C-2
		-0.6f,  0.66f, 0.0f,    1.0f,0.0f,0.0f,  //D-3

		-0.6f,0.5f, 0.0f,    0.0f,1.0f,0.0f,  //C-4
		-0.6f,0.8f, 0.0f,    0.0f,1.0f,0.0f,  //D-5
		-0.31f,0.5f, 0.0f,    0.0f,1.0f,0.0f,  //F-6

		-0.31f,0.5f, 0.0f,    1.0f,0.0f,1.0f,  //F-7
		-0.21f,0.605f, 0.0f,    1.0f,0.0f,1.0f,  //G-8
		-0.31f,0.7f, 0.0f,    1.0f,0.0f,1.0f,  //H-9
		-0.405f,0.599f, 0.0f,    1.0f,0.0f,1.0f,  //I-10

		-0.31f,0.7f, 0.0f,    1.0f,1.0f,0.0f,  //H-11
		-0.1f,0.7f, 0.0f,    1.0f,1.0f,0.0f,  //J-12
		-0.1f,0.5f, 0.0f,    1.0f,1.0f,0.0f,  //K-13

		-0.7f,0.5f, 0.0f,    0.0f,1.0f,1.0f,  //L-14
		-0.5f,0.29f, 0.0f,    0.0f,1.0f,1.0f,  //M-15
		-0.31f,0.5f, 0.0f,    0.0f,1.0f,1.0f,  //F-16

		-0.53f,0.32f, 0.0f,		1.0f,0.5f,0.2f,  //Q-17
		-0.7f,0.32f, 0.0f,		1.0f,0.5f,0.2f,  //R-18
		-0.7f, 0.2f, 0.0f,		1.0f,0.5f, 0.2f,  //S-19

		-0.45f, 0.34f, 0.0f,		8.0f,0.7f, 0.2f,  //N-20
		-0.45f, 0.2f, 0.0f,		8.0f,0.7f, 0.2f,  //O-21
		-0.3f, 0.2f, 0.0f,		8.0f,0.7f, 0.2f,  //P-22

	};
	unsigned int indices[] = {
		0,1,2,3,  //A-B-C-D 
		4,5,6,	//C-E-F 
		7,8,9,10, //F,G,H,I 7
		11,12,13,	//H-J-K  
		14,15,16,	//L-M-F 14
		17,18,19,	//Q-R-S
		20,21,22,	//N-O-P
	};


	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Desenlazamos de memoria el VAO


	
	while (!glfwWindowShouldClose(window))
	{
		// Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.156f, 0.1523f, 0.1523f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Dibujar aquí
		OurShader.Use();
		glBindVertexArray(VAO);
			glPointSize(10);

			/* Ave primer cuadrante */
			glDrawElements(GL_TRIANGLE_FAN,4, GL_UNSIGNED_INT, (GLvoid*)(0*sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(4 * sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, (GLvoid*)(7 * sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(11 * sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(14 * sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(14 * sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(17 * sizeof(GLfloat)));
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(20 * sizeof(GLfloat)));

	
		glBindVertexArray(0);


		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}