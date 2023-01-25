#include <iostream>
#include <vector>
#include <exception>
#include <iterator>

#include "point2D.h"
#include "polygone.h"
#include "zu.h"
#include "zau.h"
#include "za.h"
#include "zn.h"
#include "carte.h"
#include "exceptionSurface.h"


int main() {

    //Test point
    std::cout << "[Test des points]\n";
    Point2D_t<int> point0;
    point0.translate(5, 0);
    Point2D_t<int> point1(5, 5);
    Point2D_t<int> point2(0, 5);
    Point2D_t<int> point3;
    Point2D_t<int> point4(point1);
    std::cout << "Point0 : " << point0 << "\n";
    std::cout << "Point1 : " << point1 << "\n";
    std::cout << "Point2 : " << point2 << "\n";
    std::cout << "Point3 : " << point3 << "\n";
    std::cout << "Point4 : " << point4 << "\n\n";

    //Test polygone
    std::cout << "[Test des polygones]\n";
    std::vector<Point2D_t<int>> vect;
    vect.push_back(point0);
    vect.push_back(point1);
    vect.push_back(point2);
    vect.push_back(point3);

    try {
        Polygone_t<int> pol1;
        Polygone_t<int> pol2(vect);
        Polygone_t<int> pol3(pol2);
        std::cout << "pol1 : " << pol1 << "\n";
        std::cout << "pol2 : " << pol2 << "\n";
        std::cout << "pol3 : " << pol3 << "\n";

        Point2D_t<int> to_add(3, 5);
        pol1.addPoint(to_add);
        std::cout << "Add (3, 5) to pol1\n";
        std::cout << "pol1 : " << pol1 << "\n";
        pol2.translate(10, 10);
        std::cout << "Translate pol2 to (+10, +10)\n";
        std::cout << "pol2 : " << pol2 << "\n\n";
    }
    catch(const std::exception& e) {
        std::cout << "dbg 1\n";
        std::cerr << e.what() << '\n';
    }

    //Test parcelle
    std::cout << "[Test des parcelles]\n";
    Point2D_t<int> haut_d(5, 5);
    Point2D_t<int> haut_g(-5, 5);
    Point2D_t<int> bas_g(-5, -5);
    Point2D_t<int> bas_d(5, -5);
    std::vector<Point2D_t<int>> points;
    points.push_back(haut_d);
    points.push_back(haut_g);
    points.push_back(bas_g);
    points.push_back(bas_d);

    try {
        Polygone_t<int> pol_parc(points);
        zu_t ZU1(1, "M. GAUTHIER", pol_parc, 35.6);
        pol_parc.translate(15, 0);
        zau_t ZAU1(2, "M. AUFFRAY", pol_parc);
        pol_parc.translate(0, -15);
        za_t ZA1(3, "M. BENAROCH", pol_parc, "ble");
        pol_parc.translate(-15, 0);
        zn_t ZN1(4, "M. ROUX", pol_parc);

        std::cout << ZU1 << "\n";
        std::cout << ZAU1 << "\n";
        std::cout << ZA1 << "\n";
        std::cout << ZN1 << "\n";
    }
    catch(const std::exception& e) {
        std::cout << "dbg 2\n";
        std::cerr << e.what() << '\n';
    }
    
    //Teste carte
    std::cout << "[Test de la carte]\n";
    try {
        Carte_t carte("Parcelles_short.txt");
        std::cout << "Surface total : " << carte.getSurfaceTotal() << "\n";
        Polygone_t<int> pol_parc(points);
        zu_t* ZU2 = new zu_t(6, "M. PROPRIO", pol_parc, 12.54);
        carte.add(ZU2);
        std::cout << "Ajout de la parcelle num 6 (M. PROPRIO) a la carte\n";
        std::cout << *ZU2;
        std::cout << "Nouvelle surface total : " << carte.getSurfaceTotal() << "\n";
        carte.save();
        std::cout << "Enrigistrement de la carte complete dans le fichier save_parc.txt\n\n";
    }
    catch(const std::exception& e) {
        std::cout << "dbg 3\n";
        std::cerr << e.what() << '\n';
    }

    //Teste exception
    std::cout << "[Test de l'exception croise]\n";
    Point2D_t<int> pt1(0, 0);
    Point2D_t<int> pt2(10, 0);
    Point2D_t<int> pt3(0, 10);
    Point2D_t<int> pt4(10, 10);
    std::vector<Point2D_t<int>> points_exception;
    points_exception.push_back(pt1);
    points_exception.push_back(pt2);
    points_exception.push_back(pt3);
    points_exception.push_back(pt4);

    std::vector<Point2D_t<int>> points_exception2;
    points_exception2.push_back(pt1);
    points_exception2.push_back(pt2);
    points_exception2.push_back(pt4);
    points_exception2.push_back(pt3);

    try {
        std::cout << "Tentative creation polygone non croise...\n";
        Polygone_t<int> poly_exception2(points_exception2);
        std::cout << "...Polygone creer\n";
        std::cout << "Tentative creation polygone croise...\n";
        Polygone_t<int> poly_exception(points_exception);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}