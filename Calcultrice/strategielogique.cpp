#include "strategielogique.h"

#include "litteraleabstraite.h"
#include"entier.h"
#include"reel.h"
#include"rationnel.h"
#include "complexe.h"
#include "strategiedivision.h"
#include"fabrique.h"


 Entier* StrategieLogiqueEgal::Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y){

     FabEntier f;
     Entier *ex,*ey;
     Reel* rx,*ry;
     Rationnel *rax,*ray;
     Complexe *cx,*cy;
     bool res;


     ex= dynamic_cast<Entier*>(x);
     rx= dynamic_cast<Reel*>(x);
     rax= dynamic_cast<Rationnel*>(x);
     cx= dynamic_cast<Complexe*>(x);

     ey= dynamic_cast<Entier*>(y);
     ry= dynamic_cast<Reel*>(y);
     ray= dynamic_cast<Rationnel*>(y);
     cy= dynamic_cast<Complexe*>(y);




         if (ex!=NULL){
             if(ey!= NULL){
                 res= (ex->getVal() == ey->getVal());
             }
             else if(ry!= NULL){
                 res= (ex->getVal() == ry->getVal());
             }
             else if(ray!= NULL){
                 res= 0;
             }
             else { //cy !=NULL
                 res= 0;
             }
         }
         if (rx!=NULL){

             if(ry!= NULL){
                 res= (rx->getVal() == ry->getVal());
             }
             else if(ray!= NULL){
                 float fl= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());
                 res= (rx->getVal() == fl);
             }
             else { //cy !=NULL
                 res= 0;
             }

         }
         if (rax!=NULL){

             if(ray!= NULL){
                 float fl1= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                 float fl2= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());

                 res= (fl1 == fl2);
             }
             else { //cy !=NULL
                 res= 0;
             }

         }
         if (cx!=NULL){
             if(cy!= NULL){
                 StrategieLogiqueEgal l;
                 Entier *comp1,*comp2;
                 comp1=l.Comparer(cx->getR(),cy->getR());
                 comp2=l.Comparer(cx->getI(),cy->getI());
                 res= (comp1->getVal() && comp2->getVal());
                 delete comp1;
                 delete comp2;
             }

         }




         if (res==0){return (f.Fabriquer(0));}
         if (res==1){return (f.Fabriquer(1));}


}



Entier* StrategieLogiqueInegal::Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y){

    FabEntier f;
    Entier *ex,*ey;
    Reel* rx,*ry;
    Rationnel *rax,*ray;
    Complexe *cx,*cy;
    bool res;


    ex= dynamic_cast<Entier*>(x);
    rx= dynamic_cast<Reel*>(x);
    rax= dynamic_cast<Rationnel*>(x);
    cx= dynamic_cast<Complexe*>(x);

    ey= dynamic_cast<Entier*>(y);
    ry= dynamic_cast<Reel*>(y);
    ray= dynamic_cast<Rationnel*>(y);
    cy= dynamic_cast<Complexe*>(y);




        if (ex!=NULL){
            if(ey!= NULL){
                res= (ex->getVal() != ey->getVal());
            }
            else if(ry!= NULL){
                res= (ex->getVal() != ry->getVal());
            }
            else if(ray!= NULL){
                res= 0;
            }
            else { //cy !=NULL
                res= 0;
            }
        }
        if (rx!=NULL){

            if(ry!= NULL){
                res= (rx->getVal() != ry->getVal());
            }
            else if(ray!= NULL){
                float fl= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());
                res= (rx->getVal() != fl);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (rax!=NULL){

            if(ray!= NULL){
                float fl1= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                float fl2= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());

                res= (fl1 != fl2);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (cx!=NULL){
            if(cy!= NULL){
                StrategieLogiqueEgal l;
                Entier *comp1,*comp2;
                comp1=l.Comparer(cx->getR(),cy->getR());
                comp2=l.Comparer(cx->getI(),cy->getI());
                res= (comp1->getVal() && comp2->getVal());
                delete comp1;
                delete comp2;

            }

        }




        if (res==0){return (f.Fabriquer(0));}
        if (res==1){return (f.Fabriquer(1));}


}



Entier* StrategieLogiqueInf::Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y){

    FabEntier f;
    Entier *ex,*ey;
    Reel* rx,*ry;
    Rationnel *rax,*ray;
    Complexe *cx,*cy;
    bool res;


    ex= dynamic_cast<Entier*>(x);
    rx= dynamic_cast<Reel*>(x);
    rax= dynamic_cast<Rationnel*>(x);
    cx= dynamic_cast<Complexe*>(x);

    ey= dynamic_cast<Entier*>(y);
    ry= dynamic_cast<Reel*>(y);
    ray= dynamic_cast<Rationnel*>(y);
    cy= dynamic_cast<Complexe*>(y);




        if (ex!=NULL){
            if(ey!= NULL){
                res= (ex->getVal() < ey->getVal());
            }
            else if(ry!= NULL){
                res= (ex->getVal() < ry->getVal());
            }
            else if(ray!= NULL){
                res= 0;
            }
            else { //cy !=NULL
                res= 0;
            }
        }
        if (rx!=NULL){

            if(ey!= NULL){
                res= (rx->getVal() < ey->getVal());
            }
            if(ry!= NULL){
                res= (rx->getVal() < ry->getVal());
            }
            else if(ray!= NULL){
                float fl= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());
                res= (rx->getVal() < fl);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (rax!=NULL){

            if(ey!= NULL){
                res= 0;
            }
            if(ry!= NULL){
                float fl= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                res= (fl < ry->getVal());
            }
            if(ray!= NULL){
                float fl1= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                float fl2= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());

                res= (fl1 < fl2);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (cx!=NULL){
            if(ey!= NULL){
                res= 0;
            }
            if(ry!= NULL){
                res= 0;
            }
            else if(ray!= NULL){
                res= 0;
            }
            else{ //cy != NULL
                StrategieLogiqueEgal l;
                Entier *comp1,*comp2;
                comp1=l.Comparer(cx->getR(),cy->getR());
                comp2=l.Comparer(cx->getI(),cy->getI());
                res= (comp1->getVal() && comp2->getVal());
                delete comp1;
                delete comp2;

            }

        }




        if (res==0){return (f.Fabriquer(0));}
        if (res==1){return (f.Fabriquer(1));}




}

Entier* StrategieLogiqueInfEg::Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y){

    FabEntier f;
    Entier *ex,*ey;
    Reel* rx,*ry;
    Rationnel *rax,*ray;
    Complexe *cx,*cy;
    bool res;


    ex= dynamic_cast<Entier*>(x);
    rx= dynamic_cast<Reel*>(x);
    rax= dynamic_cast<Rationnel*>(x);
    cx= dynamic_cast<Complexe*>(x);

    ey= dynamic_cast<Entier*>(y);
    ry= dynamic_cast<Reel*>(y);
    ray= dynamic_cast<Rationnel*>(y);
    cy= dynamic_cast<Complexe*>(y);




        if (ex!=NULL){
            if(ey!= NULL){
                res= (ex->getVal() <= ey->getVal());
            }
            else if(ry!= NULL){
                res= (ex->getVal() <= ry->getVal());
            }
            else if(ray!= NULL){
                res= 0;
            }
            else { //cy !=NULL
                res= 0;
            }
        }
        if (rx!=NULL){

            if(ey!= NULL){
                res= (rx->getVal() <= ey->getVal());
            }
            if(ry!= NULL){
                res= (rx->getVal() <= ry->getVal());
            }
            else if(ray!= NULL){
                float fl= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());
                res= (rx->getVal() <= fl);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (rax!=NULL){

            if(ey!= NULL){
                res= 0;
            }
            if(ry!= NULL){
                float fl = (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                res= (fl <= ry->getVal());
            }
            if(ray!= NULL){
                float fl1= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                float fl2= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());

                res= (fl1 <= fl2);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (cx!=NULL){
            if(ey!= NULL){
                res= 0;
            }
            if(ry!= NULL){
                res= 0;
            }
            else if(ray!= NULL){
                res=0;
            }
            else{ //cy != NULL
                StrategieLogiqueEgal l;
                Entier *comp1,*comp2;
                comp1=l.Comparer(cx->getR(),cy->getR());
                comp2=l.Comparer(cx->getI(),cy->getI());
                res= (comp1->getVal() && comp2->getVal());
                delete comp1;
                delete comp2;

            }

        }




        if (res==0){return (f.Fabriquer(0));}
        if (res==1){return (f.Fabriquer(1));}



}


 Entier* StrategieLogiqueSup::Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y){

     FabEntier f;
     Entier *ex,*ey;
     Reel* rx,*ry;
     Rationnel *rax,*ray;
     Complexe *cx,*cy;
     bool res;


     ex= dynamic_cast<Entier*>(x);
     rx= dynamic_cast<Reel*>(x);
     rax= dynamic_cast<Rationnel*>(x);
     cx= dynamic_cast<Complexe*>(x);

     ey= dynamic_cast<Entier*>(y);
     ry= dynamic_cast<Reel*>(y);
     ray= dynamic_cast<Rationnel*>(y);
     cy= dynamic_cast<Complexe*>(y);




         if (ex!=NULL){
             if(ey!= NULL){
                 res= (ex->getVal() > ey->getVal());
             }
             else if(ry!= NULL){
                 res= (ex->getVal() > ry->getVal());
             }
             else if(ray!= NULL){
                 res= 0;
             }
             else { //cy !=NULL
                 res= 0;
             }
         }
         if (rx!=NULL){
             qDebug()<<"je suis dans la bonne strat";

             if(ey!= NULL){
                 qDebug()<<"japplique la bonne strat";
                 qDebug()<<"dans rx" << rx->getVal();
                 qDebug()<<"dans ey" << ey->getVal();


                 res= (rx->getVal() > ey->getVal());

                  qDebug()<<"dans res" << res;
             }
             if(ry!= NULL){
                 res= (rx->getVal() > ry->getVal());
             }
             else if(ray!= NULL){
                 float fl= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());
                 res= (rx->getVal() > fl);
             }
             else { //cy !=NULL
                 res= 0;
             }

         }
         if (rax!=NULL){

             if(ey!= NULL){
                 float fl= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                 res= (fl > ey->getVal());
             }
             if(ry!= NULL){
                 float fl= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                 res= (fl > ry->getVal());
             }
             if(ray!= NULL){
                 float fl1= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                 float fl2= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());

                 res= (fl1 > fl2);
             }
             else { //cy !=NULL
                 res= 0;
             }

         }
         if (cx!=NULL){
             if(ey!= NULL){
                 res= 0;
             }
             if(ry!= NULL){
                 res= 0;
             }
             else if(ray!= NULL){
                 res= 0;
             }
             else{ //cy != NULL
                 StrategieLogiqueEgal l;
                 Entier *comp1,*comp2;
                 comp1=l.Comparer(cx->getR(),cy->getR());
                 comp2=l.Comparer(cx->getI(),cy->getI());
                 res= (comp1->getVal() && comp2->getVal());
                 delete comp1;
                 delete comp2;

             }

         }




         if (res==0){return (f.Fabriquer(0));}
         if (res==1){return (f.Fabriquer(1));}





 }



Entier* StrategieLogiqueSupEg::Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y){

    FabEntier f;
    Entier *ex,*ey;
    Reel* rx,*ry;
    Rationnel *rax,*ray;
    Complexe *cx,*cy;
    bool res;


    ex= dynamic_cast<Entier*>(x);
    rx= dynamic_cast<Reel*>(x);
    rax= dynamic_cast<Rationnel*>(x);
    cx= dynamic_cast<Complexe*>(x);

    ey= dynamic_cast<Entier*>(y);
    ry= dynamic_cast<Reel*>(y);
    ray= dynamic_cast<Rationnel*>(y);
    cy= dynamic_cast<Complexe*>(y);




        if (ex!=NULL){
            if(ey!= NULL){
                res= (ex->getVal() >= ey->getVal());
            }
            else if(ry!= NULL){
                res= (ex->getVal() >= ry->getVal());
            }
            else if(ray!= NULL){
                res= 0;
            }
            else { //cy !=NULL
                res= 0;
            }
        }
        if (rx!=NULL){

            if(ey!= NULL){
                res= (rx->getVal() >= ey->getVal());
            }
            if(ry!= NULL){
                res= (rx->getVal() >= ry->getVal());
            }
            else if(ray!= NULL){
                float fl= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());
                res= (rx->getVal() >= fl);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (rax!=NULL){

            if(ey!= NULL){
                float fl= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                res= (fl >= ey->getVal());
            }
            if(ry!= NULL){
                float fl= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                res= (fl >= ry->getVal());
            }
            if(ray!= NULL){
                float fl1= (rax->getNumerateur()->getVal()/rax->getDenumerateur()->getVal());
                float fl2= (ray->getNumerateur()->getVal()/ray->getDenumerateur()->getVal());

                res= (fl1 >= fl2);
            }
            else { //cy !=NULL
                res= 0;
            }

        }
        if (cx!=NULL){
            if(ey!= NULL){
                res= 0;
            }
            if(ry!= NULL){
                res= 0;
            }
            else if(ray!= NULL){

                res= 0;
            }
            else{ //cy != NULL
                StrategieLogiqueEgal l;
                Entier *comp1,*comp2;
                comp1=l.Comparer(cx->getR(),cy->getR());
                comp2=l.Comparer(cx->getI(),cy->getI());
                res= (comp1->getVal() && comp2->getVal());
                delete comp1;
                delete comp2;

            }

        }




        if (res==0){return (f.Fabriquer(0));}
        if (res==1){return (f.Fabriquer(1));}




}

















