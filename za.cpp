#include "za.h"

za_t::za_t(int num, std::string p, Polygone_t<int> f, std::string tc) : Parcelle_t(num, p, f) {
    if(forme.getSurface() * 0.1 > 200) {
        float temp = (20000 / forme.getSurface());
        pConstructible = int(temp);
        surfaceConstructible = 200;
    }
    else {
        pConstructible = 10;
        surfaceConstructible = (0.1 * forme.getSurface());
    }
    this->setType();
    typeCulture = tc;
}

void za_t::setType() {
    type = typeParcelle::agricole;
    typeString = "ZA";
}

std::string za_t::print() const {
    std::string to_return;
    std::to_string(pConstructible);
    to_return += typeString;
    to_return += " ";
    to_return += std::to_string(numero);
    to_return += " ";
    to_return += proprio;
    to_return += " ";
    to_return += typeCulture;
    to_return += "\n";
    return to_return;
}

std::ostream& operator<<(std::ostream& o, const za_t& parc) {
    o << "Parcelle num " << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Proprietaire : " << parc.getProprio() << "\n\t";
    o << "Type de culture : " << parc.getTypeCulture() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " % batiment agricole uniquement\n\t";
    o << "Surface constructible : " << parc.getSurfaceConstruct() << "\n";
    return o;
}