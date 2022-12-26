#include "kvaternion.hpp"
using namespace std;

int main(){
    Kvaternion k1 (0, 0, 0, 0);
    cout << "k1 = " << k1 << endl;
    k1.set(1, 2, 3, 4);
    cout << "k1 = " << k1 << endl;
    Kvaternion k2 (0, 2, 0, 2);
    cout << "k1 + k2 = " << k1 + k2 << endl;
    cout << "im_z_k2 = " << k2.getIm_z() << endl;
    k1 += k2;
    cout << "k1 = " << k1 << endl;
    k1.setRe(8);
    cout << "k1 = " << k1 << endl;
    cout << "|k2| = " << k2.abs() << endl;
    cout << "conjugated k = " << k1.conjugate() << endl;

    return 0;
}

