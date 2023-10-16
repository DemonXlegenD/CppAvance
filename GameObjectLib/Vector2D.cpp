#include "Vector2D.h"


template<typename T>
inline Vector2D< T>::Vector2D(){}

template<typename T>
inline Vector2D<T>::Vector2D(T X, T Y) : X(X), Y(Y) {}

template<typename T>
Vector2D<T> Vector2D<T>::add(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() + right.getX(), left.getY() + right.getY());
}

//template<typename T>
//Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& left, const Vector2D<T>& right) {
//	return Vector2D(left.getY() + right.getX(), left.getY() + right.getY());
//}

template<typename T>
Vector2D<T> Vector2D<T>::minus(const Vector2D left, const Vector2D right) {
	return Vector2D(left.getX() - right.getX(), left.getY() - right.getY());
}

//template<typename T>
//Vector2D<T> Vector2D<T>::operator-(const Vector2D<T>& left, const Vector2D<T>& right) {
//	return Vector2D(left.getY() + right.getX(), left.getY() + right.getY());
//}

template<typename T>
T Vector2D<T>::kVector2D(T k, const Vector2D vector) {
	return Vector2D(k * vector.getX(), k * vector.getY());
}

template<typename T>
T Vector2D<T>::scalarProduct(const Vector2D left, const Vector2D right) {
	return left.getX() * right.getX() + left.getY() * right.getY();
}

