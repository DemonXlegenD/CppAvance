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
	Container<T> resize(int newSize, T element);
	Container<T> reserve(int capacity);
	Container<T> empty();
	Container<T> showElements();
	Container<T> push(T element);
	Container<T> pop();
	Container<T> shrinkToFit();

	int findIndexByElement(T element);



	bool isEmpty();

	~Container();
private:
	int size = 0;
	int capacity = 1;
	T* dynamicArray = new T[size];
};

