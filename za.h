#ifndef ZA_H
#define ZA_H

#include <string>
#include "parcelle.h"

class za_t : public Parcelle_t{
private:
    std::string typeCulture;
    float surfaceConstructible;
public:
    za_t(int, std::string, Polygone_t<int>, std::string);         // constructor
    void setType();                                               // setter
    std::string getTypeCulture() const {return typeCulture;}      // getter
    float getSurfaceConstruct() const {return surfaceConstructible;}
    std::string print() const;
    friend std::ostream& operator<<(std::ostream&, const za_t&);  // friend
};

#endif