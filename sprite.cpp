/*
 * sprite.cpp
 *
 *  Created on: May 28, 2016
 *      Author: chris
 */


#include "sprite.h"


void Sprite::setPosition(Vector2 newPosition)
{
	_position = newPosition;
}

Vector2 Sprite::getPosition()
{
	return _position;
}

Sprite::Sprite(GLuint textureBufferID)
{
	_textureBufferID = textureBufferID;
}

void Sprite::render()
{
	glBindTexture(GL_TEXTURE_2D,  _textureBufferID);
	glDrawArrays(GL_QUADS, 0, 4);
}

void Sprite::update()
{

}


