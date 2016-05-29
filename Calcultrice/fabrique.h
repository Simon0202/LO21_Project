#ifndef Fabrique_H
#define Fabrique_H

#include"litterale.h"
#include<QString>

//Le litteral manager possede fonction ajouter(const LitteraleAbstraite* l) cette fonction est appelee
// fonction creer est generale a toutes les classes : elle prend en param une chaine de car
// fonction Fabriquer est specifique à chaque Fabrique fille car en fonction du type fabriqué on a besoin d'un nombre diff d'argument
// on l'appelera avec l'operateur de resolution de portée
// ATTETION DANS CREER ET FabriqueR creation dynamique pour pvr renvoyer la reference
// Pile doit detruire une litterale doit detruire toutes les litterales associée(Dynamiques)

class Fabrique{

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




#endif // Fabrique_H

