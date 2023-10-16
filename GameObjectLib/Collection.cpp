#include "Collection.h"

template<typename T>
Collection<T>::Collection() : size(0), capacity(1) {}

template<typename T>
T* Collection<T>::getAllElements() {
	return dynamicArray;
}

template<typename T>
T Collection<T>::getElementByIndex(int index) {
	if (index >= 0 && index < taille) {
		return dynamicArray[index];
	}
	return NULL;
}

template<typename T>
Collection<T> Collection<T>::addElement(T element) {
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
	return this*;
}



template<typename T>
Collection<T>::~Collection() {
	delete[] dynamicArray;
}
