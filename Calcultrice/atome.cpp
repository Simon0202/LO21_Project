#include "atome.h"

Atome::Atome(QString atm){
    if (atm.at(0).isLetter())
        val = atm;
    else
        throw "L'atome ne commence pas par une lettre";
}

void Atome::afficher(std::ostream& f) const
{
    f<<"val";
}
