
#include "carte.h"
#include <fstream>

Carte_t::Carte_t(){

    std::string line;
    std::ifstream myfile("Parcelles_short.txt");
    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
        std::cout << line << '\n';
        }
        myfile.close();
    }
    else std::cout << "Unable to open file"; 

}