#pragma once
template<typename T>
class Collection
{
public:
	Collection();
	T* getAllElements();
	T* getElementByIndex(int index);
	Collection addElement(T element);

	~Collection();
private:
	T* dynamicArray = nullptr;
	int size;
	int capacity
};

