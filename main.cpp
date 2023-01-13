#include <iostream>
#include <vector>

#include "point2D.h"
#include "polygone.h"

int main() {

    //Test point
    Point2D_t<int> point0;
    Point2D_t<int> point1(1, 2);
    std::cout << point0 << point1 << std::endl;
    point0.translate(5, 5);
    std::cout << point0 << std::endl;

    //Test polygone
    Polygone_t<int> pol1;
    //std::cout << pol1 << std::endl;

}