#ifndef COMPLEXE_H
#define COMPLEXE_H


#include "numerique.h"

//Rajouter un destructeur

class Complexe : public Numerique{
private:
    Numerique *a;
    Numerique *b;

public:
    Complexe();
    ~Complexe(){
        delete a;
        delete b;
    }
    Complexe(Numerique *Re,Numerique *Im): a(Re), b(Im){}
    Complexe(LitteraleAbstraite* Re, LitteraleAbstraite* Im);

    Numerique* getR(){return a;}
    Numerique* getI(){return b;}

    //A implémenter dans stratégie
    //inline void setSign(){a->setSign();b->setSign();}

    //On cree un complexe a partir d'un nombre reel et on met b a zero. */
    //Complexe(Numerique* d);

    //Héritage
    void afficher(std::ostream& f=std::cout) const;


    //virtual void setSign();

    //Pb de fonction ci dessous
    virtual LitteraleAbstraite* clone() const;

    bool EstNul(){return (a->EstNul() && b->EstNul());}

    QString type(){return "complexe";}

};

#endif // COMPLEXE_H
