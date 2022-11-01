#include <iostream>
#include "array.h"

using namespace std;

template <typename T>
Array<T>::Array(T arr[], int capacity)
{
    data = new T[capacity];
    for (int i = 0; i < this->capacity; i++)
        data[i] = arr[i];
}

template <typename T>
Array<T>::Array(const Array<T>& list)
{
    this->capacity = list.count;
    this->count = list.count;
    this->data = new T[list.count];
    for (int i = 0; i < list.count; ++i)
    {
        this->data[i] = list.data[i];
    }
}

template <typename T>
void Array<T>::expand(int count)
{
    T* newdata = new T[count + this->capacity];
    for (int i = 0; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newdata;
    this->capacity += count;
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
        pushbegin(0);
        return 0;
    }
    if (index >= this->count)
    {
        pushend(0);
        return this->count - 1;
    }
    return index;
}

template <typename T>
Array<T>::Array(int capacity)
{
    this->capacity = capacity;
    this->count = 0;
    this->data = new T[capacity];
}

template <typename T>
Array<T>::~Array()
{
    this->count = 0;
    this->capacity = 0;
    for (int i = 0; i < this->capacity; ++i)
    {
        this->data[i] = 0;
    }
    delete[] this->data;
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
void Array<T>::insert(T element, int position)
{
    if(this->count == this->capacity)
    {
        expand(this->capacity);
    }
    T* newdata = new T[this->capacity];
    for(int i = 0; i < position; ++i)
    {
        newdata[i] = this->data[i];
    }
    newdata[position] = element;
    for(int i = position + 1; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i - 1];
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
T Array<T>::extract(int position)
{
    this->count--;
    if(position >= this->capacity)
    {
        pushend(0);
    }
    else if(position < 0)
    {
        pushbegin(0);
    }
    T* newdata = new T[this->count];
    for(int i = 0; i < position; ++i)
    {
        newdata[i] = this->data[i];
    }
    T extract = this->data[position];
    for(int i = position; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i + 1];
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

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < this->count; i++)
        cout << " " << *(data + i);
    cout << endl;
}
