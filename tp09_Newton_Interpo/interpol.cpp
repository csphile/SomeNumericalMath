//
// Created by gael on 12/09/2020.
//
#include "interpol.hpp"

Interpol::Interpol(const std::string& nom_fichier, int n) {
    std::ifstream file(nom_fichier.c_str());
    points_x = new double[n];
    points_y = new double[n];
    poids = new double[n];
    for(int i=0; i<n; ++i){
        file >> points_x[i] >> points_y[i]; file.close();
    }
}

