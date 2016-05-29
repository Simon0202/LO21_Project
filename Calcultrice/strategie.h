#ifndef STRATEGIE_H
#define STRATEGIE_H

#include"litterale.h"
#include"fabrique.h"

// Pas besoin de ructeur, celui par defaut suffit, pareil pour destruction
// utilisation des fonctions calcul : pour operateur binaire : calcul(*depile(), *depile()) ou fonction depile renvoie une litterale pas pointeur
//car pointeur sur litterales ! pour pvr utiliser bonne version calcul il faut un type precis (pas de cast dynamique pour les types)
// Operateur manip pile = methodes de pile
// les ructeurs des litterales doivent etre declare ne prive et fabrique en friend des litterale
//On renvoit des LitteraleAbstraite* ac les strategie pour pouvoir utiliser des strategies dans des strategies


class StrategieCalcul{

    virtual Numerique *Calcul(Numerique* l1, Numerique* l2)=0;
    //virtual Numerique *Calcul(Entier* l1, Numerique* l2)=0;
    //virtual Numerique *Calcul(Numerique* l1, Entier* l2)=0;
    //virtual Numerique *Calcul(Reel* l1, Numerique* l2)=0;
    //virtual Numerique *Calcul(Numerique* l1, Reel* l2)=0;
    //virtual Numerique *Calcul(Rationnel* l1, Numerique* l2)=0;
    //virtual Numerique *Calcul(Numerique* l1, Rationnel* l2)=0;






};

class CalculAddition: public StrategieCalcul{


public:


    virtual Numerique*Calcul(Numerique* l1, Numerique* l2);
    //virtual Numerique *Calcul(Entier* l1, Numerique* l2);
    //virtual Numerique *Calcul(Numerique* l1, Entier* l2);
    //virtual Numerique *Calcul(Reel* l1, Numerique* l2);
    //virtual Numerique *Calcul(Numerique* l1, Reel* l2);
    //virtual Numerique *Calcul(Rationnel* l1, Numerique* l2);
    //virtual Numerique *Calcul(Numerique* l1, Rationnel* l2);
    virtual  Entier* Calcul(Entier* l1,Entier* l2);
    virtual  Reel* Calcul(Reel* l1,Reel* l2);
    virtual  Numerique* Calcul(Complexe* l1,Complexe* l2);
    //virtual  Numerique* Calcul(Rationnel* l1,Rationnel* l2);
    //virtual  Expression* Calcul(Expression* l1,Expression* l2);
    virtual  Reel* Calcul(Entier* l1,Reel* l2);
    virtual  Complexe* Calcul(Entier* l1,Complexe* l2);
    //virtual  Rationnel* Calcul(Entier* l1,Rationnel* l2);
    //virtual  Expression* Calcul(Entier* l1,Expression* l2);
    /*
    virtual  Reel* Calcul(Reel* l1,Entier* l2);
    virtual  Complexe* Calcul(Reel* l1,Complexe* l2);
    virtual  Reel* Calcul(Reel* l1,Rationnel* l2);
    virtual  Expression* Calcul(Reel* l1,Expression* l2);
    virtual  Entier* Calcul(Complexe* l1,Entier* l2);
    virtual  Complexe* Calcul(Complexe* l1,Reel* l2);
    virtual  Complexe* Calcul(Complexe* l1,Rationnel* l2);
    virtual  Expression* Calcul(Complexe* l1,Expression* l2);
    virtual  Rationnel* Calcul(Rationnel* l1,Entier* l2);
    virtual  Rationnel* Calcul(Rationnel* l1,Reel* l2);
    virtual  Complexe* Calcul(Rationnel* l1,Complexe* l2);
    virtual  Expression* Calcul(Rationnel* l1,Expression* l2);
    virtual  Expression* Calcul(Expression* l1,Entier* l2);
    virtual  Expression* Calcul(Expression* l1,Reel* l2);
    virtual  Expression* Calcul(Expression* l1,Complexe* l2);
    virtual  Expression* Calcul(Expression* l1,Rationnel* l2);


};

class CalculSoustraction: public StrategieCalcul{


};

class CalculMultiplication: public StrategieCalcul{


};

class CalculDivision: public StrategieCalcul{


};

class CalculDIV: public StrategieCalcul{


};

class CalculMOD: public StrategieCalcul{


};

class CalculNEG: public StrategieCalcul{


};

class CalculNUM: public StrategieCalcul{


};

class CalculDEN: public StrategieCalcul{


};



class CalculRE: public StrategieCalcul{


};

class CalculIM: public StrategieCalcul{


};

class CalculLogiqueEgal: public StrategieCalcul{


};

class CalculLogiqueDifferent: public StrategieCalcul{


};

class CalculLogiqueInfEg: public StrategieCalcul{


};

class CalculLogiqueSupEg: public StrategieCalcul{


};

class CalculLogiqueInf: public StrategieCalcul{


};

class CalculLogiqueSup: public StrategieCalcul{


};


*/

#endif // STRATEGIE_H
