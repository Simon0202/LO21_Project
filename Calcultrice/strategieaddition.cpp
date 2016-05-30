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
/*
Numerique* StrategieAddition::Calcul(Complexe* l1,Complexe* l2){


    FabComplexe f;
    StrategieAddition c;

//Conversion dynamique des pointeurs vers numerique
// Partie Reel l1

    if (dynamic_cast < Entier* > ( l1->getR()) == NULL){
        if(dynamic_cast < Reel* > ( l1->getR()) == NULL){
            dynamic_cast < Rationnel* > ( l1->getR());
        }
    }

    if (dynamic_cast < Entier* > ( l2->getR()) == NULL){
        if(dynamic_cast < Reel* > ( l2->getR()) == NULL){
            dynamic_cast < Rationnel* > ( l2->getR());
        }
    }

    if (dynamic_cast < Entier* > ( l1->getI()) == NULL){
        if(dynamic_cast < Reel* > ( l1->getI()) == NULL){
            dynamic_cast < Rationnel* > ( l1->getI());
        }
    }

    if (dynamic_cast < Entier* > ( l2->getI()) == NULL){
        if(dynamic_cast < Reel* > ( l2->getI()) == NULL){
            dynamic_cast < Rationnel* > ( l2->getI());
        }
    }




    Complexe* res= f.Fabriquer(c.Calcul(l1->getR(),l2->getR()),c.Calcul(l1->getI(),l2->getI()));
    if(res->getI()->EstNul()){
       Numerique* nouv = res->getR();
       delete res;
       return nouv;
    }
    else{
        return res;
    }



}

*/
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
