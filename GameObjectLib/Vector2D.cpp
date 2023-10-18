#include "Vector2D.h"


template<typename T>
Vector2D< T>::Vector2D() : X(0), Y(0) {}

template<typename T>
Vector2D<T>::Vector2D(T X, T Y) : X(X), Y(Y) {}

template<typename T>
Vector2D<T> Vector2D<T>::add(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() + right.getX(), left.getY() + right.getY());
}



template<typename T>
Vector2D<T> Vector2D<T>::minus(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() - right.getX(), left.getY() - right.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::kVector2D(T k, const Vector2D vector) {
	return Vector2D(k * vector.getX(), k * vector.getY());
}




template<typename T>
double Vector2D<T>::magnitude() {
	return std::sqrt(X * X + Y * Y);
}

template<typename T>
Vector2D<T> Vector2D<T>::down() {
	return Vector2D((T)0, (T)-1);
}

template<typename T>
Vector2D<T> Vector2D<T>::up() {
	return Vector2D((T)0, (T)1);
}

template<typename T>
Vector2D<T> Vector2D<T>::left() {
	return Vector2D((T)-1, (T)0);
}

template<typename T>
Vector2D<T> Vector2D<T>::right() {
	return Vector2D((T)1, (T)0);
}

template<typename T>
Vector2D<T> Vector2D<T>::one() {
	return Vector2D((T)1, (T)1);
}

template<typename T>
Vector2D<T> Vector2D<T>::zero() {
	return Vector2D((T)0, (T)0);
}

template<typename T>
Vector2D<T> Vector2D<T>::negativeInfinity() {
	T negative_infinity = -std::numeric_limits<T>::infinity();
	return Vector2D(negative_infinity, negative_infinity);
}

template<typename T>
Vector2D<T> Vector2D<T>::positiveInfinity() {
	T positive_infinity = std::numeric_limits<T>::infinity();
	return Vector2D(positive_infinity, positive_infinity);
}

template<typename T>
Vector2D<T> Vector2D<T>::normalized() {
	T magnitude = magnitude();
	if (magnitude == 0) {
		return Vector2D(0, 0);
	}
	return Vector2D<T>(X / magnitude, Y / magnitude);
}

template<typename T>
void Vector2D<T>::normalize() {
	T magnitude = magnitude();
	if (magnitude == 0) {
		X = 0;
		Y = 0;
	}
	else {
		X = X / magnitude;
		Y = Y / magnitude;
	}
}

template<typename T>
void Vector2D<T>::set(T x, T y) {
	X = x;
	Y = y;
}

template<typename T>
void Vector2D<T>::toString() {
	GameLog::log(std::string("Vector : (" + X + "," + Y + ")"));
}

template<typename T>
bool Vector2D<T>::equals(Vector2D<T> vector2D) {
	return (vector2D.getX() == X && vector2D.getY() == Y);
}

/*==============================================================================================================================================*/
/*----------------------------------------------------------------STATIC METHODS----------------------------------------------------------------*/
/*==============================================================================================================================================*/

template<typename T>
T Vector2D<T>::angle(Vector2D<T> vector2D_1, Vector2D<T> vector2D_2) {
	T magnitude1 = vector2D_1.magnitude();
	T magnitude2 = vector2D_2.magnitude();
	T dot = Vector2D<T>::dot(vector2D_1, vector2D_2);
	T cosAngle = dot / (magnitude1 * magnitude2);

	return std::acos(cosAngle);
}

template<typename T>
T Vector2D<T>::dot(const Vector2D<T> left, const Vector2D<T> right) {
	return left.getX() * right.getX() + left.getY() * right.getY();
}

template<typename T>
Vector2D<T> Vector2D<T>::clampMagnitude(const Vector2D<T> vector, double maxMagnitude) {
	double currentMagnitude = vector.magnitude();

	if (currentMagnitude > maxMagnitude) {
		double scaleFactor = maxMagnitude / currentMagnitude;

		return Vector2D<T>(vector.getX() * scaleFactor, vector.getY() * scaleFactor);
	}
	return Vector2D<T>(vector.getX(), vector.getY());
}

template<typename T>
double Vector2D<T>::distance(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2) {
	Vector2D<T> vectorDistance = vector2D_1 - vector2D_2;
	double distance = vectorDistance.magnitude();
	return distance;
}

template<typename T>
Vector2D<T> Vector2D<T>::lerp(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2, double t) {
	if (t == 0) {
		return vector2D_1;
	}
	else if (t == 1) {
		return vector2D_2;
	}
	else if (t > 0 && t < 1) {
		T interpolatedX = (1 - t) * vector2D_1.getX() + t * vector2D_2.getX();
		T interpolatedY = (1 - t) * vector2D_1.getY() + t * vector2D_2.getY();
		return Vector2D<T>(interpolatedX, interpolatedY);
	}
	else {
		return Vector2D<T>::lerpUnclamped(vector2D_1, vector2D_2, t);
	}
}

template<typename T>
Vector2D<T> Vector2D<T>::lerpUnclamped(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2, double t) {
	T interpolatedX = (1 - t) * vector2D_1.getX() + t * vector2D_2.getX();
	T interpolatedY = (1 - t) * vector2D_1.getY() + t * vector2D_2.getY();

	return Vector2D<T>(interpolatedX, interpolatedY);
}



template<typename T>
Vector2D<T> Vector2D<T>::min(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2) {
	T minX = 0;
	T minY = 0;
	if (vector2D_1.getX() < vector2D_2.getX()) {
		minX = vector2D_2.getX();
	}
	else {
		minX = vector2D_1.getX();
	}
	if (vector2D_1.getY() < vector2D_2.getY()) {
		minY = vector2D_2.getY();
	}
	else {
		minY = vector2D_1.getY();
	}

	return Vector2D<T>(minX, minY);
}

template<typename T>
Vector2D<T> Vector2D<T>::max(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2) {
	T maxX = 0;
	T maxY = 0;
	if (vector2D_1.getX() > vector2D_2.getX()) {
		maxX = vector2D_2.getX();
	}
	else {
		maxX = vector2D_1.getX();
	}
	if (vector2D_1.getY() > vector2D_2.getY()) {
		maxY = vector2D_2.getY();
	}
	else {
		maxY = vector2D_1.getY();
	}

	return Vector2D<T>(maxX, maxY);
}

template<typename T>
Vector2D<T> Vector2D<T>::perpendicular(const Vector2D<T> vector2D) {
	return Vector(-vector2D.getY(), vector2D.getX());
}

template<typename T>
Vector2D<T> Vector2D<T>::reflect(const Vector2D<T> vector2D, const Vector2D<T> normal) {
	T dotProduct = Vector2D<T>::dot(vector2D, normal);
	T reflectX = vector2D.getX() - 2 * dotProduct * normal.getX();
	T reflectY = vector2D.getY() - 2 * dotProduct * normal.getY();

	return Vector(reflectX, reflectY);
}

template<typename T>
Vector2D<T> Vector2D<T>::scale(const Vector2D<T> vector2D_1, const Vector2D<T> vector2D_2) {
	return Vector(vector2D_1.getX() * vector2D_2.getX(), vector2D_1.getY() * vector2D_2.getY());
}

template<typename T>
float Vector2D<T>::signedAngle(const Vector2D<T> from, const Vector2D<T> to) {
	float angle = std::atan2(from.getY(), from.getX()) - atan2(to.getY(), to.getX());
	return angle;
}


/*==============================================================================================================================================*/
/*-------------------------------------------------------------------OPERATORS------------------------------------------------------------------*/
/*==============================================================================================================================================*/

template<typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& otherVector2D) const {
	return Vector2D(X + otherVector2D.getX(), Y + otherVector2D.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D<T>& vector2D) const {
	return Vector2D(X - vector2D.getX(), Y - vector2D.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-() const {
	return Vector2D(-X, -Y);
}


template<typename T>
Vector2D<T> Vector2D<T>::operator*(T k) const {
	return Vector2D(this->getX() * k, this->getY() * k);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator*(const Vector2D<T>& vector2D) const {
	return Vector2D(X * vector2D.getX(), Y * vector2D.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator/(T k) const {
	if (k != 0) return Vector2D(this->getX() / k, this->getY() / k);
	return this;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator/(const Vector2D<T>& vector2D) const {
	if (vector2D.getX() != 0 && vector2D.getY() != 0) return Vector2D(X / vector2D.getX(), Y / vector2D.getY());
	GameLog::error(std::string("Cannot divide by 0"));
	return Vector2D(0, 0);
}

template<typename T>
bool Vector2D<T>::operator==(const Vector2D& vector2D) const {
	return (X == vector2D.getX() && Y == vector2D.getY());
}