#ifndef ENTIER_H
#define ENTIER_H

#include "numerique.h"

class Entier : public Numerique
{
private:
    long int _val;
public:
    //conversion implicite effectuee a l'initialisation de l'attribut.
    Entier(double val=1):_val(val){}

    //Accesseurs
    double getVal(){return _val;}
    void setVal(double val){_val=val;}
    virtual void setSign(){_val = -_val;}

    //Héritage de Numerique
    virtual void afficher(std::ostream& f=std::cout) const { f<<_val; }
    LitteraleAbstraite *clone() const;

    //Permet l'affectation Entier-Entier
    Entier& operator=(const Entier& val);
};

Entier operator+( Entier  &a,  Entier  &b);
Entier operator-( Entier  &a,  Entier  &b);
Entier operator*( Entier  &a,  Entier  &b);
Entier operator/( Entier  &a,  Entier  &b);
Entier operator%( Entier  &a,  Entier  &b);

#endif // ENTIER_H
