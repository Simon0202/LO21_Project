#ifndef COMPLEXE_H
#define COMPLEXE_H


#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"

//Rajouter un destructeur

class Complexe : public Numerique{
private:
    Numerique* R;
    Numerique* I;

public:
    Complexe();
    Complexe(Numerique *Re,Numerique *Im): R(Re), I(Im){}

    Numerique* getI() {return I;}
    Numerique* getR() {return R;}

    virtual QString type(){return "complexe";}
    //A implémenter dans stratégie
    //inline void setSign(){a->setSign();b->setSign();}
    //On cree un complexe a partir d'un nombre reel et on met b a zero. */
    //A revoir
    //Complexe(Numerique* d);

    //Héritage
    void afficher(std::ostream& f=std::cout) const{//a revoir fait beuguer appli, dit que afficher ne peut etre redefinit alors que la def est dans le cpp..
    }


    //***Pb de fonction ci dessous
    virtual Numerique* clone() const{// a definir (rend la classe complexe abstraite si non definie)
    }
    //virtual void setSign();

    bool EstNul(){return (R->EstNul() && I->EstNul());}



};

#endif // COMPLEXE_H
