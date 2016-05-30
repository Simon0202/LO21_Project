#ifndef FABRIQUE_H
#define FABRIQUE_H

#include"litteraleabstraite.h"
#include"numerique.h"
#include"entier.h"
#include"reel.h"
#include"rationnel.h"
#include"complexe.h"


class Fabrique
{
public:

    //virtual const LitteraleAbstraite* creer(QString c)=0;
};


class FabEntier: public Fabrique{

public:

    //virtual const LitteraleAbstraite* creer(QString c);
    Entier* Fabriquer(long int i);


};

class FabReel: public Fabrique{

public:
    //virtual const LitteraleAbstraite* creer(QString c);
    Reel* Fabriquer(float r);


};

class FabComplexe: public Fabrique{


public:

    //virtual const LitteraleAbstraite* creer(QString c);
   Complexe* Fabriquer(Numerique* l1, Numerique* l2);


};

class FabRationnel: public Fabrique{


public:
    //virtual const LitteraleAbstraite* creer(QString c);
    Rationnel* Fabriquer(Entier* l1, Entier* l2);



};

class FabExpression: public Fabrique{



public:

    //virtual const LitteraleAbstraite* creer(QString c);
    //Expression* Fabriquer();



};

class FabProgramme: public Fabrique{


public:

    //virtual const LitteraleAbstraite* creer(QString c);
    //Programme* Fabriquer();



};




#endif // FABRIQUE_H
