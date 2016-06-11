#include "reel.h"

LitteraleAbstraite *Reel::clone() const
{
    return new Reel(_val);
}


//Méthode toString
QString Reel::toString() const {
    return QString::number(_val);
}


