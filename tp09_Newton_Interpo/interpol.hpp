//
// Created by gael on 12/09/2020.
//
#ifndef TPS_INTERPOL_HPP
#define TPS_INTERPOL_HPP
#include <string>
#include <fstream>
#include <memory>
class Interpol{
public:
    Interpol(const std::string& nom_fichier, int n);
    Interpol(const Interpol& other);
    virtual double operator ()( double x) = 0;
    ~Interpol();
    double min();
    double max();
protected:
    int n;
    std::shared_ptr<double[]> points_x, points_y, poids;
};

class InterpolLin: public Interpol{
public:
    double operator()(double x);
    InterpolLin(const std::string& nom_fichier, int n);
};
#endif //TPS_INTERPOL_HPP
