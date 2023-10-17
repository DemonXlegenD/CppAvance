#include "Vector2D.h"


template<typename T>
Vector2D< T>::Vector2D(): X(0), Y(0){}

template<typename T>
Vector2D<T>::Vector2D(T X, T Y) : X(X), Y(Y) {}

template<typename T>
Vector2D<T> Vector2D<T>::add(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() + right.getX(), left.getY() + right.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& otherVector2D) const{
	return Vector2D(this->getX() + otherVector2D.getX(), this->getY() + otherVector2D.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::minus(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() - right.getX(), left.getY() - right.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D<T>& otherVector2D) const {
	return Vector2D(this->getX() - otherVector2D.getX(), this->getY() - otherVector2D.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::kVector2D(T k, const Vector2D vector) {
	return Vector2D(k * vector.getX(), k * vector.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator*(T k) const {
	return Vector2D(this->getX() * k, this->getY() * k);
}

template<typename T>
T Vector2D<T>::scalarProduct(const Vector2D left, const Vector2D right) {
	return left.getX() * right.getX() + left.getY() * right.getY();
}

