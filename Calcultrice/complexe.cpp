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
    return new Complexe(a->clone(),b->clone());
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
