#include "Components/Colliders2D/Circle.h"
#define M_PI 3.14159265359
#include <cmath>

Circle::Circle() : radius(0) {}
Circle::Circle(double radius) : radius(radius) {}

double Circle::area() const {
	return radius * radius * M_PI;
}

Circle::~Circle() {}