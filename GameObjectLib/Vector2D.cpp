#include "Vector2D.h"


template<typename T>
inline Vector2D< T>::Vector2D(){}

template<typename T>
inline Vector2D<T>::Vector2D(T X, T Y) : X(X), Y(Y) {}

template<typename T>
Vector2D<T> Vector2D<T>::add(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() + right.getX(), left.getY() + right.getY());
}

template<typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& left, const Vector2D<T>& right) {
	return Vector2D(left.getY() + right.getX(), left.getY() + right.getY());
}