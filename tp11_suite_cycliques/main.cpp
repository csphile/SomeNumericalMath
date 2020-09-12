#include "suite.hpp"

int main(){
    Lucas XL({3.47, 0.5});
    for(int i=0; i<=5; ++i){
        cout << XL << endl; 
        ++XL;
    }

    // cout << XL.cycle() << endl;

    Logistique X(3.47, 0.5);
    for(int i=0; i<=5; ++i){
        cout << X << endl; 
        ++X;
    }
    X.reinit();
    cout << X.cycle() << endl;

    Jeu j(6);
    for(int i=0; i<=5; ++i){
        cout << i << ": " << j << endl; 
        ++j;
    }
    cout << j.cycle() << endl;
    Jeu j1(8), j2(100);
    cout << j1.cycle() << endl;
    cout << j2.cycle() << endl;
    return 0;
}