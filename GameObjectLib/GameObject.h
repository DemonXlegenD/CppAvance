#pragma once
#include <string>
#include "Collider2D.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject();
	GameObject(std::string name, float x, float y);



	~GameObject();
protected:
	std::string name = "GameObject";
	Vector2D<float> position = new Vector2D<float>(0.f, 0.f);
	Collider2D collider = NULL;
};