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
/*
Entier operator+(Entier& a,  Entier& b){

    double valeur=a.getVal()+b.getVal();
    Entier resultat(valeur);
    return resultat;
}

Entier operator-( Entier& a,  Entier& b){

    double valeur=a.getVal()-b.getVal();
    Entier resultat(valeur);
    return resultat;
}

Entier operator*( Entier& a,  Entier& b){

    double valeur=a.getVal()*b.getVal();
    Entier resultat(valeur);
    return resultat;
}

Entier operator/( Entier& a,  Entier& b){

    unsigned int valeur=a.getVal()/b.getVal();
    Entier resultat(valeur);
    return resultat;
}

Entier operator%( Entier& a,  Entier& b){
    double valeur=(int)a.getVal()%(int)b.getVal();
    Entier resultat(valeur);
    return resultat;
}

*/
