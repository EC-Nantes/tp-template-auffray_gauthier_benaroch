#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
class Point2D_t {
    private:
        T x;
        T y;

    public:
        //Constructeurs
        Point2D_t();
        Point2D_t(T x, T y);
        // Point2D_t(Point2D_t& p);
        // [JEAN] : erreur dans la déclaration du constructeur par recopie
        //          pas mal d'erreur dans le compilo à cause de ça
        Point2D_t(const Point2D_t<T>& p);

        //Getteurs
        T getX() const { return this->x;}
        T getY() const { return this->y;}

        //Setteurs
        void setX(T x) { this->x = x;}
        void setY(T y) { this->y = y;}

        //Méthodes
        void translate(T x, T y);

        Point2D_t<T>& operator=(Point2D_t<T> other) {
            x = other.getX();
            y = other.getY();
            return *this;
        }
};

template<typename T>
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
Point2D_t<T>::Point2D_t(const Point2D_t<T>& p){
    // this->x = p->x;
    // this->y = p->y;
    // [JEAN] : p est une référence pas un pointeur donc pas de "->"
    this->x = p.getX();
    this->y = p.getY();

}

template<typename T>
void Point2D_t<T>::translate(T x, T y){
    this->x += x;
    this->y += y;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Point2D_t<T>& p){
    s << "[" << p.getX() << ";" << p.getY() << "]";
    return s;
}

// template<typename T>
// std::ostream& operator<<(std::ostream& s, const Point2D_t<T>& p);

#endif