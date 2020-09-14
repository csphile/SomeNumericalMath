#ifndef STEP_FUNCTION
#define STEP_FUNCTION
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> class StepFunction
{
public:
	StepFunction() = default;
    StepFunction(const StepFunction<T>& oth){
	    points = oth.points;
	}
	StepFunction(T const* xk, unsigned size_){
		for (int i = 0; i < size_; i++){
			this -> points.push_back(xk[i]);
		}
	}

	explicit StepFunction(unsigned size_){
        points = std::vector<T>(size_);
    }

	~StepFunction() = default;

	friend std::ostream& operator<<(std::ostream& os, const StepFunction<T>& stepF){
		for (auto& t: stepF.points) os << t << " ";
		return os;
	}

	virtual StepFunction<T> operator+(const StepFunction<T>& oth);
    virtual StepFunction<T> operator*(int coef);
    virtual T operator() (const T& t) {std::cout << "base operator called\n";}
    unsigned get_size() const {return points.size();}
    void set_point_value(int i, double t){
        this -> points[i] = t;
    }
protected:
    std::vector<T> points;
};

// template class StepFunction<double>;

class CstStepFunction: public StepFunction<double>
{
public:
    //conversion constructor;
    CstStepFunction(const StepFunction<double>& other): StepFunction<double>(other) {}
	CstStepFunction(double const* xk, int n): StepFunction<double>(xk, n){}
    CstStepFunction(): StepFunction<double>(){}
	~CstStepFunction() = default;
    explicit CstStepFunction(unsigned size_){
        points = std::vector<double>(size_);
    }
	double operator()(const double& x) const;
};


class LinearStepFunction: public StepFunction<double>
{
public:
    //conversion constructor;
    LinearStepFunction(const StepFunction<double>& other): StepFunction<double>(other) {}

	LinearStepFunction(double const* xk, int n): StepFunction<double>(xk, n){}
    explicit LinearStepFunction(unsigned size_){
        points = std::vector<double>(size_);
    }
	~LinearStepFunction() = default;
	LinearStepFunction() = default;

	double operator()(const double& x) const;

	double inverse(double y);
};

extern LinearStepFunction integrate(const CstStepFunction& f);
extern CstStepFunction derive(LinearStepFunction const& f);
#endif