#pragma once
#include <iostream>

template<typename T>
class Container
{
public:
	Container();
	T* getAllElements();
	T getElementByIndex(int index);
	Container addElement(T element);

	~Container();
private:
	T* dynamicArray = nullptr;
	int size;
	int capacity;
};

