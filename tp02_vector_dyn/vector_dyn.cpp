#include "vector_dyn.hpp"
#include<iostream>

template<typename T> 
std::ostream& AbsVect<T>::operator<<(std::ostream& os, const AbsVect<T>& absVec){
    for (int i = 0; i < absVec.n; i++){
        os << absVec(i) << " ";
    }
    return os;
}