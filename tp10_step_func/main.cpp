#include "StepFunction.hpp"

int main(){
	double xk[] = { 0.2, 0.36, 0.5, 1.2 };
	double xk2[] = { 0.2, 0.36, 0.5, 1.2 };
	StepFunction<double> f_(xk, 4);
	double xk1[] = { 0.2, 0.36, 0.5, 1.2, 0.9, 1.3};
    CstStepFunction f1(xk1, 6);
    CstStepFunction f2 = f_ + f1;
    std::cout << f2 << std::endl;
	LinearStepFunction g(xk, 4);
	double t = 5.1;
    LinearStepFunction h = g * 2;
    f2 = f2 * 2;
    std::cout << "Multiplied by two" <<std::endl;
    std::cout << t << "\t" << f2(t) << "\t" << h(t) << std::endl;
    g = LinearStepFunction(xk, 4);
    CstStepFunction f = CstStepFunction(xk, 4);
    t = 1.5;
    std::cout << "t: \t" << t << "\t" << f(t) << "\t" << g(t) << std::endl;
    std::cout << "g is: " << g << std::endl;
    std::cout << "Reverse of g at 0.43 is: " << g.inverse(0.43) << std::endl;
    std::cout << "derive of g is: " << derive(g) << std::endl;
    std::cout << "integration of g is: " << integrate(g) << std::endl;
	return 0;
}