#include "parcelle.h"
#include "constructible.h"

class zu_t : Parcelle_t, Constructible_t{
private:
    float surfaceConstruite;
public:
    zu_t(/* args */);
    ~zu_t();
};

zu_t::zu_t(/* args */)
{
}

zu_t::~zu_t()
{
}
