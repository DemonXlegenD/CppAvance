#pragma once
#include "Vector2D.h"
class Collider2D 
{
public :
	Collider2D(Vector2D<float> position, float width, float height);
	~Collider2D();

	float getX() { return position.getX; }
	float getY() { return position.getY; }
	float getWidth() { return width; }
	float getHeight() { return height; }

protected :
	Vector2D<float> position;
	float width, height;
};