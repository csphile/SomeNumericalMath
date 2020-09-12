#include "StepFunction.hpp"
#ifndef STEP_CPP
#define STEP_CPP

template <typename T>
StepFunction<T> StepFunction<T>::operator+(const StepFunction<T>& oth){
    StepFunction<T> ans;
    int i = 0;
    while (i < oth.points.size() || i < this -> points.size()){
        double p1 = 0;
        if (i < oth.points.size()) p1 = oth.points[i];
        double p2 = 0;
        if (i < this -> points.size()) p2 = this -> points[i];
        ans.points.push_back(p1 + p2);
        ++i;
    }
    return ans;
}

template <typename T>
StepFunction<T> StepFunction<T>::operator*(int coef) {
    StepFunction<T> ans;
    for (int i = 0; i < this -> points.size(); i++){
        ans.points.push_back(2 * this -> points[i]);
    }
    return ans;
}

double LinearStepFunction::operator()(const double& x) const{
    if (x > this -> points.size() - 1) return 0;
	int left = x; int right = left + 1;
	return points[left] + (x - left)*(points[right] - points[left]);
}

double LinearStepFunction::inverse(double y) {
    std::vector<double> xs;
    int divid = 100;
    for (int i = 0; i < this -> points.size(); i++) {
        for (int j = 0; j < divid; j++){
            double x = i + (double) j / divid;
            xs.push_back(this -> operator()(x));
        }
    }
    auto it = std::lower_bound(xs.begin(), xs.end(), y);
    return (double) (it - xs.begin()) / divid;
}

double CstStepFunction::operator()(const double& x) const{
    if (x > this -> points.size()) return 0;
	return points[int(x)];
}

LinearStepFunction integrate(CstStepFunction const& f){
    LinearStepFunction ans(f.get_size());
    for (int i = 1; i < f.get_size(); i++){
        ans.set_point_value(i, f(i - 1) + ans(i - 1));
    }
    return ans;
}

CstStepFunction derive(LinearStepFunction const& f){
    CstStepFunction ans(f.get_size());
    for (int i = 1; i < f.get_size(); i++){
        ans.set_point_value(i - 1, f(i) - f(i - 1));
    }
    return ans;
}
#endif


