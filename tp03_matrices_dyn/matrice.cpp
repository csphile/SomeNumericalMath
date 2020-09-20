#include <iostream>
#include "matrice.hpp"

using namespace std;

int main(){
	matrice M(3,3);
	cout << "sucessfully generated" << endl;
	for (int i = 1; i<= M.nb_lignes(); ++i)
		for (int j = 1; j<=M.nb_cols(); ++j)
			M[i][j] = i*j + i;
	cout << "Matrice M: \n" << M << endl;

	// cout << "Ligne 1:\t" << Ligne<int>(M,1) << endl;
	// cout << "Colonne 3:\t" << Colonne<int>(M,3) << endl;
	// cout << endl;

	// Matrice<int> M2(3,3);
	// for (int i = 1; i<=M.nb_lignes; ++i)
	// 	for(int j = 1; j<=M.nb_cols(); ++j)
	// 		M2(i,j) = produit_scalaire(Ligne<int>(M,i), Colonne<int>(M,j));
	// cout << "Matrice M2:\n" << M2 << endl;

	return 0;
}