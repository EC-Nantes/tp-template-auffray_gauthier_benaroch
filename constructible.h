#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIBLE_H

class Constructible_t {
public:
    Constructible_t() {}
    virtual float surfaceConstructible() const  = 0;
};

#endif