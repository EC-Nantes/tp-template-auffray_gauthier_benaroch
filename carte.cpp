
#include "carte.h"
#include "zu.h"
#include "zau.h"
#include "za.h"
#include "zn.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

std::vector<std::string> split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
    // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
  }
  return elems;
}

int formatPoints(std::string str) {
    char chars[] = "[]";
    int result=0;

   for (unsigned int i = 0; i < strlen(chars); ++i)
   {
      // you need include <algorithm> to use general algorithms like std::remove()
      str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
   }
   result = std::stoi(str);
   return result;
}

Carte_t::Carte_t(std::string path){
    int nl, npt = 0;
    std::string line;
    std::vector<std::string> line_array, parcelle_elems, vStrPoints;
    std::vector<Point2D_t<int>> vPoints;
    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        while(getline(myfile, line)){
            nl++;
            line_array = split(line, ' '); //On stocke les tockens dans un tableau de string
            
            for(int i=0;  i < line_array.size(); i++){
                parcelle_elems.push_back(line_array[i]);
                //std::cout << line_array[i] << " ";
                //std::cout <<i << " " << line_array.size()-1 << " " << n%2 << " \n ";

                //Si ligne paire on créé les points correspondant à chaque coordonné
                if (nl % 2 == 0) {
                    vStrPoints = split(line_array[i], ';');
                    Point2D_t point(formatPoints(vStrPoints[0]), formatPoints(vStrPoints[1]));
                    vPoints.push_back(point);
                }

                //Si ligne paire et fin de ligne
                if ((nl % 2 == 0) && (i == line_array.size()-1)) {
                    
                    if(parcelle_elems[0] == "ZU"){
                        std::cout << "ZU detected : " << '\n';
                        for(int i=0;  i < parcelle_elems.size(); i++){
                            std::cout << parcelle_elems[i] << " ";
                        }
                        std::cout << '\n';

                        //Création d'une ZU
                        Polygone_t pol(vPoints);
                        zu_t zu(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol, std::stof(parcelle_elems[4]), std::stoi(parcelle_elems[3]));
                        std::cout << zu << std::endl;
                        this->push_back(&zu);
                        //le nom associé à Zu est supprimé à partir d'ici mais est toujours présent dans Carte_t
                    }
                    if(parcelle_elems[0] == "ZAU"){
                        std::cout << "ZAU detected : " << '\n';
                        for(int i=0;  i < parcelle_elems.size(); i++){
                            std::cout << parcelle_elems[i] << " ";
                        }
                        std::cout << '\n';

                        //Création d'une ZAU
                        Polygone_t pol(vPoints);
                        zau_t zau(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol);
                        std::cout << zau << std::endl;
                        this->push_back(&zau);
                        //le nom associé à Zau est supprimé à partir d'ici mais est toujours présent dans Carte_t

                    }
                    if(parcelle_elems[0] == "ZA"){
                        std::cout << "ZA detected : " << '\n';
                        for(int i=0;  i < parcelle_elems.size(); i++){
                            std::cout << parcelle_elems[i] << " ";
                        }
                        std::cout << '\n';

                        //Création d'une ZA
                        Polygone_t pol(vPoints);
                        za_t za(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol, parcelle_elems[3]);
                        std::cout << za << std::endl;
                        this->push_back(&za);
                        //le nom associé à Za est supprimé à partir d'ici mais est toujours présent dans Carte_t
                    }
                    if(parcelle_elems[0] == "ZN"){
                        std::cout << "ZN detecte : " << '\n';
                        for(int i=0;  i < parcelle_elems.size(); i++){
                            std::cout << parcelle_elems[i] << " ";
                        }
                        std::cout << '\n';
                        //Création d'une ZU
                        Polygone_t pol(vPoints);
                        zn_t zn(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol);
                        std::cout << zn << std::endl;
                        this->push_back(&zn);
                        //le nom associé à Za est supprimé à partir d'ici mais est toujours présent dans Carte_t
                    }
                    else {

                    }
                    parcelle_elems = {}; //On réinitialise le tableau
                    vPoints = {}; //On réinitialise le vecteur de points
                }
            }
        }

        myfile.close();
    }
    else std::cout << "Unable to open file"; 

}