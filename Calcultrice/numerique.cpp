#include "numerique.h"
#include"entier.h"
#include"reel.h"
#include"complexe.h"
#include"rationnel.h"

bool Numerique::EstNul(){

if ((dynamic_cast < Entier* > (this)) != NULL){ return this->EstNul();}
else if ((dynamic_cast < Reel* > (this))!= NULL){ return this->EstNul();}
else if ((dynamic_cast < Rationnel* > (this))!= NULL){ return this->EstNul();}
else if ((dynamic_cast < Complexe* > (this))!= NULL){ return this->EstNul();}

}
/*
int Numerique::isPositive(){
    if (int val=(dynamic_cast < Entier* > (this)) != NULL){
        if (val>0)
            return 1;
         else
             return -1;}
    //else if ((dynamic_cast < Reel* > (this))!= NULL){ return this->EstNul();}
    //else if ((dynamic_cast < Rationnel* > (this))!= NULL){ return this->EstNul();}
    //else if ((dynamic_cast < Complexe* > (this))!= NULL){ return this->EstNul();}

}
*/
