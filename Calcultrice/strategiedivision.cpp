#include<cmath>
#include "strategiedivision.h"
#include"strategiemultiplication.h"
#include"strategieaddition.h"
#include"strategiesoustraction.h"

Numerique* StrategieDivision::Calcul(Entier* l1,Entier* l2){

    if (fmod(l1->getVal(),l2->getVal()) == 0){
        FabEntier f;
        return f.Fabriquer((l1->getVal())/(l2->getVal()));
    }
    else{
        FabRationnel f;

        Entier* lit1= dynamic_cast<Entier*>(l1->clone());
        Entier* lit2= dynamic_cast<Entier*>(l2->clone());


        return f.Fabriquer(lit1,lit2);

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
    Entier* den= dynamic_cast <Entier*> (l2->getNumerateur()->clone());
    res = f.Fabriquer(m.Calcul(l1,l2->getDenumerateur()),den);
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
    Entier* num= dynamic_cast <Entier*> (l1->getNumerateur()->clone());
    res = f.Fabriquer(num,m.Calcul(l1->getDenumerateur(),l2));
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

    Entier *er2,*ei2,*ercarre,*eicarre;
    Reel *rr2,*ri2,*rrcarre,*ricarre;
    Rationnel *rar2,*rai2,*rarcarre,*raicarre;



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

Complexe* StrategieDivision::Calcul(Complexe* l1,Reel* l2){

    FabComplexe f;
    StrategieDivision m;
    Numerique* numR;
    Numerique* numI;

    Entier *er2,*ei2,*ercarre,*eicarre;
    Reel *rr2,*ri2,*rrcarre,*ricarre;
    Rationnel *rar2,*rai2,*rarcarre,*raicarre;



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

Complexe* StrategieDivision::Calcul(Complexe* l1,Rationnel* l2){

    FabComplexe f;
    StrategieDivision m;
    Numerique* numR;
    Numerique* numI;

    Entier *er2,*ei2,*ercarre,*eicarre;
    Reel *rr2,*ri2,*rrcarre,*ricarre;
    Rationnel *rar2,*rai2,*rarcarre,*raicarre;



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

Numerique* StrategieDivision::Calcul(Complexe* l1,Complexe* l2){
    //LIBERATION MEMOIRE INTERMEDIAIRE

    FabComplexe f;
    StrategieMultiplication c;
    StrategieAddition a;
    StrategieSoustraction s;
    StrategieDivision d;
    Numerique *numR,*numI,*numR_1,*numR_2,*numI_1,*numI_2 ;

    Entier *er1,*er2,*ei1,*ei2,*eDiviseur;
    Reel *rr1,*rr2,*ri1,*ri2,*rDiviseur;
    Rationnel *rar1,*rar2,*rai1,*rai2,*raDiviseur;

    Entier *enumR1,*enumR2,*enumI1,*enumI2,*ercarre,*eicarre;
    Reel *rnumR1,*rnumR2,*rnumI1,*rnumI2, *rrcarre,*ricarre;
    Rationnel *ranumR1,*ranumR2,*ranumI1,*ranumI2,*rarcarre,*raicarre;



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
        if(er2!= NULL){
        numR_2= c.Calcul(rai1,ei2);
        }
        else if(rr2!= NULL){
        numR_2= c.Calcul(rai1,ri2);
        }
        else if(rai2!= NULL){
        numR_2= c.Calcul(rai1,rai2);
        }
    }

    //------------------------------------------------------------------------------------------------------------------
        // Addition partie reel 1 et 2 pour obtenir partie reel resultat

        enumR1=dynamic_cast<Entier*>(numR_1);
        rnumR1=dynamic_cast<Reel*>(numR_1);
        ranumR1=dynamic_cast<Rationnel*>(numR_1);
        enumR2=dynamic_cast<Entier*>(numR_2);
        rnumR2=dynamic_cast<Reel*>(numR_2);
        ranumR2=dynamic_cast<Rationnel*>(numR_2);



        if (enumR1!=NULL){
            if(enumR2!= NULL){
            numR= a.Calcul(enumR1,enumR2);
            }
            else if(rnumR2!= NULL){
            numR= a.Calcul(enumR1,rnumR2);
            }
            else if(ranumR2!= NULL){
            numR= a.Calcul(enumR1,ranumR2);
            }
        }
        if (rnumR1!=NULL){
            if(enumR2!= NULL){
            numR= a.Calcul(rnumR1,enumR2);
            }
            else if(rnumR2!= NULL){
            numR= a.Calcul(rnumR1,rnumR2);
            }
            else if(ranumR2!= NULL){
            numR= a.Calcul(rnumR1,ranumR2);
            }
        }

        if (ranumR1!=NULL){
            if(enumR2!= NULL){
            numR= a.Calcul(ranumR1,enumR2);
            }
            else if(rnumR2!= NULL){
            numR= a.Calcul(ranumR1,rnumR2);
            }
            else if(ranumR2!= NULL){
            numR= a.Calcul(ranumR1,ranumR2);
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
            //Soustraction pour obtenir partie imaginaire resultat

            enumI1=dynamic_cast<Entier*>(numI_1);
            rnumI1=dynamic_cast<Reel*>(numI_1);
            ranumI1=dynamic_cast<Rationnel*>(numI_1);
            enumI2=dynamic_cast<Entier*>(numI_2);
            rnumI2=dynamic_cast<Reel*>(numI_2);
            ranumI2=dynamic_cast<Rationnel*>(numI_2);



                    if (enumI1!=NULL){
                        if(enumI2!= NULL){
                        numI= s.Calcul(enumI2,enumI1);
                        }
                        else if(rnumI2!= NULL){
                        numI= s.Calcul(rnumI2,enumI1);
                        }
                        else if(ranumI2!= NULL){
                        numI= s.Calcul(ranumI2,enumI1);
                        }
                    }
                    if (rnumI1!=NULL){
                        if(enumI2!= NULL){
                        numI= s.Calcul(enumI2,rnumI1);
                        }
                        else if(rnumI2!= NULL){
                        numI= s.Calcul(rnumI2,rnumI1);
                        }
                        else if(ranumI2!= NULL){
                        numI= s.Calcul(ranumI2,rnumI1);
                        }
                    }

                    if (ranumI1!=NULL){
                        if(enumI2!= NULL){
                        numI= s.Calcul(enumI2,ranumI1);
                        }
                        else if(rnumI2!= NULL){
                        numI= s.Calcul(rnumI2,ranumI1);
                        }
                        else if(ranumI2!= NULL){
                        numI= s.Calcul(ranumI2,ranumI1);
                        }
                    }



        //------------------------------------------------------------------------------------------------------

                    Complexe* res_intermed = f.Fabriquer(numR,numI);
             // Diviseur du complexe partie reel2 au carre + partieim2 au carre




                    Numerique *rcarre,*icarre;

                    if (er2!= NULL){
                        rcarre = c.Calcul(er2,er2);
                    }
                    else if (rr2 != NULL){
                        rcarre = c.Calcul(rr2,rr2);
                    }
                    else if (rar2 != NULL){
                        rcarre = c.Calcul(rar2,rar2);
                    }



                    if (ei2!= NULL){
                        icarre = c.Calcul(er2,er2);
                    }
                    else if (ri2 != NULL){
                        icarre = c.Calcul(rr2,rr2);
                    }
                    else if (rai2 != NULL){
                        icarre = c.Calcul(rar2,rar2);
                    }


                    ercarre=dynamic_cast<Entier*>(rcarre);
                    rrcarre=dynamic_cast<Reel*>(rcarre);
                    rarcarre=dynamic_cast<Rationnel*>(rcarre);
                    eicarre=dynamic_cast<Entier*>(icarre);
                    ricarre=dynamic_cast<Reel*>(icarre);
                    raicarre=dynamic_cast<Rationnel*>(icarre);

                    Numerique* Diviseur;

                    if (ercarre!=NULL){
                        if(eicarre!= NULL){
                        Diviseur= a.Calcul(ercarre,eicarre);
                        }
                        else if(ricarre!= NULL){
                        Diviseur= a.Calcul(ercarre,ricarre);
                        }
                        else if(raicarre!= NULL){
                        Diviseur= a.Calcul(ercarre,raicarre);
                        }
                    }
                    if (rrcarre!=NULL){
                        if(eicarre!= NULL){
                        Diviseur= a.Calcul(ercarre,eicarre);
                        }
                        else if(ricarre!= NULL){
                        Diviseur= a.Calcul(ercarre,ricarre);
                        }
                        else if(raicarre!= NULL){
                        Diviseur= a.Calcul(ercarre,raicarre);
                        }
                    }

                    if (rarcarre!=NULL){
                        if(eicarre!= NULL){
                        Diviseur= a.Calcul(ercarre,eicarre);
                        }
                        else if(ricarre!= NULL){
                        Diviseur= a.Calcul(ercarre,ricarre);
                        }
                        else if(raicarre!= NULL){
                        Diviseur= a.Calcul(ercarre,raicarre);
                        }
                    }


                    Complexe* resultat;

                    eDiviseur=dynamic_cast<Entier*>(Diviseur);
                    rDiviseur=dynamic_cast<Reel*>(Diviseur);
                    raDiviseur=dynamic_cast<Rationnel*>(Diviseur);

                    if (eDiviseur != NULL){
                        resultat= d.Calcul(res_intermed,eDiviseur);
                    }
                    else if(rDiviseur != NULL){
                        resultat= d.Calcul(res_intermed,rDiviseur);
                    }
                    else if(raDiviseur != NULL){
                        resultat= d.Calcul(res_intermed,raDiviseur);
                    }

                    if (resultat->getI()->EstNul()){
                        FabEntier f;
                        Numerique* nouv = resultat->getR();
                        delete resultat;
                        delete numR_1;
                        delete numR_2;
                        delete numI_1;
                        delete numI_2;
                        delete numR;
                        delete numI;
                        delete rcarre;
                        delete icarre;
                        delete Diviseur;
                        delete res_intermed;
                        return nouv;
                    }
                    else{
                        delete numR_1;
                        delete numR_2;
                        delete numI_1;
                        delete numI_2;
                        delete numR;
                        delete numI;
                        delete rcarre;
                        delete icarre;
                        delete Diviseur;
                        delete res_intermed;
                        return resultat;
                    }







}
