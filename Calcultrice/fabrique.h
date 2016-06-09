#ifndef FABRIQUE_H
#define FABRIQUE_H

#include"litteraleabstraite.h"
#include"numerique.h"
#include"entier.h"
#include"reel.h"
#include"rationnel.h"
#include"complexe.h"


//Fabrique d'entier
class FabEntier{
public:
    Entier* Fabriquer(long int i);
};

//Fabrique de réel
class FabReel{
public:
    Reel* Fabriquer(float r);
};

//Fabrique de complexe
class FabComplexe{
public:
   Complexe* Fabriquer(Numerique* l1, Numerique* l2);
};

//FabriqueRationnel
class FabRationnel{
public:
    Rationnel* Fabriquer(Entier* l1, Entier* l2);
};

class FabExpression{
public:
};

class FabProgramme{
public:
};




#endif // FABRIQUE_H
