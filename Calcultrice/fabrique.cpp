#include "fabrique.h"
#include<QDebug>


<<<<<<< HEAD
//LitteraleAbstraite* FabEntier::creer(QString c)

Entier *FabEntier::Fabriquer(long int i){
    qDebug()<<"valeur du i "<< i;
    return new Entier(i);
=======
Entier *FabEntier::Fabriquer(long int e){
    return new Entier(e);
>>>>>>> acc948888ee0b6947a95eb6ec601ff1f85d7dac0
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

