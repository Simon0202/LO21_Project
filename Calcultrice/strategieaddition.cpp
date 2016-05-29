#include"strategie.h"

Numerique* CalculAddition::Calcul(Numerique* l1, Numerique* l2){

    if(l1->type()=="entier" && l2->type()=="entier"){

        CalculAddition c;
        Entier* e1;
        Entier* e2;
        e1= dynamic_cast < Entier* > ( l1 );
        e2= dynamic_cast < Entier* > ( l2 );
        return c.Calcul(e1,e2);



    }
    else if (l1->type()=="reel" && l2->type()=="reel"){

        CalculAddition c;
        Reel* e1;
        Reel* e2;
        e1= dynamic_cast < Reel* > ( l1 );
        e2= dynamic_cast < Reel* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if (l1->type()=="rationnel" && l2->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e1;
        Rationnel* e2;
        e1= dynamic_cast < Rationnel* > ( l1 );
        e2= dynamic_cast < Rationnel* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if(l1->type()=="entier" && l2->type()=="reel"){

        CalculAddition c;
        Entier* e1;
        Reel* e2;
        e1= dynamic_cast < Entier* > ( l1 );
        e2= dynamic_cast < Reel* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if(l1->type()=="reel" && l2->type()=="entier"){

        CalculAddition c;
        Reel* e1;
        Entier* e2;
        e1= dynamic_cast < Reel* > ( l1 );
        e2= dynamic_cast < Entier* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if (l1->type()=="rationnel" && l2->type()=="reel"){

        CalculAddition c;
        Rationnel* e1;
        Reel* e2;
        e1= dynamic_cast < Rationnel* > ( l1 );
        e2= dynamic_cast < Reel* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if (l1->type()=="reel" && l2->type()=="rationnel"){

        CalculAddition c;
        Reel* e1;
        Rationnel* e2;
        e1= dynamic_cast < Reel* > ( l1 );
        e2= dynamic_cast < Rationnel* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if (l1->type()=="rationnel" && l2->type()=="entier"){

        CalculAddition c;
        Rationnel* e1;
        Entier* e2;
        e1= dynamic_cast < Rationnel* > ( l1 );
        e2= dynamic_cast < Entier* > ( l2 );
        return c.Calcul(e1,e2);

    }
    else if (l1->type()=="entier" && l2->type()=="rationnel"){

        CalculAddition c;
        Entier* e1;
        Rationnel* e2;
        e1= dynamic_cast < Entier* > ( l1 );
        e2= dynamic_cast < Rationnel* > ( l2 );
        return c.Calcul(e1,e2);

    }
}

/*
Numerique* CalculAddition::Calcul(Entier* l1, Numerique* l2){



    if(l2->type()=="entier"){

       CalculAddition c;
       Entier* e2;
       e2= dynamic_cast < Entier* > ( l2 );
       return c.Calcul(l1,e2);

    }
    else if (l2->type()=="reel"){

        CalculAddition c;
        Reel* e2;
        e2= dynamic_cast < Reel* > ( l2 );
        return c.Calcul(l1,e2);

    }
    else if (l2->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e2;
        e2= dynamic_cast < Rationnel* > ( l2 );
        return c.Calcul(l1,e2);

    }


}

Numerique* CalculAddition::Calcul(Numerique* l1, Entier* l2){

    if(l1->type()=="entier"){

        CalculAddition c;
        Entier* e1;
        e1= dynamic_cast < Entier* > ( l1 );
        return c.Calcul(e1,l2);

    }
    else if (l1->type()=="reel"){

        CalculAddition c;
        Reel* e1;
        e1= dynamic_cast < Reel* > ( l1 );
        return c.Calcul(e1,l2);

    }
    else if (l1->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e1;
        e1= dynamic_cast < Rationnel* > ( l1 );
        return c.Calcul(e1,l2);
    }



}

Numerique* CalculAddition::Calcul(Reel* l1, Numerique* l2){

    if(l2->type()=="entier"){

        CalculAddition c;
        Entier* e2;
        e2= dynamic_cast < Entier* > ( l2 );
        return c.Calcul(l1,e2);


    }
    else if (l2->type()=="reel"){

        CalculAddition c;
        Reel* e2;
        e2= dynamic_cast < Reel* > ( l2 );
        return c.Calcul(l1,e2);

    }
    else if (l2->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e2;
        e2= dynamic_cast < Rationnel* > ( l2 );
        return c.Calcul(l1,e2);


    }




}

Numerique* CalculAddition::Calcul(Numerique* l1, Reel* l2){

    if(l1->type()=="entier"){

        CalculAddition c;
        Entier* e1;
        e1= dynamic_cast < Entier* > ( l1 );
        return c.Calcul(e1,l2);

    }
    else if (l1->type()=="reel"){

        CalculAddition c;
        Reel* e1;
        e1= dynamic_cast < Reel* > ( l1 );
        return c.Calcul(e1,l2);

    }
    else if (l1->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e1;
        e1= dynamic_cast < Rationnel* > ( l1 );
        return c.Calcul(e1,l2);

    }

}

Numerique* CalculAddition::Calcul(Rationnel* l1, Numerique* l2){

    if(l2->type()=="entier"){

        CalculAddition c;
        Entier* e2;
        e2= dynamic_cast < Entier* > ( l2 );
        return c.Calcul(l1,e2);

    }
    else if (l2->type()=="reel"){

        CalculAddition c;
        Reel* e2;
        e2= dynamic_cast < Reel* > ( l2 );
        return c.Calcul(l1,e2);

    }
    else if (l2->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e2;
        e2= dynamic_cast < Rationnel* > ( l2 );
        return c.Calcul(l1,e2);

    }


}

Numerique* CalculAddition::Calcul(Numerique* l1, Rationnel* l2){

    if(l1->type()=="entier"){

        CalculAddition c;
        Entier* e1;
        e1= dynamic_cast < Entier* > ( l1 );
        return c.Calcul(e1,l2);

    }
    else if (l1->type()=="reel"){

        CalculAddition c;
        Reel* e1;
        e1= dynamic_cast < Reel* > ( l1 );
        return c.Calcul(e1,l2);

    }
    else if (l1->type()=="rationnel"){

        CalculAddition c;
        Rationnel* e1;
        e1= dynamic_cast < Rationnel* > ( l1 );
        return c.Calcul(e1,l2);

    }

}


*/


Entier* CalculAddition::Calcul(Entier* l1,Entier* l2){

    FabEntier f;
    return (f.Fabriquer((l1->getVal())+(l2->getVal())));
}


Reel* CalculAddition::Calcul(Reel* l1,Reel* l2){


    FabReel f;
    return f.Fabriquer(l1->getVal()+l2->getVal());

}

/*
Numerique* CalculAddition::Calcul(Rationnel* l1,Rationnel* l2){

    //Il me faut multiplication de deux entiers pour faire





}
*/


Numerique* CalculAddition::Calcul(Complexe* l1,Complexe* l2){


    FabComplexe f;
    CalculAddition c;
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


/*
Expression* CalculAddition::Calcul(Expression* l1,Expression* l2)=0{

        //Faire une concatenation des deux chaines de charactere
}
*/
Reel* CalculAddition::Calcul(Entier* l1,Reel* l2){

      FabReel f;
      f.Fabriquer(l1->getVal()+l2->getVal());
}

Complexe* CalculAddition::Calcul(Entier* l1,Complexe* l2){

        FabComplexe f;
        CalculAddition c;
        return f.Fabriquer(c.Calcul(l1,l2->getR()),l2->getI());
}

/*
Rationnel* CalculAddition::Calcul(Entier* l1,Rationnel* l2){

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

Reel* CalculAddition::Calcul(Reel* l1,Entier* l2){

    FabReel f;
    f.Fabriquer(l1->getVal()+l2->getVal());

}

/*
Expression* CalculAddition::Calcul(Entier* l1,Expression* l2){

            //transfo entier en chaine caractere + concatenation


}
*/
