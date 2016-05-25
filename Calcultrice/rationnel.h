#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "entier.h"


class Rationnel : public Entier
{
private:
    Entier _num;
    Entier _denum;
public:
    static double pgcd(unsigned long int a,unsigned long int b);
    void simplifier();

    //deux numeriques initialisent le rationnel.
    Rationnel(double n=0 , double d=1) : _num(n),_denum(d) {simplifier();}

    //2 entier initialisent le nombre rationnel.
    Rationnel(Entier n,Entier d) : _num(n),_denum(d) {simplifier();}

    //Un entier initialise le numerateur, le denominateur vaut 1.
    Rationnel(Entier e): _num(e),_denum(1){simplifier();}

    //Permet de creer un rationnel a partir d'un litteralAbstrait
    Rationnel(LitteraleAbstraite* d);

    Entier getNumerateur() const {return _num;}
    Entier getDenumerateur() const {return _denum;}

    //Héritage d'Entier<--Numerique<--LitteraleAbstraite
    virtual void setSign() {_num.setSign();}
    void afficher(std::ostream& f=std::cout) const { _num.afficher(f); f<<"/"; _denum.afficher(f); }
    virtual LitteraleAbstraite* clone() const;

    //Autorise affectation Rationnel-Rationnel
    Rationnel& operator=(const Rationnel& n);
};

Rationnel operator+( Rationnel& a,  Rationnel& b);
Rationnel operator-( Rationnel& a,  Rationnel& b);
Rationnel operator*( Rationnel& a,  Rationnel& b);
Rationnel operator/( Rationnel& a,  Rationnel& b);

#endif // RATIONNEL_H
