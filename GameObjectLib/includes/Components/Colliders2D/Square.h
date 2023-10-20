#pragma once
#include "Components/Collider2D.h"
class Square : public Collider2D
{
public:
	Square();
	Square(double sideLength);

	double area() const override;

	~Square();
private:
	double sideLength;
};

