#ifndef PARCELLE_H
#define PARCELLE_H

#include <iostream>
#include <string>
#include "polygone.h"

class Parcelle_t {
protected:
    typeParcelle type;
    int numero;
    std::string proprio;
    Polygone_t<int> forme;
    unsigned int pConstructible;
    float surface;
public:
    // constructors
    Parcelle_t(int, std::string, Polygone_t<int>);
    Parcelle_t(Parcelle_t&);

    // getters
    int getNumero() const                   {return numero;}
    std::string getProprio() const          {return proprio;}
    Polygone_t<int> getForme()              {return forme;}
    typeParcelle getType() const            {return type;}
    unsigned int getPconstructible() const  {return pConstructible;}

    // setters
    void setNumero(const int num)           {numero = num;}
    void setProprio(const std::string prop) {proprio = prop;}
    void setForme(Polygone_t<int>);
    virtual void setType() = 0;

    // friend
    friend std::ostream& operator<< (std::ostream&, Parcelle_t &);
};

enum typeParcelle {
    urbaine,
    aUrbaniser,
    agricole,
    naturelleForestiere
};

#endif