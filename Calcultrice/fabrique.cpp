#include "fabrique.h"


//LitteraleAbstraite* FabEntier::creer(QString c)

Entier *FabEntier::Fabriquer(long int i){
    return new Entier(i);
}


//LitteraleAbstraite* FabReel::creer(QString c);

Reel* FabReel::Fabriquer(float r){
    return new Reel(r);
}

//LitteraleAbstraite* FabComplexe::creer(QString c);

Complexe* FabComplexe::Fabriquer(Numerique* l1,Numerique* l2){
    return new Complexe(l1,l2);
}

//LitteraleAbstraite* FabRationnel::creer(QString c);

Rationnel* FabRationnel::Fabriquer(Entier* l1, Entier* l2){
    return new Rationnel(l1,l2);
}

