#include "zu.h"
#include <iostream>

zu_t::zu_t(int num, std::string p, Polygone_t<int> f, float surfaceConstruite) : Parcelle_t(num, p, f) {
    if(surfaceConstruite > forme.getSurface()) {
        std::cerr << "Tentative de creation de la parcelle de M/Mme : " << p;
        std::cerr << "\nLa surface construite de la parcelle depasse la surface total de la parcelle";
        std::cerr << "\nSurface construite initialisee sur toute la parcelle" << std::endl;
        this->surfaceConstruite = forme.getSurface();
    }
    else {
        this->surfaceConstruite = surfaceConstruite;
    }
    this->setType();
}

void zu_t::setType() {
    type = typeParcelle::urbaine;
    typeString = "ZU";
}

float zu_t::surfaceConstructible() const {
    float temp = (this->getSurface() * pConstructible) / 100;
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

std::ostream& operator<<(std::ostream& o, const zu_t& parc) {
    o << "Parcelle n°" << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Propriétaire : " << parc.getProprio() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " %\n\t";
    o << "Surface construite : " << parc.getSurfaceConstruite() << "\n\t";
    o << "Surface a construire restante : " << parc.surfaceConstructible() << std::endl;
    return o;
}
