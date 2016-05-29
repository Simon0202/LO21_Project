#include "rationnel.h"

double Rationnel::pgcd(unsigned long int a,unsigned long int b)
{
    int r =a%b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

void Rationnel::simplifier(){

        if(getNumerateur()->getVal() != 0)
            {
                double p = pgcd(getNumerateur()->getVal(),getDenominateur()->getVal());
                _num->setVal(getNumerateur()->getVal()/p);
                _denum->setVal(getDenominateur()->getVal()/p);
                if (getDenominateur()<0 && getNumerateur()<0 )
                {
                    _num->setVal(-1*getNumerateur()->getVal());
                    _denum->setVal(-1*getDenominateur()->getVal());
                }
                if (getDenominateur() < 0)
                {
                    _num->setVal(-1*getNumerateur()->getVal());
                    _denum->setVal(-1*getDenominateur()->getVal());
                }

            }
            else
                 _denum->setVal(1);
}





LitteraleAbstraite* Rationnel::clone() const
{
    return new Rationnel(_num,_denum);
}

Rationnel& Rationnel::operator=(const Rationnel& n){
    if(this != &n){
        _num= n._num;
        _denum= n._denum;
    }
    return *this;
}

/*
Rationnel operator+( Rationnel& a,  Rationnel& b){


    Entier valDenum( a.getDenumerateur().getVal() * b.getDenumerateur().getVal());
    Entier valNum( a.getNumerateur().getVal()*b.getDenumerateur().getVal() + b.getNumerateur().getVal()*a.getDenumerateur().getVal() );

    Rationnel resultat(valNum, valDenum);
    return resultat;
}

Rationnel operator-( Rationnel& a,  Rationnel& b){
    Entier valDenum( a.getDenumerateur().getVal() * b.getDenumerateur().getVal());
    Entier valNum( a.getNumerateur().getVal()*b.getDenumerateur().getVal() - b.getNumerateur().getVal()*a.getDenumerateur().getVal() );

    Rationnel resultat(valNum, valDenum);
    return resultat;
}

Rationnel operator*( Rationnel& a,  Rationnel& b){

    Entier valNum( a.getNumerateur().getVal()*b.getNumerateur().getVal() );
    Entier valDenum( a.getDenumerateur().getVal()*b.getDenumerateur().getVal() );

    Rationnel resultat(valNum, valDenum);
    return resultat;
}

Rationnel operator/( Rationnel& a,  Rationnel& b){

    Entier valNum( a.getNumerateur().getVal()*b.getDenumerateur().getVal() );
    Entier valDenum( a.getDenumerateur().getVal()*b.getNumerateur().getVal() );

    Rationnel resultat(valNum, valDenum);
    return resultat;
}
*/
