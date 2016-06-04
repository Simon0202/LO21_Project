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
    Complexe(Numerique *Re,Numerique *Im): a(Re), b(Im){}
    Complexe(LitteraleAbstraite* Re, LitteraleAbstraite* Im);
    ~Complexe(){
        delete a;
        delete b;
    }


    Numerique* getR() const {return a;}
    Numerique* getI() const {return b;}

    //Héritage
    void afficher(std::ostream& f=std::cout) const;
    //virtual QString toString() const;

    //Pb de fonction ci dessous
    virtual LitteraleAbstraite* clone() const;

    bool EstNul(){return (a->EstNul() && b->EstNul());}

    QString type(){return "complexe";}

};

#endif // COMPLEXE_H
