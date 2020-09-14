//
// Created by gael on 12/09/2020.
//
#include "interpol.hpp"

Interpol::Interpol(const std::string& nom_fichier, int n) {
    std::ifstream file(nom_fichier.c_str());
    auto points_x = std::make_shared<double*>(new double[n]);
    // points_y = new double[n];
    auto points_y = std::make_shared<double*>(new double[n]);
    auto poids = std::make_shared<double*>(new double[n]);
    for(int i=0; i<n; ++i){
        file >> (*points_x)[i] >> (*points_y)[i];
    }
    file.close();
}

Interpol::Interpol(const Interpol &other) {

}

Interpol::~Interpol() {}

double Interpol::min() {
    return 0;
}

double Interpol::max() {
    return 0;
}


double InterpolLin::operator()(double x) {

    return 0;
}

InterpolLin::InterpolLin(const std::string &nom_fichier, int n) : Interpol(nom_fichier, n) {

}
