#pragma once

/*==============================================================================================================================================*/
/*-----------------------------------------------------------------CONSTRUCTORS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

template<typename T>
Container<T>::Container() : size(0), capacity(1), dynamicArray(new T[capacity]) {}

template<typename T>
Container<T>::Container(int size, int capacity, T* dynamicArray) : size(size), capacity(capacity), dynamicArray(dynamicArray) {}


/*==============================================================================================================================================*/
/*-----------------------------------------------------------------CONSTRUCTORS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

//OPERATOR =

template<typename T>
Container<T> Container<T>::operator=(const Container<T>& otherContainer) {
	size = otherContainer.getSize();
	capacity = otherContainer.getCapacity();
	dynamicArray = otherContainer.getArray();
}

//OPERATOR ==

template<typename T>
//template <typename U = T, std::enable_if_t<decltype(std::declval<T>() == std::declval<T>())>> : std::true_type{}; >
bool Container<T>::operator==(const Container<T>& otherContainer) {
	if (size == otherContainer.getSize()) {
		for (int i = 0; i < size; i++) {
			if (dynamicArray[i] != otherContainer.at(i)) return false;
		}
	}
	else {
		return false;
	}
	return true;
}

/*==============================================================================================================================================*/
/*--------------------------------------------------------------------HOME MADE-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

//GET ARRAY

template<typename T>
T* Container<T>::getArray() {
	return dynamicArray;
}

//SET ARRAY

template<typename T>
void Container<T>::setArray(T* array) {
	dynamicArray = array;
}

//GET ELEMENT BY INDEX

template<typename T>
T Container<T>::getElementByIndex(int index) {
	if (index >= 0 && index < size) {
		return dynamicArray[index];
	}
	Error::RaiseOutOfRangeError(std::string("Index out of range"));
	return NULL;
}

//SHOW ELEMENTS

template<typename T>
void Container<T>::showElements() {
	for (int i = 0; i < size; i++) {
		std::cout << i << "." << dynamicArray[i] << std::endl;
	}
}

//FIND INDEX BY ELEMENT

template<typename T>
int Container<T>::findIndexByElement(T findElement) {
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] == findElement) return i;
	}
	GameLog::error(std::string("No element : " + findElement));
	return -1;
}

/*==============================================================================================================================================*/
/*--------------------------------------------------------------------ITERATORS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/


//BEGIN

template<typename T>
typename Container<T>::Iterator Container<T>::begin() {
	return Iterator(dynamicArray);
}

//END

template<typename T>
typename Container<T>::Iterator Container<T>::end() {
	return Iterator(dynamicArray + size);
}

//RBEGIN

template<typename T>
typename Container<T>::Iterator Container<T>::rbegin() {
	return Iterator(dynamicArray + size - 1);
}

//REND

template<typename T>
typename Container<T>::Iterator Container<T>::rend() {
	T* array = dynamicArray;
	return Iterator(dynamicArray - 1);
}

//CBEGIN

template<typename T>
typename Container<T>::Iterator Container<T>::cbegin() const {
	return Iterator(dynamicArray);
}

//CEND

template<typename T>
typename Container<T>::Iterator Container<T>::cend() const {
	return Iterator(dynamicArray + size);
}

//CRBEGIN

template<typename T>
typename Container<T>::Iterator Container<T>::crbegin() const {
	const T* array = dynamicArray;
	return Iterator(dynamicArray + size - 1);
}

//CREND

template<typename T>
typename Container<T>::Iterator Container<T>::crend() const {
	return Iterator(dynamicArray - 1);
}

/*==============================================================================================================================================*/
/*-------------------------------------------------------------------CAPACITY-------------------------------------------------------------------*/
/*==============================================================================================================================================*/


//GET SIZE

template<typename T>
int Container<T>::getSize() {
	return size;
}

//GET CAPACITY

template<typename T>
int Container<T>::getCapacity() {
	return capacity;
}

//GET LEFT CAPACITY

template<typename T>
int Container<T>::getLeftCapacity() {
	return capacity - size;
}

//RESIZES

template<typename T>
void Container<T>::resize(int newSize) {
	if (newSize > capacity) {
		reserve(newSize);
	}
	for (int i = size; i < newSize; i++) {
		dynamicArray[i] = (T)0;
	}
}

template<typename T>
void Container<T>::resize(int newSize, T element) {
	if (newSize > capacity) {
		reserve(newSize);
	}
	for (int i = size; i < newSize; i++) {
		dynamicArray[i] = element;
	}
}


//EMPTY

template<typename T>
bool Container<T>::empty() {
	return size == 0;
}

//RESERVE

template<typename T>
void Container<T>::reserve(int newCapacity) {
	if (newCapacity > capacity) {
		T* newArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			newArray[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
		capacity = newCapacity;
	}
}

//SHRINK TO FIT

template<typename T>
void Container<T>::shrinkToFit() {
	if (size > 0) {
		capacity = size;
		resize(capacity);
	}
}


/*==============================================================================================================================================*/
/*----------------------------------------------------------------ELEMENT ACCESS----------------------------------------------------------------*/
/*==============================================================================================================================================*/


//OPERATOR []
template<typename T>
T Container<T>::operator[](int index) {
	return *(dynamicArray + index);
}

//AT

template<typename T>
T Container<T>::at(int index) {
	return dynamicArray[index];
}

//FRONT

template<typename T>
T Container<T>::front() {
	return *(dynamicArray);
}

//BACK
template<typename T>
T Container<T>::back() {
	return *(dynamicArray + size);
}

//DATA

template<typename T>
T Container<T>::data() {
	T* dataPointer = dynamicArray;
	return dataPointer;
}


/*==============================================================================================================================================*/
/*--------------------------------------------------------------------MODIFIERS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/


//ASSIGNS

/*
*/
template<typename T>
void Container<T>::assign(int size, T value) {
	if (size != 0) {
		empty();
	}
	resize(size, T);
}

template<typename T>
void Container<T>::assign(Container<T> container) {
	size = container.getSize();
	capacity = container.getCapacity();
	delete[] dynamicArray;
	dynamicArray = container.getAllElements();
}

template<typename T>
void Container<T>::assign(Iterator first, Iterator last) {
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
}

//PUSH BACK

template<typename T>
void Container<T>::push_back(T element) {
	if (size >= capacity) {
		capacity *= 2;
		reserve(capacity);
	}
	dynamicArray[size] = element;
	size++;
}

//POP BACK

template<typename T>
void Container<T>::pop_back() {
	if (size > 0) {
		size--;
		if (size < capacity / 2) {
			capacity /= 2;
		}
		reserve(capacity);
	}
}

//INSERTS

template<typename T>
void Container<T>::insert(int position, T value) {
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
}

template<typename T>
void Container<T>::insert(int position, T value, int number) {
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
}

template<typename T>
void Container<T>::insert(int position, Container<T> container) {
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
}

template<typename T>
void Container<T>::insert(int position, Iterator first, Iterator last) {
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
}

//CLEAR

template<typename T>
void Container<T>::clear() {
	size = 0;
	delete[] dynamicArray;
	dynamicArray = new T[capacity];
}

//ERASES

template<typename T>
void Container<T>::erase(int position) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		int index = 0;
		size--;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				index++;
			}
			newArray[i] = dynamicArray[i + index];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

template<typename T>
void Container<T>::erase(int from, int to) {
	if (from >= size || to >= size || from < to) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		int index = 0;
		size -= (to - from + 1);
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i >= from && i <= to) {
				index = (to - from + 1);
			}
			newArray[i] = dynamicArray[i + index];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

//SWAP

template<typename T>
void Container<T>::swap(Container<T> otherContainer) {
	/*Temporaire*/
	int tempSize = otherContainer.getSize();
	int tempCapacity = otherContainer.getCapacity();
	T* tempArray = otherContainer.getArray();

	/*Modify otherContainer*/
	otherContainer.setArray(dynamicArray);
	otherContainer.reserve(capacity);
	otherContainer.resize(size);

	/*Modify actualContainer*/
	dynamicArray = tempArray;
	size = tempSize;
	capacity = tempCapacity;
}

//EMPLACES

template<typename T>
typename Container<T>::Iterator Container<T>::emplace(Iterator iterator, T value) {
	size++;
	if (size > capacity) {
		reserve(size);
	}
	for (Iterator it = end(); it != iterator; --it) {
		*(dynamicArray + 1) = *it;
	}
	*(dynamicArray + iterator) = *iterator;

	return iterator;
}

template<typename T>
void Container<T>::emplace_back(T value) {
	size++;
	if (size > capacity) {
		reserve(size);
	}
	Iterator end = end();
	*(dynamicArray + end) = *end;
}


/*==============================================================================================================================================*/
/*-------------------------------------------------------------------DESTRUCTOR-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

//DESTRUCTOR

template<typename T>
Container<T>::~Container() {
	delete[] dynamicArray;
}