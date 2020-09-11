#ifndef VECT_HPP
#define VECT_HPP
#include<iostream> 

template <typename T> class AbsVect{
protected:
    int n;
    int data[];
public:
    AbsVect(int n_): n(n_){}
    int taille(){return n;}
    virtual T operator ()( int i) const = 0;
    virtual T & operator ()( int i) = 0;
    void remplit(int i, T t){this -> (i) = t;}
    void norm(){}
    friend ostream& operator<<(ostream& os, const AbsVect<T>& absVec);
    ~AbsVect(){delete[] data;}
};

template<typename T> class Vect: public AbsVect{
public:
    Vect(int n_): AbsVect<T>(n_) {}
};

template<class T> class SubVect: public AbsVect{

};

#endif