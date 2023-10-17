#pragma once

template <typename T>
class Vector2D
{
public:
	Vector2D();
	Vector2D(T X, T Y);
	T getX() { return X; }
	T getY() { return Y; }
	void setX(T x) { X = x; }
	void setY(T y) { Y = y; }

	Vector2D add(const Vector2D left, const Vector2D right);
	Vector2D operator+(const Vector2D& otherVector2D) const;

	Vector2D minus(const Vector2D left, const Vector2D right);
	Vector2D operator-(const Vector2D& otherVector2D) const;

	Vector2D kVector2D(T k, const Vector2D vector);
	Vector2D operator*(T k) const;

	T scalarProduct(const Vector2D left, const Vector2D right);

private:
	T X = 0;
	T Y = 0;
};

