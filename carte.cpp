
#include "carte.h"
#include "zu.h"
#include "zau.h"
#include "za.h"
#include "zn.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

//Sépare les terme d'une chaine de caractère à partir d'un délimiteur et stocke dans un tableau de string
std::vector<std::string> Carte_t::split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

//Formatage d'une coordonnées d'un point
int Carte_t::formatPoints(std::string str) {
    char chars[] = "[]";
    int result=0;
   for (unsigned int i = 0; i < strlen(chars); ++i) {
      str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
   }
   result = std::stoi(str);
   return result;
}

//Constructeur
Carte_t::Carte_t(std::string path){
    int nl, npt = 0;
    std::string line;
    std::vector<std::string> line_array, parcelle_elems, vStrPoints;
    std::vector<Point2D_t<int>> vPoints;
    std::ifstream myfile(path);
    if(myfile.is_open())
    {
        while(getline(myfile, line)){
            nl++;
            line_array = split(line, ' '); //On stocke les tockens dans un tableau de string
            
            //On parcours le tableau de string correspondant à la ligne courante
            for(int i=0;  i < line_array.size(); i++){
                parcelle_elems.push_back(line_array[i]);

                //Si ligne paire on créé les points correspondant à chaque coordonné
                if(nl % 2 == 0) {
                    vStrPoints = split(line_array[i], ';');
                    Point2D_t point(formatPoints(vStrPoints[0]), formatPoints(vStrPoints[1]));
                    vPoints.push_back(point);
                }

                //Si ligne paire et fin de ligne
                if((nl % 2 == 0) && (i == line_array.size()-1)) {
                    //Création d'une ZU
                    if(parcelle_elems[0] == "ZU"){
                        std::cout << "ZU detected : " << '\n';
                        Polygone_t pol(vPoints);
                        zu_t zu(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol, std::stof(parcelle_elems[4]), std::stoi(parcelle_elems[3]));
                        std::cout << zu << std::endl;
                        this->push_back(&zu);  //le nom associé à Zu est supprimé à partir d'ici mais est toujours présent dans Carte_t
                    }
                    //Création d'une ZAU
                    if(parcelle_elems[0] == "ZAU"){
                        std::cout << "ZAU detected : " << '\n';
                        Polygone_t pol(vPoints);
                        zau_t zau(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol);
                        std::cout << zau << std::endl;
                        this->push_back(&zau);
                    }
                    //Création d'une ZA
                    if(parcelle_elems[0] == "ZA"){
                        std::cout << "ZA detected : " << '\n';
                        Polygone_t pol(vPoints);
                        za_t za(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol, parcelle_elems[3]);
                        std::cout << za << std::endl;
                        this->push_back(&za);
                    }
                    //Création d'une ZU
                    if(parcelle_elems[0] == "ZN"){
                        std::cout << "ZN detecte : " << '\n';
                        Polygone_t pol(vPoints);
                        zn_t zn(std::stoi(parcelle_elems[1]), parcelle_elems[2], pol);
                        std::cout << zn << std::endl;
                        this->push_back(&zn);
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

//Sauvegarde de la carte dans un fichier donné en paramètre
void Carte_t::saveMap(std::string path) {
    std::ofstream myFile(path);
    //Carte_t::iterator it;
    std::list<Parcelle_t*>::iterator it;
    std::string type;

    //On parcours la liste de parcelles qui composent notre objet carte
    //for(it = this->begin(); it != this->end(); it++){
       // type = (*it)->getType();
        //myFile << type << " " << (*it)->getNumero() << " " << (*it)->getProprio();
        //if (type == "ZA") { myFile << " " << (*it)->getTypeCulture() << std::endl;}
        //if (type == "ZAU") { myFile << " " << (*it)->getPconstructible() << std::endl;}
        //if (type == "ZU") { myFile << " " << (*it)->getPconstructible() << " " << (*it)->getSurface() << std::endl;}
    //}

    myFile.close();
}