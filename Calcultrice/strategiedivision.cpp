#include "strategiedivision.h"
#include<cmath>

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
