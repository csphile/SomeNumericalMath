//
// Created by gael on 12/09/2020.
//
#include "interpol.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using Points = std::vector<double>;
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

    file.close();
    std::vector<Points> to_sort(n, Points(2));
    for (int i = 0; i < n; i++){
        to_sort[i][0] = points_x[i];
        to_sort[i][1] = points_y[i];
    }
    std::sort(to_sort.begin(), to_sort.end());
    for (int i = 0; i < n; i++){
        points_x[i] = to_sort[i][0];
        points_y[i] = to_sort[i][1];
    }
    // compute weights
    for (int i = 0; i < n; i++)
        if (i < n - 1)
            poids[i] = (points_y[i + 1] - points_y[i]) / (points_x[i + 1] - points_x[i]);

    // for (int i = 0; i < n; i++) std::cout << points_x[i] << " " << points_y[i] << " " << poids[i] << std::endl;
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
    return points_x[0];
}

double Interpol::max() {
    return points_x[n - 1];
}


double InterpolLin::operator()(double x) {
    auto it = std::lower_bound(points_x, points_x + n, x);
    int k = it - points_x;
    double a_k = (k < n - 1)? poids[k]: poids[n - 2];
    return points_y[k] + a_k * (x - points_x[k]);
}

InterpolLin::InterpolLin(const std::string &nom_fichier, int n): Interpol(nom_fichier, n) {}

double InterpolPoly::operator()(double x) {
    //TO DO
    return 0;
}

InterpolPoly::InterpolPoly(const std::string &nom_fichier, int n) : Interpol(nom_fichier, n){}
