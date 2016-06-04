#include "computerexception.h"
#include "complexe.h"
#include"reel.h"

Complexe::Complexe(){
   a=new Reel;
   b=new Reel;
}

void Complexe::afficher(std::ostream& f) const
{
    a->afficher(f);
    f<<"+";
    b->afficher(f);
    f<<"i";
}

//Pb fonction ci dessous;
/*LitteraleAbstraite* Complexe::clone() const
{
    return new Complexe(a->clone(),b->clone());
}*/


Complexe::Complexe(LitteraleAbstraite* Re, LitteraleAbstraite* Im)
{
    Numerique* num1 = dynamic_cast <Numerique*>(Re);
    Numerique* num2 = dynamic_cast <Numerique*>(Im);
    if(num1&&num2)
    {
        a=num1;
        b=num2;
    }
    else
        throw ComputerException("Un complexe ne peut etre forme que de nombres.");
}

/*
QString Complexe::toString() const{
    QString im = getI()->toString();
    if(*getI()>0){
        if(im=="1") im="";
        return getR()->toString() + " + " + im + "i";
    }
    else{
        im.remove('-');
        if(im=="1") im="";
        return getR()->toString() + " - " + im + "i";
    }
}
*/
