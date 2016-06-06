#include "strategiedivision.h"
#include<cmath>

#include"strategiemultiplication.h"

Numerique* StrategieDivision::Calcul(Entier* l1,Entier* l2){

    if (fmod(l1->getVal(),l2->getVal()) == 0){
        FabEntier f;
        return f.Fabriquer((l1->getVal())/(l2->getVal()));
    }
    else{
        FabRationnel f;
        return f.Fabriquer(l1,l2);

    }


}

Reel* StrategieDivision::Calcul(Reel* l1,Reel* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()/l2->getVal());


}


Numerique* StrategieDivision::Calcul(Rationnel* l1,Rationnel* l2){

    FabRationnel f;
    StrategieMultiplication m;
    Rationnel* res = f.Fabriquer(m.Calcul(l1->getNumerateur(),l2->getDenumerateur()),m.Calcul(l1->getDenumerateur(),l2->getNumerateur()));
    if (res->getDenumerateur()->getVal() == 1){
        FabEntier e;
        Entier* nouv = e.Fabriquer(res->getNumerateur()->getVal());
        delete res;
        return nouv;
    }
    else{
        return res;
    }

}


Reel* StrategieDivision::Calcul(Entier* l1,Reel* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()/l2->getVal());


}

Reel* StrategieDivision::Calcul(Reel* l1,Entier* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()/l2->getVal());


}



Numerique* StrategieDivision::Calcul(Entier* l1,Rationnel* l2){

    FabRationnel f;
    StrategieMultiplication m;
    Rationnel* res;
    res = f.Fabriquer(m.Calcul(l1,l2->getDenumerateur()),l2->getNumerateur());
    if (res->getDenumerateur()->getVal() ==1){
        FabEntier e;
        Entier* nouv;
        nouv = e.Fabriquer(res->getNumerateur()->getVal());
        delete res;
        return nouv;
    }
    else {return res;}


}


Numerique* StrategieDivision::Calcul(Rationnel* l1,Entier* l2){

    FabRationnel f;
    StrategieMultiplication m;
    Rationnel* res;
    res = f.Fabriquer(l1->getNumerateur(),m.Calcul(l1->getDenumerateur(),l2));
    if (res->getDenumerateur()->getVal() ==1){
        FabEntier e;
        Entier* nouv;
        nouv = e.Fabriquer(res->getNumerateur()->getVal());
        delete res;
        return nouv;
    }
    else {return res;}

}



Reel* StrategieDivision::Calcul(Reel* l1,Rationnel* l2){

    StrategieDivision d;
    Numerique* res_intermediaire = d.Calcul(l2->getNumerateur(),l2->getDenumerateur());
    if (dynamic_cast<Entier*>(res_intermediaire) != NULL){
        Entier* e= dynamic_cast<Entier*>(res_intermediaire);
        Reel* res = d.Calcul(l1,e);
        delete e;
        return res;
    }
    else{
        Reel* r = dynamic_cast<Reel*>(res_intermediaire);
        Reel* res = d.Calcul(l1,r);
        delete r;
        return res;
    }



}

Reel* StrategieDivision::Calcul(Rationnel* l1,Reel* l2){

    StrategieDivision d;
    Numerique* res_intermediaire = d.Calcul(l1->getNumerateur(),l1->getDenumerateur());
    if (dynamic_cast<Entier*>(res_intermediaire) != NULL){
        Entier* e= dynamic_cast<Entier*>(res_intermediaire);
        Reel* res = d.Calcul(e,l2);
        delete e;
        return res;
    }
    else{
        Reel* r = dynamic_cast<Reel*>(res_intermediaire);
        Reel* res = d.Calcul(r,l2);
        delete r;
        return res;
    }


}

Complexe* StrategieDivision::Calcul(Complexe* l1,Entier* l2){

    FabComplexe f;
    StrategieDivision m;
    Numerique* numR;
    Numerique* numI;

    Entier *er2,*ei2;
    Reel *rr2,*ri2;
    Rationnel *rar2,*rai2;


    er2=dynamic_cast<Entier*>(l1->getR());
    ei2=dynamic_cast<Entier*>(l1->getI());
    rr2=dynamic_cast<Reel*>(l1->getR());
    ri2=dynamic_cast<Reel*>(l1->getI());
    rar2=dynamic_cast<Rationnel*>(l1->getR());
    rai2=dynamic_cast<Rationnel*>(l1->getI());


        if (er2!=NULL){
        numR= m.Calcul(er2,l2);
        }
        else if(rr2!= NULL){
        numR= m.Calcul(rr2,l2);
        }
        else if(rar2!= NULL){
        numR= m.Calcul(rar2,l2);
        }


        if (ei2!=NULL){
        numI= m.Calcul(ei2,l2);
        }
        else if(ri2!= NULL){
        numI= m.Calcul(ri2,l2);
        }
        else if(rai2!= NULL){
        numI= m.Calcul(rai2,l2);
        }

    return f.Fabriquer(numR,numI);




}

