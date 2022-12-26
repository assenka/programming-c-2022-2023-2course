#include <iostream>

template <typename T>
class Vector{
private:
    int count;
    int capacity;
    T *data;
public:
    Vector(){this->capacity = 0;  this->count = 0; this->data = new T[this->count * 2];}
    
    Vector(int count){this->capacity = 2 * count; this->count = count; this-> data = new T[this->count * 2];}
    
    Vector(const Vector& v){
        this->capacity = v.count * 2;
        data = new T[v.count * 2];
        for (int i = 0 ; i < v.count; i++){
            data[i] = v[i];
        }
    }
    
    ~Vector(){
        delete[] this->data;
    };
    
    void expand(int n){
        T* newdata = new T[2 * n];
        for (int i = 0; i < this->count; ++i){
            newdata[i] = this->data[i];
        }
        delete[] this->data;
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
        this->count++;
        for (int i = this->count; i > 0; --i){
            this->data[i] = data[i - 1];
        };
        this->data[0] = elem;
    }
    
    int Size(){
        return this->count;
    }
    
    void clear(){
        this->count = 0;
        this->data = nullptr;
    }
    
    void insert (T elem, int position) {
        if (this->count == this->capacity){
            expand(this->capacity);
        }
        for (int i = this->capacity; i > position; i--){
            this->data[i] = this->data[i - 1];
        };
        this->data[position] = elem;
    }
    
    T& operator[] (int pos) {
        return this->data[pos];
    }
    
    const T& operator[] (int pos) const {
        return this->data[pos];
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector& v){
        stream << "{";
        for (int i = 0; i < v.count; i++) {
            stream << v.data[i] << ", ";
        }
        stream << "}";
        return stream;
    }
};


int main(){
    Vector<int> a;
    
    for (int i = 0; i < 15; ++i){
        a.PushBack(i*i);
    }
    
    std::cout << a << std::endl;
    
    a.PushFront(88);
    a.PushBack(88);
    a.insert(999, 5);
    
    std::cout << a << std::endl;
    
    std::cout << "size: " << a.Size() << std::endl;
    
    a.clear();
    
    std::cout << a << std::endl;
    
//    const Vector<int> b(10);
//    b[0] = 1;
        
    return 0;
}
