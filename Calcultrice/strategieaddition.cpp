#include "strategieaddition.h"

Entier* StrategieAddition::Calcul(Entier* l1,Entier* l2){

    FabEntier f;
    return (f.Fabriquer((l1->getVal())+(l2->getVal())));
}


Reel* StrategieAddition::Calcul(Reel* l1,Reel* l2){


    FabReel f;
    return f.Fabriquer(l1->getVal()+l2->getVal());

}

/*
Numerique* StrategieAddition::Calcul(Rationnel* l1,Rationnel* l2){

    //Il me faut multiplication de deux entiers pour faire





}

*/

Numerique* StrategieAddition::Calcul(Complexe* l1,Complexe* l2){


    FabComplexe f;
    StrategieAddition c;

//Conversion dynamique des pointeurs vers numerique pour pouvoir choisir la bonne strategie de calcul

//Conversion
Numerique* numR;
Numerique* numI;
Entier* er1;
Entier* er2;
Entier* ei1;
Entier* ei2;
Reel* rr1;
Reel* rr2;
Reel* ri1;
Reel* ri2;
Rationnel* rar1;
Rationnel* rar2;
Rationnel* rai1;
Rationnel* rai2;
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
    if(rr2!= NULL){
    numR= c.Calcul(er1,rr2);
    }
    //if(rar2!= NULL){
    //numR= c.Calcul(er1,rar2);
    //}
}
if (rr1!=NULL){
    if(er2!= NULL){
    numR= c.Calcul(rr1,er2);
    }
    if(rr2!= NULL){
    numR= c.Calcul(rr1,rr2);
    }
    //if(rar2!= NULL){
    //numR= c.Calcul(rr1,rar2);
    //}
}

if (rar1!=NULL){
    //if(er2!= NULL){
    //numR= c.Calcul(rar1,er2);
    //}
    //if(rr2!= NULL){
    //numR= c.Calcul(rar1,rr2);
    //}
    //if(rar2!= NULL){
    //numR= c.Calcul(rar1,rar2);
    //}
}

//Numerique partie Imaginaire: addition des parties imaginaires

if (ei1!=NULL){
    if(er2!= NULL){
    numI= c.Calcul(ei1,ei2);
    }
    if(rr2!= NULL){
    numI= c.Calcul(ei1,ri2);
    }
    //if(ra2!= NULL){
    //numI= c.Calcul(ei1,rai2);
    //}
}
if (ri1!=NULL){
    if(er2!= NULL){
    numI= c.Calcul(ri1,ei2);
    }
    if(rr2!= NULL){
    numI= c.Calcul(ri1,ri2);
    }
   // if(ra2!= NULL){
    //numI= c.Calcul(ri1,rai2);
    //}
}

if (rai1!=NULL){
    //if(er2!= NULL){
    //numI= c.Calcul(rai1,ei2);
    //}
    //if(rr2!= NULL){
    //numI= c.Calcul(rai1,ri2);
    //}
    //if(ra2!= NULL){
    //numI= c.Calcul(rai1,rai2);
    //}
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


/*
Expression* StrategieAddition::Calcul(Expression* l1,Expression* l2)=0{

        //Faire une concatenation des deux chaines de charactere
}
*/
Reel* StrategieAddition::Calcul(Entier* l1,Reel* l2){

      FabReel f;
      return f.Fabriquer(l1->getVal()+l2->getVal());
}
/*
Complexe* StrategieAddition::Calcul(Entier* l1,Complexe* l2){

        FabComplexe f;
        StrategieAddition c;
        return f.Fabriquer(c.Calcul(l1,l2->getR()),l2->getI());
}
*/
/*
Rationnel* StrategieAddition::Calcul(Entier* l1,Rationnel* l2){

    // A REFAIRE besoin multiplication
        FabRationnel f;
        Rationnel* res=f.Fabriquer((((l1->getVal())*(l2->getDenominateur())) + l2->getNumerateur()),l2->getDenominateur());
        if (res.getDenominateur==1){
        FabEntier e;
        Entier* ent;
        ent=FabEntier(res->getNumerateur().getVal());
        delete res;
        return res;
        }
        else return res;

}
*/

Reel* StrategieAddition::Calcul(Reel* l1,Entier* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()+l2->getVal());

}

/*
Expression* StrategieAddition::Calcul(Entier* l1,Expression* l2){

            //transfo entier en chaine caractere + concatenation


}
*/
