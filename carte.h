#ifndef CARTE_H
#define CARTE_H

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include "parcelle.h"
#include "point2D.h"
#include "polygone.h"
#include "zu.h"
#include "zau.h"
#include "za.h"
#include "zn.h"

class Carte_t : std::list<Parcelle_t*> {
private:
    float surfaceTotal;
    std::vector<std::string> split(std::string s, std::string delimiter);
    Point2D_t<int> parsePoint(std::string token);
public:
    // constructor
    Carte_t(std::string);
    Carte_t() = delete;
    // destructor
    ~Carte_t();
    // getters
    float getSurfaceTotal() {return surfaceTotal;}
    void save();
};

#endif