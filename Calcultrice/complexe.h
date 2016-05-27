#ifndef COMPLEXE_H
#define COMPLEXE_H


#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"

class Complexe : public Numerique{
private:
    Numerique *a;
    Numerique *b;

public:
    Complexe();
    Complexe(Numerique *Re,Numerique *Im): a(Re), b(Im){}
    inline void setSign(){a->setSign();b->setSign();}
    //On considere qu'on cree un complexe a partir d'un nombre reel.
    //La partie imaginaire est initialisee a zero. */
    Complexe(Numerique* d);

    //Hériage
    void afficher(std::ostream& f=std::cout) const;
    //Pb de fonction ci dessous
    //virtual Numerique* clone() const;



};

#endif // COMPLEXE_H
