#include <iostream>
#include <malloc.h>

using namespace std;

class Printer {
    int x = 1;
    int y = 2;
    int z = 3;

    void PrintX () {
        cout << this->x;
    };
    void PrintY () {
        cout << this->y;
    };
    void PrintZ () {
        cout << this->z;
    };
};

struct MinMemoryCheck {
    long long a;
    double b;
    unsigned int c;
    float d;
    int e;
    short f;
    char g;
    bool h;
};

struct MaxMemoryCheck {
    char a;
    long double b;
    bool c;
    long long d;
    short e;
    long double f;
    unsigned char g;
    long int h;
};

int main() {

    cout << sizeof(MinMemoryCheck) << ' ' << sizeof(MaxMemoryCheck) << endl;

    Printer printer;

    int* a = (int*)(&printer);
    cout << *a << endl;
    *a = 10;
    cout << *a << endl;
    a++;
    *a = 20;
    cout << *a << endl;
    a++;
    *a = 30;
    cout << *a << endl;


    return EXIT_SUCCESS;
};
