#ifndef PARCELLE_H
#define PARCELLE_H

#include <string>
#include "polygone.h"

class Parcelle_t {
protected:
    typeParcelle type;
    int numero;
    std::string proprio;
    Polygone_t<int> forme;
    int pConstructible; 
public:
    // constructors
    Parcelle_t(int, std::string, Polygone_t<int>);
    Parcelle_t(Parcelle_t&);

    // getters
    int getNumero()             {return numero;}
    std::string getProprio()    {return proprio;}
    Polygone_t<int> getForme()  {return forme;}
    typeParcelle getType()       {return type;}

    // setters
    void setNumero(int num) {numero = num;}
    void setProprio(std::string prop) {proprio = prop;}
    void setForme(Polygone_t<int>);
    virtual void setType() = 0;
};

enum typeParcelle {
    urbaine,
    aUrbaniser,
    agricole,
    naturelleForestiere
};

#endif