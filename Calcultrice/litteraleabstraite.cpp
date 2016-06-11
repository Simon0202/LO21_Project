#include <QDebug>
#include "litteraleabstraite.h"
#include "entier.h"
#include "numerique.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"
#include "strategieaddition.h"
#include "strategiedivision.h"
#include "strategiesoustraction.h"
#include "strategiemultiplication.h"
#include "controleur.h"
#include "computerexception.h"


//Litteral
LitteraleAbstraite* LitteraleAbstraite::createLitteralAbstraite(const QString& value, const QString& type) {
    if (type == "Entier") {
        return new Entier(value.toInt());
        throw ComputerException("Creation Entier");
    }
    else if (type == "Reel") {
            int e;
            QStringList parts = value.split('.', QString::KeepEmptyParts);
            if(parts.at(0) == ""){
                e = 0;
            }
            else {
                e = qAbs(parts.at(0).toInt());
            }
            if (parts.at(1) == "" || parts.at(1) == "0") {
                return new Entier(parts.at(0).toInt());
            }
            double d = e + parts.at(1).toInt() * (qPow(10,-(parts.at(1).length())));
            if(parts.at(0) != "" && (parts.at(0).toInt() < 0 || parts.at(0)[0] == '-'))
                d *= (-1);
            return new Reel(d);
    }
    else if (type == "Rationnel") {
        QStringList parts = value.split('/', QString::KeepEmptyParts);
        Rationnel* rationnel = new Rationnel(parts.at(0).toInt(), parts.at(1).toInt());
        //converting into Entier, if possible
        if(rationnel->getDenumerateur()->getVal() == 1 || rationnel->getNumerateur()->getVal()  == 0){
            Entier* res= new Entier(rationnel->getNumerateur()->getVal());
            delete rationnel;
            return res;
        }
        else {
            return rationnel;
        }
    }
    else if (type == "Complexe"){
            QStringList parts;
            if(value.count('$') == 1){
                parts = value.split('$', QString::KeepEmptyParts);
            }
            else{ //parts = [pRe,"+",pIm"i"]
                QStringList partsTemp = value.split(' ', QString::KeepEmptyParts);
                if(partsTemp.at(2) == "0i"){//if it's not a complexe
                    return new Entier(partsTemp.at(0).toInt());
                }
                parts.append(partsTemp.at(0));
                QString temp = partsTemp.at(2);
                temp.truncate(temp.length()-1);
                QString temp2;
                if(partsTemp.at(1) == "-")
                    temp2.append('-');
                if(temp == "-" || temp == "")
                    temp.append('1');
                temp2.append(temp);
                parts.append(temp2);
            }
                QString re = parts.at(0);
                QString im = parts.at(1);
                return new Complexe(re, im);
    }
   /* else if (type == "Atome") {
        qDebug()<<"bla";
        Atome* a = new Atome(value);
       }*/
    else{
        throw ComputerException("Type Inconnu");
    }
}


bool isEntier(LitteraleAbstraite* l){
    Entier *e = dynamic_cast<Entier*>(l);
    return e!=nullptr;
}


bool isReel(LitteraleAbstraite* l){
    Reel *r = dynamic_cast<Reel*>(l);
    return r!=nullptr;
}


bool isRationnel(LitteraleAbstraite* l){
    Rationnel *r = dynamic_cast<Rationnel*>(l);
    return r!=nullptr;
}


bool isComplexe(LitteraleAbstraite* l){
    Complexe *c = dynamic_cast<Complexe*>(l);
    return c!=nullptr;
}
