#include "complexe.h"
#include"reel.h"

Complexe::Complexe(){
   a=new Reel;
   b=new Reel;
}

void Complexe::afficher(std::ostream& f) const
{
    a->afficher(f);
    f<<"+";
    b->afficher(f);
    f<<"i"<< std::endl;
}

//Pb fonction ci dessous;
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

/*
Complexe::Complexe(Numerique *d)
{
        // On identifie le type numerique de la donnee entree en parametre.
        Complexe* test = dynamic_cast< Complexe*>(d);
        Reel* test1 = dynamic_cast< Reel*>(d);
        Rationnel* test2 = dynamic_cast< Rationnel*>(d);
        Entier* test3 = dynamic_cast< Entier*>(d);

        //selon le type entree, la conversion s'effectue.
        if (test) {
                    a=test->a;
                    b=test->b;
        }
        else if (test1){
                   a=test1;
                   b=new Reel;
                  }
        else if (test2){
                   a=test2;
                   b= new Rationnel;
                  }
        else if (test3){
                   a=test3;
                   b=new Entier;
                  }

        else throw "Erreur inattendue au niveau de la formation d'un complexe par une donne. Cf complexe.cpp";

}
*/
