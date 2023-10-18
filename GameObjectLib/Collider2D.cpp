#include "Collider2D.h"

Collider2D::Collider2D();

Collider2D::collisionTrigger(const Collider2D& colliderA, const Collider2D& colliderB)
{
	bool collisionX = (colliderA.GetX() < colliderB.GetX() + colliderB.GetWidth()) &&
		(colliderA.GetX() + colliderA.GetWidth() > colliderB.GetX());

	bool collisionY = (colliderA.GetY() < colliderB.GetY() + colliderB.GetHeight()) &&
		(colliderA.GetY() + colliderA.GetHeight() > colliderB.GetY());

	if (collisionX && collisionY)
	{
		return true;
	}
	else
	{
		return false;
	}
}