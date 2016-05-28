/*
 * GameWindow.cpp
 *
 *  Created on: May 13, 2016
 *      Author: chris
 */

#include "GameWindow.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "third_party/stb_image.h"

// Hacemos una estructura para manejar la posición
typedef struct {
	GLfloat positionCoordinates[3];
	GLfloat textureCoordinates[2];
} VertexData;

#define Square_Size 100

VertexData vertices[] = {
	{{0.0f, 0.0f, 0.0f},				{0.0f, 1.0f}},
	{{Square_Size, 0.0f, 0.0f},			{1.0f, 1.0f}},
	{{Square_Size, Square_Size, 0.0f},	{1.0f, 0.0f}},
	{{0.0f, Square_Size, 0.0f},			{0.0f, 0.0f}}
};

void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
}

GLuint GameWindow::loadAndBufferImage(const char *filename)
{
	int width, height, bpp /* 8-bit component per pixel*/;
	unsigned char *data = NULL;

	GLuint textureBufferID;

	data = stbi_load(filename, &width, &height, &bpp, 0);
	if( data == NULL )
		return 0;

	glGenTextures(1, &textureBufferID);
	glBindTexture(GL_TEXTURE_2D, textureBufferID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	stbi_image_free(data);

	return textureBufferID;
}

GameWindow::GameWindow(bool running, GLFWwindow* window): _running(running), _height(800), _width(800*16/9), _vertexBufferID(0)
{
	_window = window;
	glClearColor(0.5f, 0.2f, 0.45f, 0.5f);
	glViewport(0.0f, 0.0f, _width, _height);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, _width, 0.0, _height);
	glMatrixMode(GL_MODELVIEW);

	glGenBuffers(1, &_vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *) offsetof(VertexData, positionCoordinates) );

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *) offsetof(VertexData, textureCoordinates) );

	_textureBufferID = loadAndBufferImage("nave.png");

	_rocket = new Sprite(_textureBufferID);
}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	/*part5Tutotial
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex2d( 100.0f, 100.0f);
	glVertex2d( 200.0f, 100.0f);
	glVertex2d( 200.0f, 200.0f);
	glVertex2d( 100.0f, 200.0f);
	glEnd();
     	*/

	//glColor3f(0.45f, 1.0f, 0.95f);
	//glDrawArrays(GL_QUADS, 0, 4);

	_rocket->render();

   	glfwSwapBuffers(_window);
}

void GameWindow::update()
{

}





