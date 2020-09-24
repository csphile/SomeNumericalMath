#ifndef VECT_HPP
#define VECT_HPP
#include<iostream>
#include <math.h>

using namespace std;

template <typename T> class AbsVect{
protected:
    int n;
    T* data;
public:
    explicit AbsVect(int n_): n(n_){
        data = new T[n_ + 1];
    }
    int taille(){return n;}
    virtual T operator()(unsigned i) const = 0;
    virtual T & operator()(unsigned i) = 0;
    void remplit(T& toreplace, const T& t){
        // cout << " called " << endl;
        toreplace = t;
    }
    T norm(){
        T ans = 0;
        for (int i = 1; i <= n; i++){
            ans += this -> operator()(i) * this -> operator()(i);
        }
        return sqrt(ans);
    }
    friend ostream& operator<<(ostream& os, const AbsVect<T>& absVec){
        for (int i = 1; i <= absVec.n; i++){
            os << absVec.operator()(i) << " ";
        }
        return os;
    }

    ~AbsVect() {delete[] data;}
};

template<typename T> class Vect: public AbsVect<T>{
public:
    Vect(int n_): AbsVect<T>(n_) {}

    T operator()(unsigned i) const{
        return this -> data[i];
    }

    T& operator ()(unsigned i){
        // cout << "called operator &" << endl;
        return this -> data[i];
    }
};

template<class T> class SubVect: public AbsVect<T>{
private:
    int beg, gap;
    AbsVect<T>* oth;
public:
    SubVect(AbsVect<T>& other, int beg_, int n_, int gap_): AbsVect<T>(n_), beg(beg_), gap(gap_) {
        oth = &other;
    }

    T operator()(unsigned i) const{
        return oth -> operator()(beg + (i -  1)*gap);
    }

    T& operator()(unsigned i){
        return oth -> operator()(beg + (i -  1)*gap);
    }

    void init(const T& t){
        for (int i = 1; i <= this -> taille(); i++)
            this -> operator()(i) = t;
    }
};


#endif