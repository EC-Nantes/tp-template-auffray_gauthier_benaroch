#ifndef PARCELLE_H
#define PARCELLE_H

#include <string>
#include "polygone.h"

class Parcelle_t {
protected:
    std::string type;
    int numero;
    std::string proprio;
    float surface;
    Polygone_t<int> forme;
public:
    // constructors
    Parcelle_t(int, std::string, Polygone_t<int>);
    Parcelle_t(Parcelle_t&);

    // getters
    int getNumero()             {return numero;}
    std::string getProprio()    {return proprio;}
    float getSurface()          {return surface;}
    Polygone_t<int> getForme()  {return forme;}
    std::string getType()       {return type;}

    // setters
    void setNumero(int num) {numero = num;}
    void setProprio(std::string prop) {proprio = prop;}
    void setForme(Polygone_t<int> f) {forme = f;}
    virtual void setType(std::string t) = 0;
};

#endif