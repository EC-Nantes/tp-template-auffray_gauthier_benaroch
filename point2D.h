#ifndef POINT2D_H
#define POINT2D_H

#include <vector>

template<typename T>
class Point2D_t {
    private:
        T x;
        T y;

    public:
        //Constructeurs
        Point2D_t();
        Point2D_t(T x, T y);
        Point2D_t(Point2D_t& p);

        //Getteurs
        T getX() { return this->x;}
        T getY() { return this->x;}

        //Setteurs
        void setX(T x) { this->x = x;}
        void setY(T y) { this->y = y;}

        //Méthodes
        void translate(T x, T y);
};


#endif