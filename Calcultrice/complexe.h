#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "litteraleabstraite.h"
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
    Complexe(const QString& pRe, const QString& pIm);
    Numerique* getR() const{return a;}
    Numerique* getI() const{return b;}


    //Héritage
    virtual void afficher(std::ostream& f=std::cout) const;
    virtual QString toString() const;


    Complexe* conjugue();


    virtual LitteraleAbstraite* clone() const;

    bool EstNul(){return (a->EstNul() && b->EstNul());}

    QString type(){return "complexe";}

};

#endif // COMPLEXE_H
