#include "Container.h"

template<typename T>
Container<T>::Container() : size(0), capacity(1) {}

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
Container<T> Container<T>::addElement(T element) {
	if (size >= capacity) {
		capacity *= 2;
		T* newArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			newArray[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
	dynamicArray[size] = element;
	size++;
	return this;
}



template<typename T>
Container<T>::~Container() {
	delete[] dynamicArray;
}
