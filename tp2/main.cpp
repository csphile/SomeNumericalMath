#include <iostream>
#include <math.h>
// #include "vect_dyn.hpp"
using namespace std;
template <typename T> class AbsVect{
protected:
    int n;
    T* data;
public:
    AbsVect(int n_): n(n_){data = new T[n_];}
    int taille(){return n;}
    virtual T operator()(unsigned i) const = 0;
    virtual T & operator()(unsigned i) = 0; 
    void remplit(T& toreplace, const T& t){
        // cout << " called " << endl;
        toreplace = t;
    }
    T norm(){
        T ans;
        for (int i = 1; i <= n; i++){
            ans += this -> operator()(i) * this -> operator()(i);
        }
        return sqrt(ans);
    }
    friend ostream& operator<<(ostream& os, const AbsVect<T>& absVec){
        for (int i = 1; i <= absVec.n; i++){
            os << absVec(i) << " ";
        }
        return os;
    }
    ~AbsVect(){delete[] this -> data;}
};

template<typename T> class Vect: public AbsVect<T>{
public:
    Vect(int n_): AbsVect<T>(n_) {}
    T operator()(unsigned i) const{
        return this -> data[i - 1];
    }
    T& operator ()(unsigned i){
        // cout << "called operator &" << endl; 
        return this -> data[i - 1];
    }
};

template<class T> class SubVect: public AbsVect<T>{
public:
    SubVect(const AbsVect<T>& other, int beg, int n_, int gap): AbsVect<T>(n_) {
        int i = beg;
        for (int ind = 1; ind <= n_; ind++){
            this -> operator()(ind) = other(i);
            i += gap;
        }
    }
    T operator()(unsigned i) const{
        return this -> data[i - 1];
    }
    T& operator()(unsigned i){
        return this -> data[i - 1];
    }

    void init(const T& t){
        for (int i = 1; i <= this -> taille(); i++) this -> remplit(this -> operator()(i), t);
    }
};

using namespace std;


int main(){
    Vect<double> v(10);
    for (int i = 1; i <= 10; ++i)
        v(i) = i;
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