
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

std::string formatPoints(std::string str) {
    char chars[] = "[]";

   for (unsigned int i = 0; i < strlen(chars); ++i)
   {
      // you need include <algorithm> to use general algorithms like std::remove()
      str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
   }
   return str;
}

Carte_t::Carte_t(){
    int n = 0;
    std::string line;
    std::vector<std::string> points;
    std::vector<std::string> line_array;
    std::vector<std::string> parcelle_elems;
    std::ifstream myfile("Parcelles_short.txt");
    if (myfile.is_open())
    {
        while(getline(myfile, line)){
            n++;
            line_array = split(line, ' '); //On stocke les tockens dans un tableau de string
            
            for(int i=0;  i < line_array.size(); i++){
                        parcelle_elems.push_back(line_array[i]);
                        //Si ligne paire et fin de ligne
                        if ((n%2 == 0) && (i == line_array.size()-1)) { //&& (i == line_array.size()-1)

                            if(parcelle_elems[i] == "ZU"){
                                std::cout << "ZU detected : " << '\n';
                                for(int i=0;  i < parcelle_elems.size(); i++){
                                    std::cout << parcelle_elems[i] << " ";
                                }
                                std::cout << '\n';

                                //Création d'une ZU
                                //points = split(parcelle_elems[5], ';');
                                //Point2D_t point(formatPoints(points[0]), formatPoints(points[1]));
                                //Polygone_t pol();
                                //zu_t zu(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol, std::stoi(parcelle_elems[3]), std::stoi(parcelle_elems[4]));
                            }
                            if(parcelle_elems[i] == "ZAU"){
                                std::cout << "ZAU detected : " << '\n';
                                for(int i=0;  i < parcelle_elems.size(); i++){
                                    std::cout << parcelle_elems[i] << " ";
                                }
                                std::cout << '\n';

                            }
                            if(parcelle_elems[i] == "ZA"){
                                std::cout << "ZA detected : " << '\n';
                                for(int i=0;  i < parcelle_elems.size(); i++){
                                    std::cout << parcelle_elems[i] << " ";
                                }
                                std::cout << '\n';
                            }
                            if(parcelle_elems[i] == "ZN"){
                                std::cout << "ZN detecte : " << '\n';
                                for(int i=0;  i < parcelle_elems.size(); i++){
                                    std::cout << parcelle_elems[i] << " ";
                                }
                                std::cout << '\n';
                            }
                            else {

                            }
                            parcelle_elems = {}; //On réinitialise le tableau
                        }
            }
        }

        myfile.close();
    }
    else std::cout << "Unable to open file"; 

}