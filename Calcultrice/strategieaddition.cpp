#include "strategieaddition.h"
#include "strategiemultiplication.h"
#include"strategiedivision.h"




Entier* StrategieAddition::Calcul(Entier* l1,Entier* l2){

    FabEntier f;
    return f.Fabriquer(l1->getVal()+l2->getVal());
}


Reel* StrategieAddition::Calcul(Reel* l1,Reel* l2){


    FabReel f;
    return f.Fabriquer(l1->getVal()+l2->getVal());

}


Numerique* StrategieAddition::Calcul(Rationnel* l1,Rationnel* l2){
// LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES

    FabRationnel f;
    StrategieMultiplication m;
    StrategieAddition a;
    Rationnel* res;
    Entier* res_intermediaire1 = m.Calcul(l1->getNumerateur(),l2->getDenumerateur());
    Entier* res_intermediaire2 = m.Calcul(l2->getNumerateur(),l1->getDenumerateur());

    res = f.Fabriquer(a.Calcul(res_intermediaire1,res_intermediaire2),m.Calcul(l1->getDenumerateur(), l2->getDenumerateur()));
    if (res->getDenumerateur()->getVal() ==1){

            FabEntier f;
            Entier* nouv;
            nouv = f.Fabriquer(res->getNumerateur()->getVal());
            delete(res);
            delete res_intermediaire1;
            delete res_intermediaire2;
            return nouv;
    }
    else {
    delete res_intermediaire1;
    delete res_intermediaire2;
    return res;
    }




}



Numerique* StrategieAddition::Calcul(Complexe* l1,Complexe* l2){


    FabComplexe f;
    StrategieAddition c;

//Conversion dynamique des pointeurs vers numerique pour pouvoir choisir la bonne strategie de calcul

//Conversion
Numerique *numR,*numI;

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
    else if(rar2!= NULL){
    numR= c.Calcul(er1,rar2);
    }
}
if (rr1!=NULL){
    if(er2!= NULL){
    numR= c.Calcul(rr1,er2);
    }
    else if(rr2!= NULL){
    numR= c.Calcul(rr1,rr2);
    }
    else if(rar2!= NULL){
    numR= c.Calcul(rr1,rar2);
    }
}

if (rar1!=NULL){
    if(er2!= NULL){
    numR= c.Calcul(rar1,er2);
    }
    else if(rr2!= NULL){
    numR= c.Calcul(rar1,rr2);
    }
    else if(rar2!= NULL){
    numR= c.Calcul(rar1,rar2);
    }
}

//Numerique partie Imaginaire: addition des parties imaginaires

if (ei1!=NULL){
    if(er2!= NULL){
    numI= c.Calcul(ei1,ei2);
    }
    else if(rr2!= NULL){
    numI= c.Calcul(ei1,ri2);
    }
    else if(rar2!= NULL){
    numI= c.Calcul(ei1,rai2);
    }
}
if (ri1!=NULL){
    if(er2!= NULL){
    numI= c.Calcul(ri1,ei2);
    }
    else if(rr2!= NULL){
    numI= c.Calcul(ri1,ri2);
    }
    else if(rar2!= NULL){
    numI= c.Calcul(ri1,rai2);
    }
}

if (rai1!=NULL){
    if(er2!= NULL){
    numI= c.Calcul(rai1,ei2);
    }
    else if(rr2!= NULL){
    numI= c.Calcul(rai1,ri2);
    }
    else if(rar2!= NULL){
    numI= c.Calcul(rai1,rai2);
    }
}


    Complexe* res= f.Fabriquer(numR,numI);
    if(res->getI()->EstNul()){
       Numerique* nouv = res->getR();
       delete res;
       return nouv;
    }
    else{
        return res;
    }



}


Reel* StrategieAddition::Calcul(Entier* l1,Reel* l2){

      FabReel f;
      return f.Fabriquer(l1->getVal()+l2->getVal());
}

Reel* StrategieAddition::Calcul(Reel* l1,Entier* l2){

    StrategieAddition c;
    return c.Calcul(l2,l1);

}


Complexe* StrategieAddition::Calcul(Entier* l1,Complexe* l2){

        FabComplexe f;
        StrategieAddition c;
        Numerique* numR;
        Entier* er2;
        Reel* rr2;
        Rationnel* rar2;

        er2=dynamic_cast<Entier*>(l2->getR());
        rr2=dynamic_cast<Reel*>(l2->getR());
        rar2=dynamic_cast<Rationnel*>(l2->getR());

        if (er2 != NULL){
            numR= c.Calcul(l1,er2);
        }
        else if (rr2 != NULL){
            numR= c.Calcul(l1,rr2);
        }
        else if (rar2 != NULL){
            numR= c.Calcul(l1,rar2);
        }



        return f.Fabriquer(numR,l2->getI());
}

Complexe* StrategieAddition::Calcul(Complexe* l1,Entier* l2){
    StrategieAddition c;
    return c.Calcul(l2,l1);
}




Complexe* StrategieAddition::Calcul(Reel* l1,Complexe* l2){

    FabComplexe f;
    StrategieAddition c;
    Numerique* numR;
    Entier* er2;
    Reel* rr2;
    Rationnel* rar2;

    er2=dynamic_cast<Entier*>(l2->getR());
    rr2=dynamic_cast<Reel*>(l2->getR());
    rar2=dynamic_cast<Rationnel*>(l2->getR());

    if (er2 != NULL){
        numR= c.Calcul(l1,er2);
    }
    else if (rr2 != NULL){
        numR= c.Calcul(l1,rr2);
    }
    else if (rar2 != NULL){
        numR= c.Calcul(l1,rar2);
    }


    return f.Fabriquer(numR,l2->getI());


}

Complexe* StrategieAddition::Calcul(Complexe* l1,Reel* l2){

    StrategieAddition c;
    return c.Calcul(l2,l1);

}



Numerique* StrategieAddition::Calcul(Entier* l1,Rationnel* l2){
//LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES

    FabRationnel f;
    StrategieMultiplication m;
    StrategieAddition a;
    Rationnel* res;
    Entier* res_intermediaire1 = m.Calcul(l1,l2->getDenumerateur());
    res = f.Fabriquer(a.Calcul(res_intermediaire1,l2->getNumerateur()),l2->getDenumerateur());
    if(res->getDenumerateur()->getVal() == 1){
        FabEntier f;
        Entier* nouv;
        nouv = f.Fabriquer(res->getNumerateur()->getVal());
        delete res;
        return nouv;
    }
    else {return res;}


}

Numerique* StrategieAddition::Calcul(Rationnel* l1,Entier* l2){

    StrategieAddition a;
    return a.Calcul(l2,l1);

}


Reel* StrategieAddition::Calcul(Reel* l1,Rationnel* l2){
//LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES

    StrategieDivision d;
    StrategieAddition a;
    Numerique* res_intermediaire = d.Calcul(l2->getNumerateur(),l2->getDenumerateur());
    if (dynamic_cast<Entier*>(res_intermediaire) != NULL){
        Entier* e= dynamic_cast<Entier*>(res_intermediaire);
        Reel* res = a.Calcul(l1,e);
        delete e;
        return res;
    }
    else{
        Reel* r = dynamic_cast<Reel*>(res_intermediaire);
        Reel* res = a.Calcul(l1,r);
        delete r;
        return res;
    }


}

Reel* StrategieAddition::Calcul(Rationnel* l1,Reel* l2){

    StrategieAddition a;
    return a.Calcul(l2,l1);

}


Complexe* StrategieAddition::Calcul(Rationnel* l1,Complexe* l2){

    FabComplexe f;
    StrategieAddition c;
    Numerique* numR;
    Entier* er2;
    Reel* rr2;
    Rationnel* rar2;

    er2=dynamic_cast<Entier*>(l2->getR());
    rr2=dynamic_cast<Reel*>(l2->getR());
    rar2=dynamic_cast<Rationnel*>(l2->getR());

    if (er2 != NULL){
        numR= c.Calcul(l1,er2);
    }
    else if (rr2 != NULL){
        numR= c.Calcul(l1,rr2);
    }
    else if (rar2 != NULL){
        numR= c.Calcul(l1,rar2);
    }


    return f.Fabriquer(numR,l2->getI());



}



Complexe* StrategieAddition::Calcul(Complexe* l1,Rationnel* l2){

    StrategieAddition a;
    return a.Calcul(l2,l1);
}
