#include "array.cpp"
#include <iostream>

using namespace std;

int main()
{
    Array <int> a(20);
    a[0] = 1;
    a[1] = 2;
    cout << a[28] << endl;
    a.print();
    cout << "Size: " << a.Size() << endl;
    cout << a.Empty() << endl;
    cout << a.Data() << endl;
    *a.Data() = 33;
    a.print();
//    const Array<int> b(10);
//    b[0] = 44;
//    b[0] = 6;
    return 0;
}

