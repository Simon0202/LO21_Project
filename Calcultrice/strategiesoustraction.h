#ifndef STRATEGIESOUSTRACTION_H
#define STRATEGIESOUSTRACTION_H

#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "numerique.h"
#include "litteraleabstraite.h"

class StrategieSoustraction{



public:

        virtual  Entier* Calcul(Entier* l1,Entier* l2);
        virtual  Reel* Calcul(Reel* l1,Reel* l2);
        virtual  Numerique* Calcul(Complexe* l1,Complexe* l2);
        virtual  Numerique* Calcul(Rationnel* l1,Rationnel* l2);
        //virtual  Expression* Calcul(Expression* l1,Expression* l2);

        virtual  Reel* Calcul(Entier* l1,Reel* l2);
        virtual  Reel* Calcul(Reel* l1,Entier* l2);
        virtual  Complexe* Calcul(Entier* l1,Complexe* l2);
        virtual  Complexe* Calcul(Complexe* l1,Entier* l2);
        virtual  Numerique* Calcul(Entier* l1,Rationnel* l2);
        virtual  Numerique* Calcul(Rationnel* l1,Entier* l2);
        //virtual  Expression* Calcul(Entier* l1,Expression* l2);
        //virtual  Expression* Calcul(Expression* l1,Entier* l2);

        virtual  Complexe* Calcul(Reel* l1,Complexe* l2);
        virtual  Complexe* Calcul(Complexe* l1,Reel* l2);
        virtual  Reel* Calcul(Reel* l1,Rationnel* l2);
        virtual  Reel* Calcul(Rationnel* l1,Reel* l2);
        //virtual  Expression* Calcul(Reel* l1,Expression* l2);
        //virtual  Expression* Calcul(Expression* l1,Reel* l2);

        virtual  Complexe* Calcul(Rationnel* l1,Complexe* l2);
        virtual  Complexe* Calcul(Complexe* l1,Rationnel* l2);
        //virtual  Expression* Calcul(Rationnel* l1,Expression* l2);
        //virtual  Expression* Calcul(Expression* l1,Rationnel* l2);

        //virtual  Expression* Calcul(Complexe* l1,Expression* l2);
        //virtual  Expression* Calcul(Expression* l1,Complexe* l2);
};

#endif // STRATEGIESOUSTRACTION_H
