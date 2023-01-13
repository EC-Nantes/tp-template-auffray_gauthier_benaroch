#include <iostream>
#include "point2D.h"

template<typename T>
//Avec les templates, le nom de la classe doit tjr etre suivi de <T>
Point2D_t<T>::Point2D_t(){
    this->x = 0;
    this->y = 0;
}

template<typename T>
Point2D_t<T>::Point2D_t(T x, T y){
    this->x = x;
    this->y = y;
}

template<typename T>
Point2D_t<T>::Point2D_t(Point2D_t<T>& p){
    this->x = p->x;
    this->y = p->y;
}

template<typename T>
void Point2D_t<T>::translate(T x, T y){
    this->x += x;
    this->y += y;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Point2D_t<T>& p){
    s << "[" << p->x << ";" << p->y << "]" << std::endl;
    return s;
}