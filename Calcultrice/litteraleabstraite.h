#ifndef LITTERALEABSTRAITE_H
#define LITTERALEABSTRAITE_H

#include <string>
#include <iostream>
#include <typeinfo>



class LitteraleAbstraite
{
public:
    //Affichage d'une donnee.
        virtual void afficher(std::ostream& f=std::cout) const = 0;
    //Clonage d'une donnee pour la dupliquer ou autre.
        virtual LitteraleAbstraite* clone() const = 0;
};

#endif // LITTERALEABSTRAITE_H
