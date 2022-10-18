#include "array.cpp"

using namespace std;

int main()
{
    Array <int> a(20);
    a.pushbegin(3);
    a.print();
    a.pushend(8);
    a.print();
    a.extractbegin();
    a.print();
    a.extractend();
    a.print();
    a.insert(1, 2);
    a.print();
    cout << a[0] << endl;
    a.extract(2);
    a.print();
    return 0;
}
