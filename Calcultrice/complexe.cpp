#include "complexe.h"
#include"reel.h"
#include"entier.h"
#include "rationnel.h"
#include "litteraleabstraite.h"
#include "controleur.h"
#include <QDebug>


Complexe::Complexe(){
   a=new Reel;
   b=new Reel;
}

void Complexe::afficher(std::ostream& f) const
{
    a->afficher(f);
    f<<"+";
    b->afficher(f);
    f<<"i"<<std::endl;

}

LitteraleAbstraite* Complexe::clone() const
{
    Numerique* ac = dynamic_cast <Numerique*> (a->clone());
    Numerique* bc = dynamic_cast <Numerique*> (b->clone());
    return new Complexe(ac,bc);
}


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
        throw "Un complexe ne peut etre forme que de nombres.";
}

//Méthode toString
QString Complexe::toString() const{
    QString im = getI()->toString();
    if(getI()>0){
        if(im=="1") im="";
        return getR()->toString() + " + " + im + "i";
    }
    else{
        im.remove('-');
        if(im=="1") im="";
        return getR()->toString() + " - " + im + "i";
    }
}


Complexe::Complexe(const QString& pRe, const QString& pIm){
    if(typeLitteral(pRe)=="Entier")
        a = new Entier(pRe);
    else if(typeLitteral(pRe)=="Reel")
        a = new Reel(pRe);
    else if(typeLitteral(pRe)=="Rationnel"){
        Rationnel* rat = new Rationnel(pRe);
        rat->simplifier();
        if(rat->getDenumerateur()->getVal() == 1 || rat->getNumerateur()->getVal() ==0){
            Entier* e = new Entier(rat->getNumerateur()->getVal());
            a = e;
        }
        else{
            a = rat;
        }
    }

    if(typeLitteral(pIm)=="Entier")
        b = new Entier(pIm);
    else if(typeLitteral(pIm)=="Reel")
        b = new Reel(pIm);
    else if(typeLitteral(pIm)=="Rationnel"){
        Rationnel* rat = new Rationnel(pIm);
        rat->simplifier();
        if(rat->getDenumerateur()->getVal() == 1 || rat->getNumerateur()->getVal() ==0){
            Entier* e = new Entier(rat->getNumerateur()->getVal());
            b = e;
        }
        else{
            b = rat;
        }
    }
}

Complexe* Complexe::conjugue(){

    Numerique* i= getI();

    if (isEntier(i)){
        Entier* e = dynamic_cast<Entier*>(i);
        Entier* newi = new Entier(-(e->getVal()));
        return new Complexe(getR(),newi);
    }
    else if (isReel(i)){
        Reel* r = dynamic_cast<Reel*>(i);
        Reel* newi = new Reel(-(r->getVal()));
        return new Complexe(getR(),newi);
    }
    else{
        Rationnel* ra= dynamic_cast<Rationnel*>(i);
        Entier* e= new Entier(-(ra->getNumerateur()->getVal()));
        Rationnel* newra = new Rationnel(e,ra->getDenumerateur());
        return new Complexe(getR(),newra);
    }


}
