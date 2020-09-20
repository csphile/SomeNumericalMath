#include <iostream>

class A {
public:
int* p; int t[1]; 
};

void incr (A a) {
std::cout << a.t << " | " << a.p << std::endl; // 0x7ffe951ee540 | 0x7ffe951ee560
}

int main () {
A a; a.t[0] = 0; a.p = a.t; //此处为shallow copy
std::cout << a.t << " | " << a.p<< std::endl;
incr(a); // passes a copy of a containing copies of a.p and a.t to incr 
std::cout << a.t << " | " << a.p<< std::endl; // 0x7ffe951ee560 | 0x7ffe951ee560 return 0;
}

// #include <iostream>

// typedef struct product {
//   const char* name;
//   int weight;
//   double price;
// } product;

// product* create_product (const char* _name, int _weight, double _price) { 
// 	product* p = new product;
// 	p->name = _name; 
// 	p->weight = _weight; 
// 	p->price = _price;
// 	return p;
// }

// std::ostream& operator<<(std::ostream& od, product& p) { // overloaded op. 
// 	od << p.name << ": " << p.weight << "g, " << p.price << " euro(s)";
// 	return od;
// }

// int main () {
// 	product* p = create_product ("banana", 73, 0.28);
// 	std::cout << *p << std::endl; // prints banana: 73g, 0.28 euro(s)
// 	p = NULL;
// 	std::cout << "hello" << std::endl;
// 	std::cout << 1+3 << std::endl;
// 	return 0; 
// }
