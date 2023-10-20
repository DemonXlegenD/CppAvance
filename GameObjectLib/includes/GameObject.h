#pragma once
#include <string>
#include "Components/Collider2D.h"
#include "Vector2D.h"
#include "Container.h"

class GameObject
{
public:
	GameObject();
	GameObject(std::string name, float x, float y);
	Vector2D<float> getPosition() { return position; }

	void addCollider(float width, float height);
	Collider2D getCollider(int index) {
		return colliders[index];
	}

	~GameObject();

protected:
	std::string name = "GameObject";
	Vector2D<float> position = Vector2D<float>(0.f, 0.f);
	Container<Collider2D> colliders;
};