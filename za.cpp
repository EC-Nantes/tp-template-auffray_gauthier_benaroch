#include "za.h"

za_t::za_t(int num, std::string p, Polygone_t<int> f, std::string tc) : Parcelle_t(num, p, f) {
    if(forme.getSurface() * 0.1 > 200) {
        float temp = (20000 / forme.getSurface());
        pConstructible = int(temp);
    }
    else {
        pConstructible = 10;
    }
    this->setType();
}

void za_t::setType() {
    type = typeParcelle::agricole;
    typeString = "ZA";
}

std::ostream& operator<<(std::ostream& o, const za_t& parc) {
    o << "Parcelle num " << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Proprietaire : " << parc.getProprio() << "\n\t";
    o << "Type de culture : " << parc.getTypeCulture() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " % batiment agricole uniquement";
    o << std::endl;
    return o;
}