#ifndef MONOME
#define MONOME
#include <iostream> 
#include <cmath>

using namespace std;

class Monome{
public:
	Monome(int coeff_ = 0, unsigned degre = 0): coeff(coeff_), degree(degre){}
	double operator()(double x) const{
		return coeff * pow(x, degree);
	}

	Monome operator-(const Monome& r) {
		Monome ans(coeff, degree);
		if (degree != r.degree) {
			cout << "Error, can't do operations on monomes of differents degrees" << endl;
			Monome tmp;
			return tmp;
		}
		ans.coeff -= r.coeff;
		return ans;
	}
	Monome operator+(const Monome& other) const {
		Monome ans(coeff, degree);
		if (degree != other.degree) {
			cout << "Error, can't do operations on monomes of differents degrees" << endl;
			Monome tmp;
			return tmp;
		}
		ans.coeff += other.coeff;
		return ans;
	}
	bool operator<(const Monome& other) const {
		return (degree < other.degree);
	}

	bool operator==(const Monome& other) const {
		return (degree == other.degree && coeff == other.coeff);
	}
	friend class Polynome;
	friend std::ostream & operator <<(ostream& os, const Monome& mono){
		os << mono.coeff << "x^" << mono.degree;
		return os;
	}

private:
	int coeff; 
	unsigned degree;
};
#endif
