#pragma once
#include <iostream>

template<typename T>
class Container
{
public:
	Container();

	int getSize();
	int getCapacity();
	int getActualCapacity();

	T* getAllElements();
	T getElementByIndex(int index);

	Container<T> resize(int size);
	Container<T> empty();
	Container<T> showElements();

	int findIndexByElement(T element);

	Container push(T element);
	Container pop(T element);

	bool isEmpty();

	~Container();
private:
	T* dynamicArray = nullptr;
	int size;
	int capacity;
};

