#ifndef ZAU_H
#define ZAU_H

#include <string>
#include "parcelle.h"
#include "constructible.h"

class zau_t : public Parcelle_t, public Constructible_t {
public:
    zau_t(int, std::string, Polygone_t<int>);                     // constructor
    zau_t(int, std::string, Polygone_t<int>, int);
    void setType();                                               // setter
    float surfaceConstructible() const;                           // getter
    std::string print() const;
    friend std::ostream& operator<<(std::ostream&, const zau_t&); // friend
};

#endif
