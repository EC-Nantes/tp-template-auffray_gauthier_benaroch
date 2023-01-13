#include <iostream>
#include "polygone.h"

template<typename T>
Polygone_t<T>::Polygone_t() {

}

template<typename T>
Polygone_t<T>::Polygone_t(std::vector<Point2D_t<T>> listeSommets) {

}

template<typename T>
Polygone_t<T>::Polygone_t(Polygone_t<T>& poly) {

}

template<typename T>
void Polygone_t<T>::addPoint(Point2D_t<T>&) {

}
        
template<typename T>       
void Polygone_t<T>::translate(T x, T y) {
    
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Polygone_t<T>& p){
    
}