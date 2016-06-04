#include "entier.h"

LitteraleAbstraite* Entier::clone() const
{
    return new Entier(_val);
}

Entier& Entier::operator=(const Entier& n)
{
    if(this != &n)
        _val = n._val;
    return *this;
}

QString Entier::toString() const {
    return QString::number(_val);
}


