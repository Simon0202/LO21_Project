#include "complexe.h"

/*
Complexe::Complexe(){
   R=new Reel;
   I=new Reel;
}



void Complexe::afficher(std::ostream& f) const
{
    R->afficher(f);
    f<<"+";
    I->afficher(f);
    f<<"i";
}

//Pb fonction ci dessous;
Numerique* Complexe::clone() const
{

    return new Complexe(R->clone(),b->clone());
}

Complexe::Complexe(Numerique *d)
{
        // On identifie le type numerique de la donnee entree en parametre.
        Complexe* test = dynamic_cast< Complexe*>(d);
        Reel* test1 = dynamic_cast< Reel*>(d);
        Rationnel* test2 = dynamic_cast< Rationnel*>(d);
        Entier* test3 = dynamic_cast< Entier*>(d);

        //selon le type entree, la conversion s'effectue.
        if (test) {
                    R=test->R;
                    b=test->b;
        }
        else if (test1){
                   R=test1;
                   b=new Reel;
                  }
        else if (test2){
                   R=test2;
                   b= new Rationnel;
                  }
        else if (test3){
                   R=test3;
                   b=new Entier;
                  }

        else throw "Erreur inattendue au niveau de la formation d'un complexe par une donne. Cf complexe.cpp";

}
*/


