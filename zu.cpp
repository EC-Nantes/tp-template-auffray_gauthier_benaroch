#include "zu.h"
#include <iostream>

zu_t::zu_t(int num, std::string p, Polygone_t<int> f, float surfaceConstruite) : Parcelle_t(num, p, f) {
    type = typeParcelle::urbaine;
    if(surfaceConstruite > forme.getSurface()) {
        std::cerr << "Tentative de creation de la parcelle de M/Mme : " << p;
        std::cerr << "\nLa surface construite de la parcelle depasse la surface total de la parcelle";
        std::cerr << "\nSurface construite initialisee sur toute la parcelle" << std::endl;
        this->surfaceConstruite = forme.getSurface();
    }
    else {
        this->surfaceConstruite = surfaceConstruite;
    }
}

void zu_t::setType() {
    type = typeParcelle::urbaine;
}

float zu_t::surfaceConstructible() {
    float temp = (forme.getSurface() * pConstructible) / 100;
    return (temp - surfaceConstruite);
}

void zu_t::setSurfaceConstruite(const float s) {
    if(s > forme.getSurface()) {
        std::cerr << "Tentative de setSurfaceConstruite() de la parcelle de M/Mme : " << proprio;
        std::cerr << "\nLa surface construite de la parcelle depasse la surface total de la parcelle";
        std::cerr << "\nSurface construite set sur toute la parcelle" << std::endl;
        this->surfaceConstruite = forme.getSurface();
    }
    else {
        this->surfaceConstruite = s;
    }
}