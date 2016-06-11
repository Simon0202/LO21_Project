#include "entier.h"

LitteraleAbstraite* Entier::clone() const
{
    return new Entier(_val);
}

//Méthode toString
QString Entier::toString() const {
    return QString::number(_val);
}
