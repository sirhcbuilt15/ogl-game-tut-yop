/*
 * GameWindow.h
 *
 *  Created on: May 13, 2016
 *      Author: chris
 */

#ifndef _SimpleOpenGLGame_GameWindow_
#define _SimpleOpenGlGame_GameWindow_

/* To use glGenBuffers and others */
#define GL_GLEXT_PROTOTYPES
#define GLFW_INCLUDE_GLEXT

#include <iostream>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <vector>
#include "sprite.h"

class GameWindow
{
private:
	bool _running;
	GLfloat _height;
	GLfloat _width;
	GLuint _vertexBufferID;
	GLuint _textureBufferID;
	GLuint loadAndBufferImage(const char *filename);
	Sprite *_rocket;

	GLFWwindow* _window;

public:
	void setRunning( bool newRunning );
	bool getRunning();

	GameWindow( bool running, GLFWwindow* window );

	void render();
	void update();
};

#endif /*defined _SimpleOpenGLGame_GameWindow_ */
