#ifndef POLYGONE_H
#define POLYGONE_H

#include <iostream>
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
        std::vector<Point2D_t<T>> getSommets() const {return this->sommets;}

        //Setteurs
        void setSommets(std::vector<Point2D_t<T>> listeSommets) {this->sommets = listeSommets;}

        //Méthodes
        void addPoint(Point2D_t<T>&);
        float getSurface();
        void translate(T x, T y);
};

template<typename T>
Polygone_t<T>::Polygone_t() {
    Point2D_t<T> const point0;
    for (int i = 0; i < 3; i++) {
        this->sommets.push_back(point0);
    }
}

template<typename T>
Polygone_t<T>::Polygone_t(std::vector<Point2D_t<T>> listeSommets) {
    typename std::vector<Point2D_t<T>>::iterator it;
    for(it = listeSommets.begin(); it != listeSommets.end(); it++ ) {
        this->sommets.push_back(*it);
        std::cout<< *it << std::endl;  //test
    }
}

template<typename T>
Polygone_t<T>::Polygone_t(Polygone_t<T>& poly) {
    this->sommets = poly.getSommets();
}

template<typename T>
void Polygone_t<T>::addPoint(Point2D_t<T>& p) {
    this->sommets.push_back(p);
}

template<typename T>       
void Polygone_t<T>::translate(T x, T y) {
    typename std::vector<Point2D_t<T>>::iterator it;
    for(it = this->sommets.begin(); it != this->sommets.end(); it++ ) {
        it->translate(x, y);
    }
}

template<typename T>       
float Polygone_t<T>::getSurface() {
    float surface = 0;  //Surface totale du polynome
    typename std::vector<Point2D_t<T>>::iterator it;
    typename std::vector<Point2D_t<T>>::iterator it_next; // &it_next = it + 1;

    for (it = this->sommets.begin(); it != this->sommets.end(); it++) {
        it_next = it + 1;
        if (it_next == this->sommets.end()) {it_next = this->sommets.begin();}
        surface += (it->getX() * it_next->getY()) - (it->getY() * it_next->getX()); //Produit vectoriel de 2 points
    }
    return surface;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Polygone_t<T>& p){
    typename std::vector<Point2D_t<T>>::iterator it;
    std::vector<Point2D_t<T>> vec_sommets = p.getSommets(); //obligé de passer par getSommets car attributs privés
    s << "Polygone :";
    for (it = vec_sommets.begin(); it != vec_sommets.end(); it++) {
        s << " " << *it;
    }
    return s;
}

#endif