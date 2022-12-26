#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
    T* data;
    int capacity;
    int count;
    void swap(int posi, int posj);
    int ind(int index);
    void pushend(T element);
    void pushbegin(T element);
public:
    Array(int capacity);
    void print();
    Array(const Array& list);
    ~Array();
    T extractbegin();
    T extractend();
    T At(int pos);
    int Size();
    bool Empty();
    int* Data();
//    T& operator=(const T& arr);
    T& operator[](int pos);
    const T& operator[](int pos) const;
};


