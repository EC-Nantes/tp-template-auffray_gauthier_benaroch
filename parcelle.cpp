#include "parcelle.h"

Parcelle_t::Parcelle_t(int num, std::string p, Polygone_t<int> f) {
    numero = num;
    proprio = p;
    forme.setSommets(f.getSommets());
    forme.surface = f.getSurface();
}

Parcelle_t::Parcelle_t(Parcelle_t& parc) {
    numero = parc.getNumero();
    proprio = parc.getProprio();
    forme.setSommets(parc.getForme().getSommets());
}

void Parcelle_t::setForme(Polygone_t<int> f) {
    forme.setSommets(f.getSommets());
    forme.surface = f.getSurface();
}