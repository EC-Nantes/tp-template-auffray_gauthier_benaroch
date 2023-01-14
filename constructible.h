#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIblE_H

class Constructible_t {
public:
    Constructible_t() {}
    virtual float surfaceConstructible() const  = 0;
};
Constructible_t::Constructible_t() {}
#endif