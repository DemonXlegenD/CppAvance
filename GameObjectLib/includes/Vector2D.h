#pragma once
#include <limits>
#include <cmath>
#include "Game/GameLog.h"

template <typename T>
class Vector2D
{
public:

	/*Constructors*/
	Vector2D();
	Vector2D(T X, T Y);

	/*Properties*/
	double magnitude();
	const T getX() { return X; }
	const T getY() { return Y; }
	void setX(T x) { X = x; }
	void setY(T y) { Y = y; }
	Vector2D normalized();

	Vector2D add(const Vector2D left, const Vector2D right);


	Vector2D minus(const Vector2D left, const Vector2D right);

	Vector2D kVector2D(T k, const Vector2D vector);




	/*Public methods*/
	void normalize();
	void set(T x, T y);
	void toString();


	bool equals(Vector2D<T> vector2D);

	/*Static properties*/
	static Vector2D down();
	static Vector2D up();
	static Vector2D left();
	static Vector2D right();
	static Vector2D one();
	static Vector2D zero();
	static Vector2D negativeInfinity();
	static Vector2D positiveInfinity();

	//MODIFIER LES return T
	/*Static Methods*/
	static T angle(Vector2D<T> vector2D_1, Vector2D<T> vector2D_2);
	static T dot(const Vector2D<T> left, const Vector2D<T> right);
	static Vector2D<T> clampMagnitude(const Vector2D<T> vector, double maxMagnitude);
	static double distance(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2);
	static Vector2D<T> lerp(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2, double t);
	static Vector2D<T> lerpUnclamped(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2, double t);
	static Vector2D<T> min(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2);
	static Vector2D<T> max(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2);
	static Vector2D<T> perpendicular(const Vector2D<T> vector);
	static Vector2D<T> reflect(const Vector2D<T> vector2D, const Vector2D<T> normal);
	static Vector2D<T> scale(const Vector2D<T> vector2D, const Vector2D<T> normal);
	static float signedAngle(const Vector2D<T> from, const Vector2D<T> to);

	/*Operators*/
	Vector2D operator+(const Vector2D& otherVector2D) const;

	Vector2D operator-(const Vector2D& otherVector2D) const;
	Vector2D operator-() const;

	Vector2D operator*(T k) const;
	Vector2D operator*(const Vector2D& vector2D) const;

	Vector2D operator/(T k) const;
	Vector2D operator/(const Vector2D& vector2D) const;
	T operator[](int index) const;

	bool operator==(const Vector2D& vector2D) const;



private:
	T X = 0;
	T Y = 0;
};

#include "Vector2D.inl"
