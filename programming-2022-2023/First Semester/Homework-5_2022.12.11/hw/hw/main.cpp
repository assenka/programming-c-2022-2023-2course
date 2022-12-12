#include <iostream>

template <typename T>
class Vector{
private:
    int count;
    int capacity;
    T *data;
public:
    Vector(){this->capacity = 0;  this->count = 0;}
    
    Vector(int count){this->capacity = 2 * count; this->count = capacity;}
    
    Vector(const Vector& v){
        capacity = v.count * 2;
        this->data = new T[v.count * 2];
        for (int i = 0 ; i < v.count; i++){
            data[i] = v[i];
        }
    }
    
    ~Vector(){};
    
    int size(){
        return this->count;
    }
    
    void expand(int n){
        T* newdata = new T[2 * n];
        for (int i = 0; i < this->count; i++){
            newdata[i] = this->data[i];
        }
        this->data = newdata;
        this->capacity = 2 * n;
    }
    
    void PushBack(T element){
        if (this->count == this->capacity){
            expand(this->capacity);
        };
        this->data[this->count] = element;
        this->count++;
    }
    
    void PushFront(T elem){
        if (this->count == this->capacity){
            expand(this->capacity);
        }
        this->data[0] = elem;
        for (int i = 1; i < this->count; i++){
            this->data[i - 1] = data[i];
        };
        this->count++;
    }
    
    int MaxSize(){
        return this->capacity;
    }
    
    void clear(){
        this->count = 0;
        this->data = nullptr;
    }
    
    void insert(T elem, int position){
        if (this->count == this->capacity){
            expand(this->capacity);
        }
        for (int i = this; i > position; i--){
            this->data[i] = this->data[i - 1];
        };
        this->data[position] = elem;
    }
    
    T& operator[](int position){
        return this->data[position];
    }
};

int main(){
    Vector<int> a;
    
    for (int i = 0; i < 15; ++i){
        a.PushBack(i*i);
    }
    
    a.PushFront(88);
    a.PushBack(88);
    
    for (int i = 0; i < 17; i++){
        std::cout << a[i] << " ";
    }
    
    a.clear();
    
    std::cout << a.size() << " ";
        
    return 0;
}

