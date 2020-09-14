#include <iostream>
#include "interpol.hpp"
using namespace std;

int main(){
    int n = 10;
    InterpolLin h("points.dat", 7);
    for (double x = h.min()-1; x <= h.max()+1; x += 0.2)
        cout << x << "\t" << h(x) << endl;

}