#include <iostream>
#include <vector>

#include "point2D.h"
#include "polygone.h"
#include "zu.h"
#include "zau.h"
#include "za.h"
#include "zn.h"
#include "carte.h"

int main() {

    //Test point
    Point2D_t<int> point0;
    point0.translate(5, 5);
    Point2D_t<int> point1(1, 2);
    Point2D_t<int> point2(3, 4);
    Point2D_t<int> point3;
    Point2D_t<int> point4(point1);
    std::vector<Point2D_t<int>> vect = {
        {point0},
        {point1},
        {point2},
        {point3},
        {point4}
    };

    //Test polygone
    Polygone_t<int> pol1;
    Polygone_t<int> pol2(vect);
    Polygone_t<int> pol3(pol2);
    std::cout << point0 << std::endl;
    std::cout << point1 << std::endl;
    std::cout << point2 << std::endl;
    std::cout << point3 << std::endl;
    std::cout << point4 << std::endl;
    std::cout << pol1 << std::endl;
    std::cout << pol2 << std::endl;
    std::cout << pol3 << std::endl;
    pol1.setSommets(vect);
    std::cout << pol1 << std::endl;

    pol1.addPoint(point0);
    float surf = pol1.getSurface();
    std::cout << pol1 << std::endl;
    pol1.translate(10, 10);
    std::cout << pol1 << std::endl;

    //Test parcelle
    Point2D_t<int> haut_d(1000, 1000);
    Point2D_t<int> haut_g(-5, 5);
    Point2D_t<int> bas_g(-5, -5);
    Point2D_t<int> bas_d(5, -5);

    Polygone_t<int> pol_parc;
    pol_parc.addPoint(haut_d);
    pol_parc.addPoint(haut_g);
    pol_parc.addPoint(bas_g);
    pol_parc.addPoint(bas_d);

    zu_t ZU1(1, "M. GAUTHIER", pol_parc, 35.6);
    std::cout << ZU1 << std::endl;

    pol_parc.translate(15, 0);
    zau_t ZAU1(2, "M. AUFFRAY", pol_parc);
    std::cout << ZAU1 << std::endl;

    pol_parc.translate(0, -15);
    za_t ZA1(3, "M. BENAROCH", pol_parc, "ble");
    std::cout << ZA1 << std::endl;

    pol_parc.translate(-15, 0);
    zn_t ZN1(4, "M. ROUX", pol_parc);
    std::cout << ZN1 << std::endl;

    Carte_t carte("Parcelles_short.txt");
    //Carte_t carte1("Parcelles.txt");
    carte.saveMap("testSave.txt");

    return 0;
}