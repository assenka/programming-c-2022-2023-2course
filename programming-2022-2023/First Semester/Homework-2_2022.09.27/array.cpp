#include <iostream>
#include "array.h"

using namespace std;

template <typename T>
Array<T>::Array(int count)
{
    this->capacity = count*2;
    this->count = count;
    this->data = new T[capacity];
    for(int i = 0; i < this->count; i++){
        this->data[i] = 0;
    }
}

template <typename T>
Array<T>::Array(const Array<T>& arr)
{
    this->capacity = arr.capacity;
    this->count = arr.count;
    this->data = new T[arr.count];
    for (int i = 0; i < arr.count; ++i)
    {
        this->data[i] = arr.data[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->data;
}


template <typename T>
void Array<T>::swap(int posi, int posj)
{
    T a = this->data[posi];
    this->data[posi] = this->data[posj];
    this->data[posj] = this->data[a];
    a = 0;
}

template <typename T>
int Array<T>::ind(int index)
{
    if (index < 0)
    {
        return 0;
    }
    if (index >= this->count)
    {
        return 0;
    }
    return index;
}


template <typename T>
void Array<T>::pushend(T element)
{
    if (this->count == this->capacity)
    {
        expand(this->count);
    }
    this->data[this->count] = element;
    this->count++;
}

template <typename T>
void Array<T>::pushbegin(T element)
{
    if(this->count == this->capacity)
    {
        expand(this->capacity);
    }
    T* newdata = new T[this->capacity];
    newdata[0] = element;
    for(int i = 1; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i-1];
    }
    delete[] data;
    this->data = newdata;
    this->count++;
}


template <typename T>
T Array<T>::extractend()
{
    this->capacity--;
    return this->data[this->capacity];
}

template<typename T>
T Array<T>::extractbegin()
{
    this->capacity--;
    T* newdata = new T[this->capacity];
    T extract = this->data[0];
    for(int i = 1; i < this->capacity; ++i)
    {
        newdata[i - 1] = this->data[i];
    }
    delete[] data;
    this->data = newdata;
    return extract;
}


template <typename T>
T& Array<T>::operator[](int pos)
{
    return data[ind(pos)];
}

//template <typename T>
//T& Array<T>::operator=(const T& arr)
//{
//    if (this == &arr) {
//        return *this;
//    }
//    if (arr.count > this->capacity) {
//        this->capacity = arr.capacity * 2;
//    }
//    for (int i = 0; i < arr.count; i++){
//        this->data[i] = arr[i];
//    }
//    return *this;
//}


template <typename T>
const T& Array<T>::operator[] (int pos) const
{
    return data[ind(pos)];
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < this->count; i++)
        cout << " " << *(data + i);
    cout << endl;
}


template <typename T>
T Array<T>::At(int pos)
{
    if (pos >= capacity || pos < 0) {
        return 0;
    }
    else {
        return this->data[pos];
    }
}

template <typename T>
int Array<T>::Size()
{
    return this->count;
}

template <typename T>
bool Array<T>::Empty()
{
    if (this->count == 0) {
        return 0;
    }
    return 1;
}

template <typename T>
int* Array<T>::Data()
{
    int* a = data;
    return a;
}
