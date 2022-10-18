#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
    T* data;
    int capacity;
	int count;
	void expand(int count = 1);
	void swap(int posi, int posj);
	int ind(int index);
public:
    Array(T arr[], int capacity);
    void print();
    void expand();
    Array(int capacity = 10);
	Array(const Array& list);
	~Array();
	void pushend(T element);
	void pushbegin(T element);
	void insert(T element, int position);
	T extractbegin();
	T extractend();
	T extract(int position);
    T& operator[](int pos);
};

