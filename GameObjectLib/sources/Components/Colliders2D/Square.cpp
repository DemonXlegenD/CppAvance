#include "Components/Colliders2D/Square.h"

Square::Square() : sideLength(0) {}
Square::Square(double sideLength) : sideLength(sideLength) {}

double Square::area() const {
	return sideLength * sideLength;
}

Square::~Square() {}