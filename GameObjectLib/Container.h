#pragma once
#include <iostream>
#include "Game/GameLog.h"

template<typename T>
class Container
{
public:
	Container();
	Container(int size, int capacity, T* dynamicArray);
	int getSize();
	int getCapacity();
	int getActualCapacity();

	T* getAllElements();
	T getElementByIndex(int index);

	Container<T> resize(int size);
	Container<T> empty();
	Container<T> showElements();

	int findIndexByElement(T element);

	Container<T> push(T element);
	Container<T> pop();

	bool isEmpty();

	~Container();
private:
	int size = 0;
	int capacity = 1;
	T* dynamicArray = new T[size];
};

