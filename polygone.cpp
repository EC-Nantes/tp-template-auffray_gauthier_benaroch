#include <iostream>
#include "polygone.h"

// template<typename T>
// Polygone_t<T>::Polygone_t() {
//     Point2D_t point0(0,0);
//     for (int i = 0; i < 3; i++) {
//         this->sommets.push_back(point0);
//     }
// }

// template<typename T>
// Polygone_t<T>::Polygone_t(std::vector<Point2D_t<T>> listeSommets) {
//     typename std::vector<Point2D_t<T>> it;
//     for(it = this->listeSommets.begin(); it != this->listeSommets.end(); it++ ) {
//         this->sommets.push_back(*it);
//         std::cout<< *it << std::endl;  //test
//     }
// }

// template<typename T>
// Polygone_t<T>::Polygone_t(Polygone_t<T>& poly) {
//     this->sommets = poly->sommets;
// }

// template<typename T>
// void Polygone_t<T>::addPoint(Point2D_t<T>& p) {
//     for (int i = 0; i < 3; i++) {
//         this->sommets.push_back(p);
//     }
// }

// template<typename T>       
// void Polygone_t<T>::translate(T x, T y) {
//     typename std::vector<Point2D_t<T>> it;
//     for(it = this->sommets.begin(); it != this->sommets.end(); it++ ) {
//         it->x += x;
//         it->y += y;
//     }
// }

// template<typename T>       
// float Polygone_t<T>::getSurface() {
//     float surface = 0;  //Surface totale du polynome
//     typename std::vector<Point2D_t<T>> it;
//     typename std::vector<Point2D_t<T>> it_next; // &it_next = it + 1;

//     for (it = this->sommets.begin(); it != this->sommets.end(); it++) {
//         it_next = it + 1;
//         if (it_next == this->sommets.end()) {it_next = this->sommets.begin();}
//         surface += (it->x * it_next->y) - (it->y * it_next->x); //Produit vectoriel de 2 points
//     }
//     return surface;
// }

// template<typename T>
// std::ostream& operator<<(std::ostream& s, const Polygone_t<T>& p){
//     typename std::vector<Point2D_t<T>> it;
//     s << "Polygone :";
//     for (it = p->sommets.begin(); it != p->sommets.end(); it++) {
//         s << " " << it;
//     }
//     return s;
// }