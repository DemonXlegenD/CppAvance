#pragma once
#include "Vector2D.h"
class Collider2D
{
public:
	Collider2D(Vector2D<float> position, float width, float height);
	Collider2D(float x, float y, float width, float height) {
		Vector2D<auto>(x, y) position;
	}

	float getX() { return position.getX; }
	float getY() { return position.getY; }
	Vector2D<auto> getVector2D() { return position; }

	float getWidth() { return width; }
	float getHeight() { return height; }

	bool collisionTrigger(const Collider2D& colliderA, const Collider2D& colliderB);

	~Collider2D();

protected:
	Vector2D<float> position;
	float width, height;
};