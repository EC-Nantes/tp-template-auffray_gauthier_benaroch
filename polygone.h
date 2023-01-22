#ifndef POLYGONE_H
#define POLYGONE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "point2D.h"

template<typename T>
class Polygone_t {
    private:
        std::vector<Point2D_t<T>> sommets;
        // Point2D_t<T> findPointDownLeft();

    public:
        //Constructeurs
        Polygone_t();
        Polygone_t(std::vector<Point2D_t<T>> listeSommets);
        Polygone_t(Polygone_t<T>& poly);

        //Getteurs
        std::vector<Point2D_t<T>> getSommets() const {return sommets;}

        //Setteurs
        void setSommets(std::vector<Point2D_t<T>> listeSommets) {std::swap(this->sommets, listeSommets);}

        //Méthodes
        void addPoint(Point2D_t<T>&);
        float getSurface();
        void translate(T x, T y);
};

template<typename T>
Polygone_t<T>::Polygone_t() {
    Point2D_t<T> point0;
    // for (int i = 0; i < 3; i++) {
    //     this->sommets.push_back(point0);
    // }
    // [JEAN] : c'est beaucoup plus simple d'utiliser la fonction insert ici
    this->sommets.insert(this->sommets.begin(), 3,  point0);
}

template<typename T>
Polygone_t<T>::Polygone_t(std::vector<Point2D_t<T>> listeSommets) {
    // typename std::vector<Point2D_t<T>> it;
    // [JEAN] : problème dans la déclaration de l'iterator
    typename std::vector<Point2D_t<T>>::iterator it;
    // for(it = this->listeSommets.begin(); it != this->listeSommets.end(); it++ ) {
    // [JEAN] : la tu met this-> alors que tu essai d'atteaindre le liste de sommet reçu en paramètre,
    //          pas la liste de sommet de la classe courante
    for(it = listeSommets.begin(); it != listeSommets.end(); it++) {
        this->sommets.push_back(*it);
        //std::cout<< *it << std::endl;  //test
    }
}

template<typename T>
Polygone_t<T>::Polygone_t(Polygone_t<T>& poly) {
    // this->sommets = poly->sommets;   // [JEAN] : poly n'est pas un pointeur sur un Polygone_t, c'est une référence
                                        // Tu ne peux pas acceder à ces attributs avec "->" mais avec "."
    this->sommets = poly.getSommets();
}

template<typename T>
void Polygone_t<T>::addPoint(Point2D_t<T>& p) {
    // for (int i = 0; i < 3; i++) {
    //     this->sommets.push_back(p);
    // }
    // [JEAN] : là tu l'ajoute 3 fois le point !!
    this->sommets.push_back(p);
}

template<typename T>       
void Polygone_t<T>::translate(T x, T y) {
    typename std::vector<Point2D_t<T>>::iterator it;
    for(it = this->sommets.begin(); it != this->sommets.end(); it++ ) {
        // it->x += x;
        // it->y += y;
        // [JEAN] : autant utiliser la fonction translate du point
        it->translate(x, y);
    }
}

template<typename T>
float Polygone_t<T>::getSurface() {
    float surface = 0;  //Surface totale du polynome
    // typename std::vector<Point2D_t<T>> it;
    // typename std::vector<Point2D_t<T>> it_next; // &it_next = it + 1;
    // [JEAN] : Là tu déclare mal tes itérators donc ça génère pas mal d'erreurs dans la compilation 

    typename std::vector<Point2D_t<T>>::iterator it;
    typename std::vector<Point2D_t<T>>::iterator it_next; // &it_next = it + 1;

    for (it = this->sommets.begin(); it != this->sommets.end(); it++) {
        it_next = it + 1;
        if (it_next == this->sommets.end()) {it_next = this->sommets.begin();}
        // surface += (it->x * it_next->y) - (it->y * it_next->x); //Produit vectoriel de 2 points 
        // [JEAN] : tu n'as pas accès directement au attribut d'un point2D, tu dois passer par les gets
        surface += (it->getX() * it_next->getY()) - (it->getY() * it_next->getX()); //Produit vectoriel de 2 points
    }
    return surface;
}

// template<typename T>
// Point2D_t<T> Polygone_t<T>::findPointDownLeft() {
//     Point2D_t<T> to_return;
//      = sommets[0];
//     for(int i = 0; i < sommets.size(); i++) {
//         to_return.
//     }
// }

template<typename T>
std::ostream& operator<<(std::ostream& s, const Polygone_t<T>& p){
    // typename std::vector<Point2D_t<T>> it; 
    // [JEAN] : idem, problem de déclaration d'iterateur
    std::vector<Point2D_t<T>> vect = p.getSommets();
    typename std::vector<Point2D_t<T>>::iterator it;
    s << "Polygone :";
    // for (it = p->sommets.begin(); it != p->sommets.end(); it++) {
    // [JEAN] : p n'est pas un pointeur, c'est une reférence donc pas de "->"
    //          je ne sais pas pourquoi mais obligé de passer par un vect fix.
    for (it = vect.begin(); it != vect.end(); it++) {
        // s << " " << it;
        // [JEAN] : là tu essai directment de print l'itérator, or toi tu n'as pas déffinit l'opérateur "<<"
        //          pour des itérateurs mais pour des vecteurs donc tu dois déréférencer
        s << " " << *it;
    }
    return s;
}

// template<typename T>
// std::ostream& operator<<(std::ostream& s, const Polygone_t<T>& p);

#endif