#ifndef NUMERIQUE_H
#define NUMERIQUE_H

#include "litteraleabstraite.h"




class Numerique : public LitteraleAbstraite {

public :
    //Destructeurs
    virtual ~Numerique(){}
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }

    //Clonage d'une donnee (DUP)
        virtual LitteraleAbstraite* clone() const = 0;
    //Parseur
    virtual QString toString() const=0;

    virtual bool EstNul();

    virtual QString type()=0;

};

#endif // NUMERIQUE_H
