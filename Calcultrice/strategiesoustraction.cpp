#include "strategiesoustraction.h"
#include "strategiemultiplication.h"
#include "strategiedivision.h"

Entier* StrategieSoustraction::Calcul(Entier* l1,Entier* l2){
    FabEntier f;
    return f.Fabriquer(l1->getVal()-l2->getVal());
}

Reel* StrategieSoustraction::Calcul(Reel* l1,Reel* l2){
    FabReel f;
    return f.Fabriquer(l1->getVal()-l2->getVal());
}


Numerique* StrategieSoustraction::Calcul(Complexe* l1,Complexe* l2){

    FabComplexe f;
    StrategieSoustraction c;

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

    //Numerique partie Reelle : soustraction des parties réelles
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

    //Numerique partie Imaginaire: soustraction des parties imaginaires

    if (ei1!=NULL){
        if(ei2!= NULL){
        numI= c.Calcul(ei1,ei2);
        }
        else if(ri2!= NULL){
        numI= c.Calcul(ei1,ri2);
        }
        else if(rai2!= NULL){
        numI= c.Calcul(ei1,rai2);
        }
    }
    if (ri1!=NULL){
        if(ei2!= NULL){
        numI= c.Calcul(ri1,ei2);
        }
        else if(ri2!= NULL){
        numI= c.Calcul(ri1,ri2);
        }
        else if(rai2!= NULL){
        numI= c.Calcul(ri1,rai2);
        }
    }

    if (rai1!=NULL){
        if(ei2!= NULL){
        numI= c.Calcul(rai1,ei2);
        }
        else if(ri2!= NULL){
        numI= c.Calcul(rai1,ri2);
        }
        else if(rai2!= NULL){
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

Reel* StrategieSoustraction::Calcul(Entier* l1,Reel* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()-l2->getVal());

}
Reel* StrategieSoustraction::Calcul(Reel* l1,Entier* l2){

    FabReel f;
    return f.Fabriquer(l1->getVal()-l2->getVal());

}

 Complexe* StrategieSoustraction::Calcul (Entier* l1,Complexe* l2){


     FabComplexe f;
     StrategieSoustraction c;
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

     Numerique* im= dynamic_cast <Numerique*> (l2->getI()->clone());
     return f.Fabriquer(numR,im);





 }

 Complexe* StrategieSoustraction::Calcul(Complexe* l1,Entier* l2){

     FabComplexe f;
     StrategieSoustraction c;
     Numerique* numR;
     Entier* er1;
     Reel* rr1;
     Rationnel* rar1;

     er1=dynamic_cast<Entier*>(l1->getR());
     rr1=dynamic_cast<Reel*>(l1->getR());
     rar1=dynamic_cast<Rationnel*>(l1->getR());

     if (er1 != NULL){
         numR= c.Calcul(er1,l2);
     }
     else if (rr1 != NULL){
         numR= c.Calcul(rr1,l2);
     }
     else if (rar1 != NULL){
         numR= c.Calcul(rar1,l2);
     }

     Numerique* im= dynamic_cast <Numerique*> (l1->getI()->clone());
     return f.Fabriquer(numR,im);





 }

 Complexe* StrategieSoustraction::Calcul(Reel* l1,Complexe* l2){

     FabComplexe f;
     StrategieSoustraction c;
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

     Numerique* im= dynamic_cast <Numerique*> (l2->getI()->clone());
     return f.Fabriquer(numR,im);


 }

 Complexe* StrategieSoustraction::Calcul(Complexe* l1,Reel* l2){

     FabComplexe f;
     StrategieSoustraction c;
     Numerique* numR;
     Entier* er1;
     Reel* rr1;
     Rationnel* rar1;

     er1=dynamic_cast<Entier*>(l1->getR());
     rr1=dynamic_cast<Reel*>(l1->getR());
     rar1=dynamic_cast<Rationnel*>(l1->getR());

     if (er1 != NULL){
         numR= c.Calcul(er1,l2);
     }
     else if (rr1 != NULL){
         numR= c.Calcul(rr1,l2);
     }
     else if (rar1 != NULL){
         numR= c.Calcul(rar1,l2);
     }

     Numerique* im= dynamic_cast <Numerique*> (l1->getI()->clone());
     return f.Fabriquer(numR,im);



 }

Numerique* StrategieSoustraction::Calcul(Rationnel* l1,Rationnel* l2){

    // LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES

        FabRationnel f;
        StrategieMultiplication m;
        StrategieSoustraction a;
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


Numerique* StrategieSoustraction::Calcul(Entier* l1,Rationnel* l2){

    //LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES

        FabRationnel f;
        StrategieMultiplication m;
        StrategieSoustraction a;
        Rationnel* res;
        Entier* res_intermediaire1 = m.Calcul(l1,l2->getDenumerateur());
        Entier* den = dynamic_cast <Entier*> (l2->getDenumerateur()->clone());
        res = f.Fabriquer(a.Calcul(res_intermediaire1,l2->getNumerateur()),den);
        if(res->getDenumerateur()->getVal() == 1){
            FabEntier f;
            Entier* nouv;
            nouv = f.Fabriquer(res->getNumerateur()->getVal());
            delete res;
            return nouv;
        }
        else {return res;}





}

//A refaiire
Numerique* StrategieSoustraction::Calcul(Rationnel* l1,Entier* l2){

    //LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES

        FabRationnel f;
        StrategieMultiplication m;
        StrategieSoustraction a;
        Rationnel* res;
        Entier* res_intermediaire1 = m.Calcul(l2,l1->getDenumerateur());
        Entier* den = dynamic_cast <Entier*> (l1->getDenumerateur()->clone());
        res = f.Fabriquer(a.Calcul(l1->getNumerateur(),res_intermediaire1),den);
        if(res->getDenumerateur()->getVal() == 1){
            FabEntier f;
            Entier* nouv;
            nouv = f.Fabriquer(res->getNumerateur()->getVal());
            delete res;
            return nouv;
        }
        else {return res;}


}


Reel* StrategieSoustraction::Calcul(Reel* l1,Rationnel* l2){
//LIBERATION MEMOIRE DES LITTERALES INTERMEDIAIRES CREES


    StrategieSoustraction a;
    // On n'utilise pas strategie division ici car on veut que la division de deux entiers renvoie un reel
    FabReel f;
    Reel* res_intermediaire = f.Fabriquer((l2->getNumerateur()->getVal())/(l2->getDenumerateur()->getVal()));
    Reel* resultat = a.Calcul(l1,res_intermediaire);
    delete res_intermediaire;
    return resultat;


}

Reel* StrategieSoustraction::Calcul(Rationnel* l1,Reel* l2){

    StrategieSoustraction a;
    FabReel f;
    Reel* res_intermediaire = f.Fabriquer((l1->getNumerateur()->getVal())/(l1->getDenumerateur()->getVal()));
    Reel* resultat= a.Calcul(res_intermediaire,l2);
    delete res_intermediaire;
    return resultat;

}


Complexe* StrategieSoustraction::Calcul(Rationnel* l1,Complexe* l2){

    FabComplexe f;
    StrategieSoustraction c;
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

    Numerique* im= dynamic_cast<Numerique*> (l2->getI()->clone());
    return f.Fabriquer(numR,im);



}

Complexe* StrategieSoustraction::Calcul(Complexe* l1,Rationnel* l2){

    FabComplexe f;
    StrategieSoustraction c;
    Numerique* numR;
    Entier* er2;
    Reel* rr2;
    Rationnel* rar2;

    er2=dynamic_cast<Entier*>(l1->getR());
    rr2=dynamic_cast<Reel*>(l1->getR());
    rar2=dynamic_cast<Rationnel*>(l1->getR());

    if (er2 != NULL){
        numR= c.Calcul(er2,l2);
    }
    else if (rr2 != NULL){
        numR= c.Calcul(rr2,l2);
    }
    else if (rar2 != NULL){
        numR= c.Calcul(rar2,l2);
    }

    Numerique* im= dynamic_cast<Numerique*> (l1->getI()->clone());
    return f.Fabriquer(numR,im);
}








