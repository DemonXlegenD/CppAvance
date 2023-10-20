#pragma once
#include "Vector2D.h"

class Collider2D
{
public:
	Collider2D();
	Collider2D(Vector2D<float> position, float width, float height);
	Collider2D(float x, float y, float width, float height);

	float getX() { return position.getX(); }
	float getY() { return position.getY(); }
	Vector2D<float> getVector2D() { return position; }

	float getWidth() { return width; }
	float getHeight() { return height; }

	bool collisionTrigger(Collider2D& colliderB);


protected:
	Vector2D<float> position;
	float width, height;
};