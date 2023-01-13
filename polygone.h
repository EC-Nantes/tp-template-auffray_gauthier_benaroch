#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include "point2D.h"

template<typename T>
class Polygone_t {
    private:
        std::vector<Point2D_t<T>> sommets;

    public:
        //Constructeurs
        Polygone_t();
        Polygone_t(std::vector<Point2D_t<T>> listeSommets);
        Polygone_t(Polygone_t<T>& poly);

        //Getteurs
        std::vector<Point2D_t<T>> getSommets() {return this->sommets;}

        //Setteurs
        void setSommets(std::vector<Point2D_t<T>> listeSommets) {this->sommets = listeSommets;}

        //Méthodes
        void addPoint(Point2D_t<T>&);
        void translate(T x, T y);
};

template<typename T>
std::ostream& operator<<(std::ostream& s, const Polygone_t<T>& p);

#endif