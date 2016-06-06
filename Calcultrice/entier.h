#ifndef ENTIER_H
#define ENTIER_H

#include "numerique.h"
#include <QDebug>

class Entier : public Numerique
{
private:
    long int _val;
public:
    //conversion implicite lors de l'initialisation de l'attribut.
    Entier(double val=1):_val(val){}
    Entier(const QString& s):_val(s.toInt()){};



    //Accesseurs
    double getVal(){return _val;}
    void setVal(double val){_val=val;}


    //Héritage de Numerique
    virtual void afficher(std::ostream& f=std::cout) const { f<<_val; }
    LitteraleAbstraite *clone() const;
    //virtual void setSign(){_val = -_val;}
    virtual QString toString() const;

    //Permet l'affectation Entier-Entier
    Entier& operator=(const Entier& val);

    bool EstNul(){return _val==0;}

    QString type(){return "entier";}
};
/*
Entier operator+( Entier  &a,  Entier  &b);
Entier operator-( Entier  &a,  Entier  &b);
Entier operator*( Entier  &a,  Entier  &b);
Entier operator/( Entier  &a,  Entier  &b);
Entier operator%( Entier  &a,  Entier  &b);
*/
#endif // ENTIER_H
