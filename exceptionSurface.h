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
public:
    exceptionPolyCroise_t() : exception() {};
    const char* what() const noexcept {return "Exception : Polygone croise !\n";}
};

class exceptionPolyOrdre_t : public std::exception {
public:
    exceptionPolyOrdre_t() : exception() {};
    const char* what() const noexcept {return "Exception : Polygone avec les points dans mauvaise ordre !\n";}
};

#endif