#ifndef ZN_H
#define ZN_H

#include <string>
#include "parcelle.h"

class zn_t : public Parcelle_t{
public:
    zn_t(int, std::string, Polygone_t<int>);                      // constructor
    void setType();                                               // getter
    friend std::ostream& operator<<(std::ostream&, const zn_t&);  // friend
};

#endif