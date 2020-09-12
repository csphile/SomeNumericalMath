#include <iostream>
#include <vector>
#include "polynome.cpp"

using namespace std;
int main(void) {
	vector<int> coeff{ 2, -1, 4, 0, 2 };
	vector<unsigned> degre{0, 3, 2, 5, 6};
	Polynome P(coeff, degre);
	cout << "P:\t" << P << endl;
	Polynome Q(4, 2);
	cout << "Q:\t" << Q << endl;
	cout << "Q+1:\t" << Q+1 << endl; 
	cout << "P+Q:\t" << P+Q << endl;
	cout << "P-Q:\t" << P-Q << endl;
	// cout << "P*Q:\t" << P*Q << endl;
	return 0;
};