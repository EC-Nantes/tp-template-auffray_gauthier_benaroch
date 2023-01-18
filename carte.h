#ifndef CARTE_H
#define CARTE_H

#include <list>
#include "parcelle.h"

class Carte_t : std::list<Parcelle_t*> {

    private:
        float surfaceTotale;

    public:
        //Constructeur
        Carte_t();

        //Setteurs
        void addSurface();

        //Méthodes
        int getSurfaceTotal();
        void saveMap();
};
#endif