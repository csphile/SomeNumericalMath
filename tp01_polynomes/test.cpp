#include <iostream> 
#include <cmath>
#include <unordered_map>
using namespace std;



int main(){
	unordered_map<int, int> u ;
	cout << "initialized" << endl;
	u[1] = 2;
	u[2] = 4;
	cout << "u[1]=" << u[1] << endl;
	cout << "u[2]=" << u[2] << endl;
	for(auto key = u.begin(); key != u.end(); ++key){
		cout << key->second << endl;
	}
}

	// static void simpCoef(MonoVec & data){
	// 	//simplify coefficient of the same degree
	// 	MonoVec data_;
	// 	unordered_map<int, int> u ;
	// 	for (auto v: data){
	// 		u[v.degree] += v.coeff; // degree is key, coef is value
	// 	}
	// 	for(auto key = u.begin(); key != u.end(); ++key){
	// 		//cout << key->second << endl;
	// 		if (key->second != 0){
	// 			Monome mytmp(key->second, key->first);
	// 			cout << 'tmp.degree = ' << key->second << endl;
	// 			data_.push_back(mytmp);
	// 		}
	// 	}
	// 	data = data_;
	// }