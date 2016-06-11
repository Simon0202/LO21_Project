#include "fabrique.h"
#include<QDebug>


Entier *FabEntier::Fabriquer(long int e){
    return new Entier(e);
}

Reel* FabReel::Fabriquer(float r){
    return new Reel(r);
}

Complexe* FabComplexe::Fabriquer(Numerique* c1,Numerique* c2){
    return new Complexe(c1,c2);
}

Rationnel* FabRationnel::Fabriquer(Entier* r1, Entier* r2){
    return new Rationnel(r1,r2);
}

