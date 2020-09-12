//
// Created by gael on 12/09/2020.
//

#ifndef TPS_INTERPOL_HPP
#define TPS_INTERPOL_HPP
#include <string>
#include <fstream>
class Interpol{
public:
    Interpol(const std::string& nom_fichier , int n);

    virtual double operator ()( double x) = 0;

protected:
    int n;
    double *points_x, *points_y, *poids;
};
#endif //TPS_INTERPOL_HPP
