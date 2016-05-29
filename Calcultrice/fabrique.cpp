#include"fabrique.h"

//virtual const LitteraleAbstraite* FabEntier::creer(QString c)

Entier *FabEntier::Fabriquer(long int i){
    return new Entier(i);
}


//virtual const LitteraleAbstraite* FabReel::creer(QString c);

Reel* FabReel::Fabriquer(float r){
    return new Reel(r);
}

//virtual const LitteraleAbstraite* FabComplexe::creer(QString c);

Complexe* FabComplexe::Fabriquer(Numerique* l1,Numerique* l2){
    return new Complexe(l1,l2);
}

//virtual const LitteraleAbstraite* FabRationnel::creer(QString c);

Rationnel* FabRationnel::Fabriquer(Entier* l1, Entier* l2){
    return new Rationnel(l1,l2);
}

