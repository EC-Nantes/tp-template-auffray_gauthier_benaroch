#ifndef EXCEPTIONSURFACE_H
#define EXCEPTIONSURFACE_H

#include <exception>
#include <string>

class ExceptionSurface_t : public std::exception {
public:
    ExceptionSurface_t() : exception() {};
    const char* what() const noexcept {return "Exception : surface nul ou negative au moment de creer une parcelle !\n";}
};

class exceptionPolyCroise_t : public std::exception {
private:
    /* data */
public:
    exceptionPolyCroise_t() : exception() {};
    const char* what() const noexcept {return "Exception : Polynome croise !\n";}
};

class exceptionPolyOrdre : public std::exception {
public:
    exceptionPolyOrdre() : exception() {};
    const char* what() const noexcept {return "Exception : Polynome avec les points dans mauvaise ordre !\n";}
};

#endif