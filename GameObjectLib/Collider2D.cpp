#include "Collider2D.h"
#include "Vector2D.h"

Collider2D::Collider2D(float x, float y, float width, float height) : position( Vector2D<float>(x, y)), width(width),height(height){}
Collider2D::Collider2D(Vector2D<float> position, float width, float height) : position(position), width(width),height(height){}

bool Collider2D::collisionTrigger(Collider2D& colliderB)
{
	bool collisionX = (getX() < colliderB.getX() + colliderB.getWidth()) &&
		(getX() + getWidth() > colliderB.getX());

	bool collisionY = (getY() < colliderB.getY() + colliderB.getHeight()) &&
		(getY() + getHeight() > colliderB.getY());

	if (collisionX && collisionY)
	{
		return true;
	}
	else
	{
		return false;
	}
}