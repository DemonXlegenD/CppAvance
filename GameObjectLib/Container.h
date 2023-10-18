#pragma once
#include <iostream>
#include "Game/GameLog.h"
#include "Error.h"

template<typename T>
class Container
{
public:
	Container();
	Container(int size, int capacity, T* dynamicArray);

	T* getAllElements();
	T getElementByIndex(int index);

	Container<T> showElements();


	/*ITERATORS*/

	class Iterator {
	private:
		T* ptr;

	public:
		Iterator(T* p) : ptr(p) {}

		T& operator*() {
			return *ptr;
		}

		Iterator& operator++() {
			++ptr;
			return *this;
		}

		Iterator& operator--() {
			--ptr;
			return *this;
		}

		bool operator==(const Iterator& other) const {
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other) const {
			return ptr != other.ptr;
		}
	};



	Iterator begin();
	Iterator end();
	Iterator rbegin();
	Iterator rend();
	Iterator cbegin() const;
	Iterator cend() const;
	Iterator crbegin() const;
	Iterator crend() const;

	int findIndexByElement(T element);

	/*CAPACITY*/
	int getSize();
	int getCapacity();
	int getActualCapacity();
	Container<T> resize(int size);
	Container<T> resize(int newSize, T element);
	Container<T> empty();
	Container<T> clear();
	Container<T> reserve(int capacity);
	Container<T> shrinkToFit();

	/*ELEMENT ACCESS*/
	T operator[](int index);
	T at(int index);
	T front();
	T back();
	T data();
	bool isEmpty();

	/*MODIFIERS*/
	Container<T> assign(int size, T value);
	Container<T> assign(Container<T> container);
	Container<T> assign(Iterator first, Iterator last);
	Container<T> insert(int position, T value);
	Container<T> insert(int position, T value, int number);
	Container<T> insert(int position, Container<T> container);
	Container<T> insert(int position, Iterator first, Iterator last);
	Container<T> push(T element);
	Container<T> pop();


	~Container();
private:
	int size = 0;
	int capacity = 1;
	T* dynamicArray = new T[size];
};

