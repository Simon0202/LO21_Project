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

    //Accesseurs
    float getVal() const {return _val;}
    void setVal(double val){_val=val;}


    //Héritage de Numerique
    void afficher(std::ostream& f=std::cout) const { f<<_val; }
    virtual LitteraleAbstraite *clone() const;

    //A implémenter dans stratégie
    //virtual void setSign() {_val=(-_val);}

    //Permet l'affectation Reel-Reel
    Reel& operator=(const Reel& n);

    bool EstNul(){return _val==0;}

    QString type(){return "reel";}
};

   Reel operator+( Reel& a,  Reel& b);
   Reel operator-( Reel& a,  Reel& b);
   Reel operator*( Reel& a,  Reel& b);
   Reel operator/( Reel& a,  Reel& b);

#endif // REEL_H
