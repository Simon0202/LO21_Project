#ifndef LITTERALEABSTRAITE_H
#define LITTERALEABSTRAITE_H

#include <Qstring>
#include <iostream>
#include <typeinfo>
#include <QStack>
#include "computerexception.h"




class LitteraleAbstraite
{
public:
    static LitteraleAbstraite* createLitteral(const QString& value, const QString& type);
    //Destructeur
        virtual ~LitteraleAbstraite(){}
    //Affichage d'une donnee.
        virtual void afficher(std::ostream& f=std::cout) const = 0;
    //Clonage d'une donnee (DUP)
        virtual LitteraleAbstraite* clone() const = 0;
    //Utile pour le parseur
    virtual QString toString() const = 0;

    //Surcharge des operateurs utilisant strategie
    LitteraleAbstraite* operator +(LitteraleAbstraite& a);
    //LitteraleAbstraite* operator -(Litteral& a);
    //LitteraleAbstraite* operator *(Litteral& a);
    //LitteraleAbstraite* operator /(Litteral& a);




};

bool isEntier(LitteraleAbstraite* l);


bool isReel(LitteraleAbstraite* l);


bool isRationnel(LitteraleAbstraite* l);


bool isComplexe(LitteraleAbstraite* l);
/*
template<class T>
bool isEntier(T& a);

template<class T>
bool isReel(T& a);

template<class T>
bool isRationnel(T& a);

template<class T>
bool isComplexe(T& a);

template<class T>
bool isExpression(T& a);
*/
#endif // LITTERALEABSTRAITE_H
