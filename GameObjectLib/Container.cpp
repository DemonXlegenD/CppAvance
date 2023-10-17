#include "Container.h"

/*
CONSTRUCTORS
*/

template<typename T>
Container<T>::Container() : size(0), capacity(1), dynamicArray(new int[capacity]) {}

template<typename T>
Container<T>::Container(int size, int capacity, T* dynamicArray) : size(size), capacity(capacity), dynamicArray(dynamicArray) {}

/*
METHODS RETURN INT
*/

template<typename T>
int Container<T>::getSize() {
	return size;
}

template<typename T>
int Container<T>::getCapacity() {
	return capacity;
}

template<typename T>
int Container<T>::getActualCapacity() {
	return capacity - size;
}

template<typename T>
T* Container<T>::getAllElements() {
	return dynamicArray;
}

template<typename T>
T Container<T>::getElementByIndex(int index) {
	if (index >= 0 && index < size) {
		return dynamicArray[index];
	}
	std::cerr << "Index invalide." << std::endl;
	return nullptr;
}

template<typename T>
Container<T> Container<T>::resize(int newSize) {
	if (newSize > capacity) {
		reserve(newSize);
	}
	for (int i = size; i < newSize; i++) {
		dynamicArray[i] = T();
	}

	return this;
}

template<typename T>
Container<T> Container<T>::resize(int newSize, T element) {
	if (newSize > capacity) {
		reserve(newSize);
	}
	for (int i = size; i < newSize; i++) {
		dynamicArray[i] = element;
	}

	return this;
}



template<typename T>
Container<T> Container<T>::empty() {
	size = 0;
	capacity = 0;
	reserve(capacity + 1);

	return this;
}

template<typename T>
Container<T> Container<T>::showElements() {
	for (int i = 0; i < size; i++) {
		std::cout << i << "." << dynamicArray[i] << std::endl;
	}
	return this;
}

template<typename T>
Container<T> Container<T>::push(T element) {
	if (size >= capacity) {
		capacity *= 2;
		reserve(capacity);
	}
	dynamicArray[size] = element;
	size++;
	return this;
}

template<typename T>
Container<T> Container<T>::pop() {
	if (size > 0) {
		size--;
		if (size < capacity / 2) {
			capacity /= 2;
		}
		reserve(capacity);
	}

	return this;
}

template<typename T>
Container<T> Container<T>::reserve(int newCapacity) {
	if (newCapacity > capacity) {
		T* newArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			newArray[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
		capacity = newCapacity;
	}

	return this;
}

template<typename T>
Container<T> Container<T>::shrinkToFit() {
	if (size > 0) {
		capacity = size;
		resize(capacity);
	}

	return this;
}

template<typename T>
int Container<T>::findIndexByElement(T findElement) {
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] == findElement) return i;
	}
	GameLog::error(std::string("No element : " + findElement));
	return -1;
}

template<typename T>
bool Container<T>::isEmpty() {
	return size == 0;
}

template<typename T>
Container<T>::~Container() {
	delete[] dynamicArray;
}

