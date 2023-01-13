#include "za.h"

za_t::za_t(int num, std::string p, Polygone_t<int> f, std::string tc) : Parcelle_t(num, p, f) {
    typeCulture = tc;
    if(forme.getSurface() * 0.1 > 200) {
        float temp = (20000 / forme.getSurface());
        pConstructible = int(temp);
    }
    else {
        pConstructible = 10;
    }
}

void za_t::setType() {
    type = typeParcelle::agricole;
}