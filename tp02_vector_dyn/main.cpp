#include <iostream>
#include "vector_dyn.hpp"
using namespace std;
int main(){
    Vect<double> v(10);
    for (int i = 1; i <= 10; ++i)
        v(i) = i;
    cout << "v:\t" << v.norm() << endl;
    cout << "v:\t" << v << endl;
    SubVect<double> w(v, 1, 5, 2);
    cout << "w:\t" << w << endl;
    SubVect <double > z(v, 2, 3, 3);
    cout << "z:\t" << z << endl;
    SubVect <double > u(w, 1, 3, 2);
    cout << "u:\t" << u << endl;
    u.init(44);
    cout << "u:\t" << u << endl;
    cout << "v:\t" << v << endl;
    cout << "norme de v:\t" << v.norm() << endl;
    return 0;
}