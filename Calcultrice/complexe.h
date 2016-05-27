#ifndef COMPLEXE_H
#define COMPLEXE_H


#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"

//Rajouter un destructeur

class Complexe : public Numerique{
private:
    Numerique *a;
    Numerique *b;

public:
    Complexe();
    Complexe(Numerique *Re,Numerique *Im): a(Re), b(Im){}

    //A implémenter dans stratégie
    //inline void setSign(){a->setSign();b->setSign();}
    //On cree un complexe a partir d'un nombre reel et on met b a zero. */
    //A revoir
    //Complexe(Numerique* d);

    //Héritage
    void afficher(std::ostream& f=std::cout) const;


    //***Pb de fonction ci dessous
    //virtual Numerique* clone() const;
    //virtual void setSign();



};

#endif // COMPLEXE_H
