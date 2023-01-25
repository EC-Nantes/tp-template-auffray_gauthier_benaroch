#ifndef PARCELLE_H
#define PARCELLE_H

#include <iostream>
#include <fstream>
#include <string>
#include "polygone.h"
#include "exceptionSurface.h"

class Parcelle_t {
protected:
    unsigned int type;
    std::string typeString;
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
    Polygone_t<int>& getForme()             {return forme;}
    std::string getType() const             {return typeString;}
    unsigned int getPconstructible() const  {return pConstructible;}
    float getSurface() const                {return surface;}
    virtual std::string print() const = 0;

    // setters
    void setNumero(const int num)           {numero = num;}
    void setProprio(const std::string prop) {proprio = prop;}
    void setForme(Polygone_t<int>);
    virtual void setType() = 0;

    // friend
    friend std::ostream& operator<<(std::ostream&, const Parcelle_t &);
};

enum typeParcelle {
    urbaine,
    aUrbaniser,
    agricole,
    naturelleForestiere
};

#endif