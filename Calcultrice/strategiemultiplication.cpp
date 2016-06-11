#include "strategiemultiplication.h"
#include "strategieaddition.h"
#include "strategiedivision.h"
#include "strategiesoustraction.h"
#include "fabrique.h"


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


 Numerique* StrategieMultiplication::Calcul(Complexe* l1,Complexe* l2){
//LIBERATION MEMOIRE INTERMEDIAIRE

    FabComplexe f;
    StrategieMultiplication c;
    StrategieAddition a;
    StrategieSoustraction s;
    Numerique *numR,*numI,*numR_1,*numR_2,*numI_1,*numI_2 ;


    //Conversion

    Entier *er1,*er2,*ei1,*ei2;
    Reel *rr1,*rr2,*ri1,*ri2;
    Rationnel *rar1,*rar2,*rai1,*rai2;

    Entier *enumR1,*enumR2,*enumI1,*enumI2;
    Reel *rnumR1,*rnumR2,*rnumI1,*rnumI2;
    Rationnel *ranumR1,*ranumR2,*ranumI1,*ranumI2;

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

    //Numerique partie Reelle1 : multiplication des parties réelles
    if (er1!=NULL){
        if(er2!= NULL){
        numR_1= c.Calcul(er1,er2);
        }
        else if(rr2!= NULL){
        numR_1= c.Calcul(er1,rr2);
        }
        else if(rar2!= NULL){
        numR_1= c.Calcul(er1,rar2);
        }
    }
    if (rr1!=NULL){
        if(er2!= NULL){
        numR_1= c.Calcul(rr1,er2);
        }
        else if(rr2!= NULL){
        numR_1= c.Calcul(rr1,rr2);
        }
        else if(rar2!= NULL){
        numR_1= c.Calcul(rr1,rar2);
        }
    }

    if (rar1!=NULL){
        if(er2!= NULL){
        numR_1= c.Calcul(rar1,er2);
        }
        else if(rr2!= NULL){
        numR_1= c.Calcul(rar1,rr2);
        }
        else if(rar2!= NULL){
        numR_1= c.Calcul(rar1,rar2);
        }
    }

    //Numerique partie Reel2: multiplication des parties imaginaires

    if (ei1!=NULL){
        if(ei2!= NULL){
        numR_2= c.Calcul(ei1,ei2);
        }
        else if(ri2!= NULL){
        numR_2= c.Calcul(ei1,ri2);
        }
        else if(rai2!= NULL){
        numR_2= c.Calcul(ei1,rai2);
        }
    }
    if (ri1!=NULL){
        if(ei2!= NULL){
        numR_2= c.Calcul(ri1,ei2);
        }
        else if(ri2!= NULL){
        numR_2= c.Calcul(ri1,ri2);
        }
        else if(rai2!= NULL){
        numR_2= c.Calcul(ri1,rai2);
        }
    }

    if (rai1!=NULL){
        if(ei2!= NULL){
        numR_2= c.Calcul(rai1,ei2);
        }
        else if(ri2!= NULL){
        numR_2= c.Calcul(rai1,ri2);
        }
        else if(rai2!= NULL){
        numR_2= c.Calcul(rai1,rai2);
        }
    }
//------------------------------------------------------------------------------------------------------------------
    // Soustraction partie reel 1 et 2 pour obtenir partie reel resultat

    enumR1=dynamic_cast<Entier*>(numR_1);
    rnumR1=dynamic_cast<Reel*>(numR_1);
    ranumR1=dynamic_cast<Rationnel*>(numR_1);
    enumR2=dynamic_cast<Entier*>(numR_2);
    rnumR2=dynamic_cast<Reel*>(numR_2);
    ranumR2=dynamic_cast<Rationnel*>(numR_2);



    if (enumR1!=NULL){
        if(enumR2!= NULL){
        numR= s.Calcul(enumR1,enumR2);
        }
        else if(rnumR2!= NULL){
        numR= s.Calcul(enumR1,rnumR2);
        }
        else if(ranumR2!= NULL){
        numR= s.Calcul(enumR1,ranumR2);
        }
    }
    if (rnumR1!=NULL){
        if(enumR2!= NULL){
        numR= s.Calcul(rnumR1,enumR2);
        }
        else if(rnumR2!= NULL){
        numR= s.Calcul(rnumR1,rnumR2);
        }
        else if(ranumR2!= NULL){
        numR= s.Calcul(rnumR1,ranumR2);
        }
    }

    if (ranumR1!=NULL){
        if(enumR2!= NULL){
        numR= s.Calcul(ranumR1,enumR2);
        }
        else if(rnumR2!= NULL){
        numR= s.Calcul(ranumR1,rnumR2);
        }
        else if(ranumR2!= NULL){
        numR= s.Calcul(ranumR1,ranumR2);
        }
    }



//------------------------------------------------------------------------------------------------------------------





    //Numerique partie Imaginaire1 : multiplication r1 et i2

    if (er1!=NULL){
        if(ei2!= NULL){
        numI_1= c.Calcul(er1,ei2);
        }
        else if(ri2!= NULL){
        numI_1= c.Calcul(er1,ri2);
        }
        else if(rai2!= NULL){
        numI_1= c.Calcul(er1,rai2);
        }
    }
    if (rr1!=NULL){
        if(ei2!= NULL){
        numI_1= c.Calcul(rr1,ei2);
        }
        else if(ri2!= NULL){
        numI_1= c.Calcul(rr1,ri2);
        }
        else if(rai2!= NULL){
        numI_1= c.Calcul(rr1,rai2);
        }
    }

    if (rar1!=NULL){
        if(ei2!= NULL){
        numI_1= c.Calcul(rar1,ei2);
        }
        else if(ri2!= NULL){
        numI_1= c.Calcul(rar1,ri2);
        }
        else if(rai2!= NULL){
        numI_1= c.Calcul(rar1,rai2);
        }
    }

    //Numerique partie Imaginaire2: multiplication i1 et r2

    if (ei1!=NULL){
        if(er2!= NULL){
        numI_2= c.Calcul(ei1,er2);
        }
        else if(rr2!= NULL){
        numI_2= c.Calcul(ei1,rr2);
        }
        else if(rar2!= NULL){
        numI_2= c.Calcul(ei1,rar2);
        }
    }
    if (ri1!=NULL){
        if(er2!= NULL){
        numI_2= c.Calcul(ri1,er2);
        }
        else if(rr2!= NULL){
        numI_2= c.Calcul(ri1,rr2);
        }
        else if(rar2!= NULL){
        numI_2= c.Calcul(ri1,rar2);
        }
    }

    if (rai1!=NULL){
        if(er2!= NULL){
        numI_2= c.Calcul(rai1,er2);
        }
        else if(rr2!= NULL){
        numI_2= c.Calcul(rai1,rr2);
        }
        else if(rar2!= NULL){
        numI_2= c.Calcul(rai1,rar2);
        }
    }
//------------------------------------------------------------------------------------------------------------------
    //Addition pour obtenir partie imaginaire resultat

    enumI1=dynamic_cast<Entier*>(numI_1);
    rnumI1=dynamic_cast<Reel*>(numI_1);
    ranumI1=dynamic_cast<Rationnel*>(numI_1);
    enumI2=dynamic_cast<Entier*>(numI_2);
    rnumI2=dynamic_cast<Reel*>(numI_2);
    ranumI2=dynamic_cast<Rationnel*>(numI_2);



            if (enumI1!=NULL){
                if(enumI2!= NULL){
                numI= a.Calcul(enumI1,enumI2);
                }
                else if(rnumI2!= NULL){
                numI= a.Calcul(enumI1,rnumI2);
                }
                else if(ranumI2!= NULL){
                numI= a.Calcul(enumI1,ranumI2);
                }
            }
            if (rnumI1!=NULL){
                if(enumI2!= NULL){
                numI= a.Calcul(rnumI1,enumI2);
                }
                else if(rnumI2!= NULL){
                numI= a.Calcul(rnumI1,rnumI2);
                }
                else if(ranumI2!= NULL){
                numI= a.Calcul(rnumI1,ranumI2);
                }
            }

            if (ranumI1!=NULL){
                if(enumI2!= NULL){
                numI= a.Calcul(ranumI1,enumI2);
                }
                else if(rnumI2!= NULL){
                numI= a.Calcul(ranumI1,rnumI2);
                }
                else if(ranumI2!= NULL){
                numI= a.Calcul(ranumI1,ranumI2);
                }
            }



//------------------------------------------------------------------------------------------------------------------
        Complexe* res = f.Fabriquer(numR,numI);

        if(res->getI()->EstNul()){

            Numerique* nouv = dynamic_cast<Numerique*>(res->getR()->clone());
            delete res;
            delete numR_1;
            delete numR_2;
            delete numI_1;
            delete numI_2;
            return nouv;

        }
        delete numR_1;
        delete numR_2;
        delete numI_1;
        delete numI_2;
        return res;

}



Rationnel* StrategieMultiplication::Calcul(Entier* l1,Rationnel* l2){

    FabRationnel f;
    StrategieMultiplication s;

    Entier* den = dynamic_cast<Entier*> (l2->getDenumerateur()->clone());
    return f.Fabriquer(s.Calcul(l1,l2->getNumerateur()),den);



}

Rationnel* StrategieMultiplication::Calcul(Rationnel* l1,Entier* l2){

    StrategieMultiplication s;
    return s.Calcul(l2,l1);

}


Reel* StrategieMultiplication::Calcul(Reel* l1,Rationnel* l2){
//LIBERATION MEMOIRE INTERMEDIAIRE


    StrategieMultiplication a;
    // Ici on n'utilise pas strattegie divise car on veut que le resultat de la division soit un entier
    FabReel f;
    Reel* res_intermediaire = f.Fabriquer(l2->getNumerateur()->getVal()/l2->getDenumerateur()->getVal());
    Reel* res= a.Calcul(l1,res_intermediaire);
    delete res_intermediaire;
    return res;

}

Reel* StrategieMultiplication::Calcul(Rationnel* l1,Reel* l2){

    StrategieMultiplication s;
    return s.Calcul(l2,l1);

}

Complexe* StrategieMultiplication::Calcul(Entier* l1,Complexe* l2){

    FabComplexe f;
    StrategieMultiplication m;
    Numerique* numR;
    Numerique* numI;

    Entier *er2,*ei2;
    Reel *rr2,*ri2;
    Rationnel *rar2,*rai2;


    er2=dynamic_cast<Entier*>(l2->getR());
    ei2=dynamic_cast<Entier*>(l2->getI());
    rr2=dynamic_cast<Reel*>(l2->getR());
    ri2=dynamic_cast<Reel*>(l2->getI());
    rar2=dynamic_cast<Rationnel*>(l2->getR());
    rai2=dynamic_cast<Rationnel*>(l2->getI());


        if (er2!=NULL){
        numR= m.Calcul(l1,er2);
        }
        else if(rr2!= NULL){
        numR= m.Calcul(l1,rr2);
        }
        else if(rar2!= NULL){
        numR= m.Calcul(l1,rar2);
        }


        if (ei2!=NULL){
        numI= m.Calcul(l1,ei2);
        }
        else if(ri2!= NULL){
        numI= m.Calcul(l1,ri2);
        }
        else if(rai2!= NULL){
        numI= m.Calcul(l1,rai2);
        }

    return f.Fabriquer(numR,numI);


}

Complexe* StrategieMultiplication::Calcul(Complexe* l1,Entier* l2){

    StrategieMultiplication m;
    return m.Calcul(l2,l1);

}

Complexe* StrategieMultiplication::Calcul(Reel* l1,Complexe* l2){

    FabComplexe f;
    StrategieMultiplication m;
    Numerique* numR;
    Numerique* numI;

    Entier *er2,*ei2;
    Reel *rr2,*ri2;
    Rationnel *rar2,*rai2;


    er2=dynamic_cast<Entier*>(l2->getR());
    ei2=dynamic_cast<Entier*>(l2->getI());
    rr2=dynamic_cast<Reel*>(l2->getR());
    ri2=dynamic_cast<Reel*>(l2->getI());
    rar2=dynamic_cast<Rationnel*>(l2->getR());
    rai2=dynamic_cast<Rationnel*>(l2->getI());


        if (er2!=NULL){
        numR= m.Calcul(l1,er2);
        }
        else if(rr2!= NULL){
        numR= m.Calcul(l1,rr2);
        }
        else if(rar2!= NULL){
        numR= m.Calcul(l1,rar2);
        }


        if (ei2!=NULL){
        numI= m.Calcul(l1,ei2);
        }
        else if(ri2!= NULL){
        numI= m.Calcul(l1,ri2);
        }
        else if(rai2!= NULL){
        numI= m.Calcul(l1,rai2);
        }

    return f.Fabriquer(numR,numI);


}

Complexe* StrategieMultiplication::Calcul(Complexe* l1,Reel* l2){

    StrategieMultiplication m;
    return m.Calcul(l2,l1);
}

Complexe* StrategieMultiplication::Calcul(Rationnel* l1,Complexe* l2){

    FabComplexe f;
    StrategieMultiplication m;
    Numerique* numR;
    Numerique* numI;

    Entier *er2,*ei2;
    Reel *rr2,*ri2;
    Rationnel *rar2,*rai2;


    er2=dynamic_cast<Entier*>(l2->getR());
    ei2=dynamic_cast<Entier*>(l2->getI());
    rr2=dynamic_cast<Reel*>(l2->getR());
    ri2=dynamic_cast<Reel*>(l2->getI());
    rar2=dynamic_cast<Rationnel*>(l2->getR());
    rai2=dynamic_cast<Rationnel*>(l2->getI());


        if (er2!=NULL){
        numR= m.Calcul(l1,er2);
        }
        else if(rr2!= NULL){
        numR= m.Calcul(l1,rr2);
        }
        else if(rar2!= NULL){
        numR= m.Calcul(l1,rar2);
        }


        if (ei2!=NULL){
        numI= m.Calcul(l1,ei2);
        }
        else if(ri2!= NULL){
        numI= m.Calcul(l1,ri2);
        }
        else if(rai2!= NULL){
        numI= m.Calcul(l1,rai2);
        }

    return f.Fabriquer(numR,numI);



}

Complexe* StrategieMultiplication::Calcul(Complexe* l1,Rationnel* l2){

    StrategieMultiplication m;
    return m.Calcul(l2,l1);

}












