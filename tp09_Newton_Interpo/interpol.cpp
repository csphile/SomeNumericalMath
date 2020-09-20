//
// Created by gael on 12/09/2020.
//
#include "interpol.hpp"
#include <algorithm>
#include <iostream>

Interpol::Interpol(const std::string& nom_fichier, int n) {
    points_x = new double[n];
    points_y = new double[n];
    poids = new double[n];
    this -> n = n;
    std::ifstream file(nom_fichier.c_str());
    assert(file.is_open());
    for(int i=0; i < n; ++i){
        file >> points_x[i] >> points_y[i];
    }
    // for (int i = 0; i < n; i++) std::cout << points_x[i] << " " << points_y[i] << std::endl;
    file.close();
}

Interpol::Interpol(const Interpol &other) {
    points_x = new double[n];
    points_y = new double[n];
    poids = new double[n];
    for(int i=0; i < n; ++i) {
        points_x[i] = other.points_x[i];
        points_y[i] = other.points_y[i];
        poids[i] = other.poids[i];
    }
}

Interpol::~Interpol() {
    delete [] points_x;
    delete [] points_y;
    delete [] poids;
}

double Interpol::min() {
    return *std::min_element(points_x, points_x + n );
}

double Interpol::max() {
    return *std::max_element(points_x, points_x + n );
}


double InterpolLin::operator()(double x) {

    return 0;
}

InterpolLin::InterpolLin(const std::string &nom_fichier, int n): Interpol(nom_fichier, n) {}
