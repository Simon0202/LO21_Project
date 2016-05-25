#ifndef REEL_H
#define REEL_H

#include "numerique.h"

class Reel : public Numerique
{
private:
    float _val;
public:
    //Constructeur
    Reel(float v=0) : _val(v){}

    //Permet de creer un reel a partir d'une donnee.
    Reel(LitteraleAbstraite* d);

    //Accesseurs
    float getVal() const {return _val;}
    void setVal(double val){_val=val;}
    virtual void setSign() {_val=(-_val);}

    //Héritage de Numerique
    void afficher(std::ostream& f=std::cout) const { f<<_val; }
    virtual LitteraleAbstraite *clone() const;

    //Permet l'affectation Reel-Reel
    Reel& operator=(const Reel& n);
};

   Reel operator+( Reel& a,  Reel& b);
   Reel operator-( Reel& a,  Reel& b);
   Reel operator*( Reel& a,  Reel& b);
   Reel operator/( Reel& a,  Reel& b);

#endif // REEL_H
