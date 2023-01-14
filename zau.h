#ifndef ZAU_H
#define ZAU_H

#include <string>
#include "parcelle.h"
#include "constructible.h"

class zau_t : public Parcelle_t, public Constructible_t {
public:
    zau_t(int, std::string, Polygone_t<int>);                     // constructor
    void setType();                                               // setter
    float surfaceConstructible() const;                           // getter
    friend std::ostream& operator<<(std::ostream&, const zau_t&); // friend
};

#endif
