#include "reel.h"

LitteraleAbstraite *Reel::clone() const
{
    return new Reel(_val);
}


//Méthode toString
QString Reel::toString() const {
    return QString::number(_val);
}


<<<<<<< HEAD
=======
//Faut il les enlever
Reel& Reel::operator=(const Reel& n)
{
    if(this != &n)
        _val = n._val;
    return *this;
}

/*
Reel operator+( Reel& a,  Reel& b){

    float val=a.getVal()+b.getVal();
    Reel resultat(val);
    return resultat;
}

Reel operator-( Reel& a,  Reel& b){
    float val=a.getVal()-b.getVal();
    Reel resultat(val);
    return resultat;
}

Reel operator*( Reel& a,  Reel& b){

    float val=a.getVal()*b.getVal();
    Reel resultat(val);
    return resultat;
}

Reel operator/( Reel& a,  Reel& b){

    float val=a.getVal()/b.getVal();
    Reel resultat(val);
    return resultat;
}

*/


>>>>>>> 7f872e351578daa9a54fdd4bb09fb8cd13c38419




