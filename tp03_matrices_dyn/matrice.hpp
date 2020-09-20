#include <iostream>
#include <vector>

using namespace std;

//template< typename MATRICE> 
class matrice{
private:
	int row, col;
	vector<vector<int>> a;
	//int* a = new int[row][col];

//constructor
	matrice(int row_, int col_): row(row_), col(col_), a(vector<vector<int>>(row_, vector<int>(col_))){}
	//matrice(int row_, int col_): row(row_), col(col_), a(row_, vector<int>(col_)){}
	//matrice(int row_, int col_):row(row_), col(col_), a(vector<int>(row_, vector<int>(col_)>)){}
//constructor de clonage 
	matrice(int row_, int col_, vector<vector<int>> a_):row(row_), col(col_), a(a_){}

// operator d'affectation
	matrice operator=(matrice &m){
		row = m.row;
		col = m.col;
		a = vector<vector<int>>(row, vector<int>(col));
		return *this;
	}
// () as M(3,3) for constructor, () as M(i,j) fill value, () as (M,3) give columns
	// matrice operator()(int i, int j){
	// 	vector<vector<int> > a(int row, vector<int>(col));
	// 	return a;
	// }

	// int* operator()(int i, int j){
	// 	return &(this->a)[i][j];
	// }

//destructeur 



} ;