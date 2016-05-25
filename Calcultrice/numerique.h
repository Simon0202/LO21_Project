#ifndef NUMERIQUE_H
#define NUMERIQUE_H

#include "litteraleabstraite.h"

class Numerique : public LitteraleAbstraite {

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }
    virtual LitteraleAbstraite* clone() const = 0;

    //inverse le signe d'un Numerique.
    virtual void setSign() =0;

};

#endif // NUMERIQUE_H
