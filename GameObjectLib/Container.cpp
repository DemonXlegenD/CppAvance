#include "Container.h"

/*
CONSTRUCTORS
*/

template<typename T>
Container<T>::Container() : size(0), capacity(1), dynamicArray(new T[capacity]) {}

template<typename T>
Container<T>::Container(int size, int capacity, T* dynamicArray) : size(size), capacity(capacity), dynamicArray(dynamicArray) {}



/*==============================================================================================================================================*/
/*--------------------------------------------------------------------ITERATORS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

template<typename T>
typename Container<T>::Iterator Container<T>::begin() {
	return Iterator(dynamicArray);
}

template<typename T>
typename Container<T>::Iterator Container<T>::end() {
	return Iterator(dynamicArray + size);
}

template<typename T>
typename Container<T>::Iterator Container<T>::rbegin() {
	return Iterator(dynamicArray + size - 1);
}

template<typename T>
typename Container<T>::Iterator Container<T>::rend() {
	T* array = dynamicArray;
	return Iterator(dynamicArray - 1);
}


template<typename T>
typename Container<T>::Iterator Container<T>::cbegin() const {
	return Iterator(dynamicArray);
}

template<typename T>
typename Container<T>::Iterator Container<T>::cend() const {
	return Iterator(dynamicArray + size);
}

template<typename T>
typename Container<T>::Iterator Container<T>::crbegin() const {
	const T* array = dynamicArray;
	return Iterator(dynamicArray + size - 1);
}

template<typename T>
typename Container<T>::Iterator Container<T>::crend() const {
	return Iterator(dynamicArray - 1);
}

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
Container<T> Container<T>::clear() {
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

/*==============================================================================================================================================*/
/*----------------------------------------------------------------ELEMENT ACCESS----------------------------------------------------------------*/
/*==============================================================================================================================================*/
template<typename T>
T Container<T>::operator[](int index) {
	return *(dynamicArray + index);
}

template<typename T>
T Container<T>::at(int index) {
	return dynamicArray[index];
}

template<typename T>
T Container<T>::front() {
	return *(dynamicArray);
}

template<typename T>
T Container<T>::back() {
	return *(dynamicArray + size);
}

template<typename T>
T Container<T>::data() {
	T* dataPointer = dynamicArray;
	return dataPointer;
}

/*==============================================================================================================================================*/
/*--------------------------------------------------------------------MODIFIERS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

template<typename T>
Container<T> Container<T>::assign(int size, T value) {
	if (size != 0) {
		empty();
	}
	resize(size, T);

	return this;
}

template<typename T>
Container<T> Container<T>::assign(Container<T> container) {
	size = container.getSize();
	capacity = container.getCapacity();
	delete[] dynamicArray;
	dynamicArray = container.getAllElements();
}

template<typename T>
Container<T> Container<T>::assign(Iterator first, Iterator last) {
	int newSize = 0;
	for (Iterator it = first; it != last; ++it) {
		++newSize;
	}
	if (newSize > capacity) {
		reserve(newSize);
	}
	size = 0;
	for (Iterator it = first; it != last; ++it) {
		dynamicArray[size] = *it;
		++size;
	}

	return this;
}

template<typename T>
Container<T> Container<T>::insert(int position, T value) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		size++;
		int index = 0;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				newArray[i] = value;
				index++;
			}
			else {
				newArray[i] = dynamicArray[i - index];
			}

		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}

	return this;
}

template<typename T>
Container<T> Container<T>::insert(int position, T value, int number) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		size += number;
		int index = 0;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				newArray[i] = value;
				index++;
			}
			else {
				newArray[i] = dynamicArray[i - index];
			}
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}

	return this;
}

template<typename T>
Container<T> Container<T>::insert(int position, Container<T> container) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		size += container.getSize();
		int index = 0;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				newArray[i] = container.at(index);
				index++;
			}
			else {
				newArray[i] = dynamicArray[i - index];
			}
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}

	return this;
}

template<typename T>
Container<T> Container<T>::insert(int position, Iterator first, Iterator last) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		int numElementsToInsert = 0;
		for (Iterator it = first; it != last; ++it) {
			++numElementsToInsert;
		}

		if (size + numElementsToInsert > capacity) {
			reserve(size + numElementsToInsert);
		}

		for (Iterator it = end(); it != position; --it) {
			*(dynamicArray + numElementsToInsert) = *it;
		}
		int index = 0;
		for (Iterator it = first; it != last; ++it) {
			*(dynamicArray + index) = *it;
			index++;
			++size;
		}
	}

	return this;
}