/*
 * sprite.h
 *
 *  Created on: May 28, 2016
 *      Author: chris
 */

#ifndef SPRITE_H_
#define SPRITE_H_


#include <iostream>
#include <GLFW/glfw3.h>

typedef struct {
	GLfloat x;
	GLfloat y;
} Vector2;

class Sprite
{
private:
	GLuint _textureBufferID;
	Vector2 _position;

public:
	void setPosition(Vector2 newPosition);
	Vector2 getPosition();
	Sprite(GLuint textureBufferID);
	void render();
	void update();
};


#endif /* SPRITE_H_ */
