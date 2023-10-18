#include "GameObject.h"


GameObject::GameObject();
void GameObject::addCollider(float width, float height) {
	colliders.addElement(Collider2D(position, width, height));
}

GameObject::~GameObject();