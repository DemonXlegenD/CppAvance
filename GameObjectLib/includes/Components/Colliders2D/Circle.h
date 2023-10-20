#pragma once
#include "Components/Collider2D.h"
class Circle : public Collider2D
{
public:
	Circle();
	Circle(double radius);

	double area() const override;

	~Circle();
private:
	double radius;
};

