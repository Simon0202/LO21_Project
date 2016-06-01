#include "strategiemultiplication.h"

#include"strategiecalcul.h"
#include"strategieaddition.h"
#include"strategiesoustraction.h"


Entier* StrategieMultiplication::Calcul(Entier* l1,Entier* l2){

    FabEntier f;
    return f.Fabriquer(l1->getVal()*l2->getVal());


}

Reel* StrategieMultiplication::Calcul(Reel* l1,Reel* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()*l2->getVal());

}

Reel* StrategieMultiplication::Calcul(Entier* l1,Reel* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()*l2->getVal());

}
Reel* StrategieMultiplication::Calcul(Reel* l1,Entier* l2){

    StrategieMultiplication c;
    return c.Calcul(l2,l1);

}

Numerique* StrategieMultiplication::Calcul(Rationnel* l1,Rationnel* l2){

    FabRationnel f;
    Rationnel* res;
    StrategieMultiplication m;
    res=f.Fabriquer(m.Calcul(l1->getNumerateur(),l2->getNumerateur()),m.Calcul(l1->getDenumerateur(),l2->getDenumerateur()));
    if (res->getDenumerateur()->getVal() == 1){
        FabEntier e;
        Entier* nouv;
        nouv = e.Fabriquer(res->getNumerateur()->getVal());
        delete res;
        return nouv;
    }
    else {
        return res;
    }

}

/*
 Numerique* Calcul(Complexe* l1,Complexe* l2){

    FabComplexe f;
    StrategieMultiplication m;
    StrategieAddition a;
    StrategieSoustraction s;

    //Conversion
    Entier *er1,*er2,*ei1,*ei2;
    Reel *rr1,*rr2,*ri1,*ri2;
    Rationnel *rar1,*rar2,*rai1,*rai2;
    er1=dynamic_cast<Entier*>(l1->getR());
    er2=dynamic_cast<Entier*>(l2->getR());
    ei1=dynamic_cast<Entier*>(l1->getI());
    ei2=dynamic_cast<Entier*>(l2->getI());
    rr1=dynamic_cast<Reel*>(l1->getR());
    rr2=dynamic_cast<Reel*>(l2->getR());
    ri1=dynamic_cast<Reel*>(l1->getI());
    ri2=dynamic_cast<Reel*>(l2->getI());
    rar1=dynamic_cast<Rationnel*>(l1->getR());
    rar2=dynamic_cast<Rationnel*>(l2->getR());
    rai1=dynamic_cast<Rationnel*>(l1->getI());
    rai2=dynamic_cast<Rationnel*>(l2->getI());

    //Numerique partie Reelle : addition des parties réelles
    if (er1!=NULL){
        if(er2!= NULL){
        numR= c.Calcul(er1,er2);
        }
        else if(rr2!= NULL){
        numR= c.Calcul(er1,rr2);
        }
        //else if(rar2!= NULL){
        //numR= c.Calcul(er1,rar2);
        //}
    }
    if (rr1!=NULL){
        if(er2!= NULL){
        numR= c.Calcul(rr1,er2);
        }
        else if(rr2!= NULL){
        numR= c.Calcul(rr1,rr2);
        }
        //else if(rar2!= NULL){
        //numR= c.Calcul(rr1,rar2);
        //}
    }

    if (rar1!=NULL){
        //if(er2!= NULL){
        //numR= c.Calcul(rar1,er2);
        //}
        //else if(rr2!= NULL){
        //numR= c.Calcul(rar1,rr2);
        //}
        //else if(rar2!= NULL){
        //numR= c.Calcul(rar1,rar2);
        //}
    }

    //Numerique partie Imaginaire: addition des parties imaginaires

    if (ei1!=NULL){
        if(er2!= NULL){
        numI= c.Calcul(ei1,ei2);
        }
        else if(rr2!= NULL){
        numI= c.Calcul(ei1,ri2);
        }
        //else if(ra2!= NULL){
        //numI= c.Calcul(ei1,rai2);
        //}
    }
    if (ri1!=NULL){
        if(er2!= NULL){
        numI= c.Calcul(ri1,ei2);
        }
        else if(rr2!= NULL){
        numI= c.Calcul(ri1,ri2);
        }
       //else if(ra2!= NULL){
        //numI= c.Calcul(ri1,rai2);
        //}
    }

    if (rai1!=NULL){
        //if(er2!= NULL){
        //numI= c.Calcul(rai1,ei2);
        //}
        //else if(rr2!= NULL){
        //numI= c.Calcul(rai1,ri2);
        //}
        //else if(ra2!= NULL){
        //numI= c.Calcul(rai1,rai2);
        //}
    }





 }

*/










