#include "GameObject.h"



GameObject::GameObject(){}
GameObject::GameObject(std::string name, float x, float y) : name(name), position(Vector2D<float>(x,y)) {}

void GameObject::addCollider(float width, float height) {
	colliders.push_back(Collider2D(position, width, height));
}

GameObject::~GameObject(){}