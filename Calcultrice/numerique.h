#ifndef NUMERIQUE_H
#define NUMERIQUE_H

#include "litteraleabstraite.h"


class Numerique : public LitteraleAbstraite {

public :
    //Destructeurs
    virtual ~Numerique(){}
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }
    //virtual LitteraleAbstraite* clone() const = 0;
    //COMMENTE CAR A DEFINIR DANS COMPLEXE (rend complexe abstraite)

    //inverse le signe d'un Numerique.
    //virtual void setSign() =0;

    //Clonage d'une donnee (DUP)
    virtual LitteraleAbstraite* clone() const = 0;

    virtual bool EstNul();

    //Passage en string pour la pile
    virtual QString toString() const = 0;

    virtual QString type()=0;

    //Permet de vérifier qu'une fonction est positive
    //virtual int isPositive();

};

#endif // NUMERIQUE_H
