#include <iostream>
#include <vector>

using namespace std;

template< typename T>
class matrix{
private:
	int row, col;
	vector<vector<T>> a;
public:
    matrix(int row_, int col_);
    //copy constructor;
    matrix(matrix<T>& other);
    T& operator()(int i, int j) {
        i -= 1;
        j -= 1;
        return a[i][j];
    }
    T operator()(int i, int j) const {
        i -= 1;
        j -= 1;
        return a[i][j];
    }
    [[nodiscard]] int nb_lignes() const {
        return row;
    }
    [[nodiscard]] int nb_cols() const {
        return col;
    }

    friend ostream& operator<<(ostream& os, const matrix<T>& m){
        for (int i = 1; i <= m.nb_lignes(); i++){
            for (int j = 1; j <= m.nb_cols(); j++){
                os << m(i, j);
                if (j < m.nb_cols()) os << " ";
            }
            os << endl;
        }
        return os;
    }
};

template <typename T>
class AbsVect{
protected:
    int ind, taille;
    matrix<T>& mat;
public:
    AbsVect(matrix<T>& mat_, int i): mat(mat_), ind(i){}
    virtual T operator()(unsigned i) const = 0;
    virtual T & operator()(unsigned i) = 0;
    [[nodiscard]] int nb_taille() const {return taille;}
    friend ostream& operator<<(ostream& os, const AbsVect<T>& m){
        for (int i = 1; i <= m.taille; i++){
            os << m.operator()(i) << " ";
        }
        return os;
    }
};

template <typename T>
class Ligne: public AbsVect<T>{
public:
    Ligne(matrix<T>& mat_, int i): AbsVect<T>(mat_, i){
        this -> taille = mat_.nb_cols();
    }
    T operator()(unsigned i) const{
        return this -> mat(this->ind, i);
    }
    T& operator()(unsigned i){
        return this->mat(this->ind, i);
    }
};

template <typename T>
class Colonne: public AbsVect<T>{
public:
    Colonne(matrix<T>& mat_, int i): AbsVect<T>(mat_, i){
        this -> taille = mat_.nb_lignes();
    }
    T operator()(unsigned i) const{
        return this -> mat(i, this->ind);
    }
    T& operator()(unsigned i){
        return this -> mat(i, this->ind);
    }
};

template<typename T>
matrix<T>::matrix(matrix<T> &other): row(other.row), col(other.col) {
    // deep copy;
    a = other.a;
}
template<typename T>
matrix<T>::matrix(int row_, int col_): row(row_), col(col_) {
    a = vector<vector<T>> (row_, vector<int>(col_));
}

template <typename T>
T produit_scalaire(const Ligne<T>& line, const Colonne<T>& col){
    assert(line.nb_taille() == col.nb_taille());
    int k = line.nb_taille();
    T ans = 0;
    for (int i = 1; i <= k; i++){
        ans += line(i)*col(i);
    }
    return ans;
}