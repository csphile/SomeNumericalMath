#include <iostream>
#include <vector>

using namespace std;

//template< typename MATRICE> 
class matrice{
private:
	int row, col;
	vector<vector<int> > a(int row, vector<int>(col));
	//int* a = new int[row][col];

//constructor
	matrice(int row_, int col_): row(row_), col(col_), a(row, vector<int>(col)){}
//constructor de clonage ??

// operator d'affectation
	matrice operator=(matrice &m){
		row = m.row;
		col = m.col;
		a = new int[row][col];
		return this;
	}
// () as M(3,3) for constructor, () as M(i,j) fill value, () as (M,3) give columns
	matrice operator()(int i, int j){
		vector<vector<int> > a(int row, vector<int>(col));
		return a;
	}

	int* operator()(int i, int j){
		return &(this->a)[i][j];
	}

//destructeur 



} ;