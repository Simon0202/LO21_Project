#ifndef LITTERALEABSTRAITE_H
#define LITTERALEABSTRAITE_H

#include <Qstring>
#include <iostream>
#include <typeinfo>
#include <QStack>
#include "computerexception.h"

/**
 * @brief The LitteraleAbstraite class is the main class (Abstract) of the project. Every others litterals herit from it.
 */
class LitteraleAbstraite
{
public:
    /**
     * @brief createLitteralAbstraite
     * @param value
     * @param type
     * @return
     */
    static LitteraleAbstraite* createLitteralAbstraite(const QString& value, const QString& type);
    //Destructeur
        virtual ~LitteraleAbstraite(){}
    //Affichage d'une donnee.
        virtual void afficher(std::ostream& f=std::cout) const = 0;
    //Clonage d'une donnee (DUP)
        virtual LitteraleAbstraite* clone() const = 0;
    //Utile pour le parseur
    virtual QString toString() const = 0;

};

bool isEntier(LitteraleAbstraite* l);

bool isReel(LitteraleAbstraite* l);

bool isRationnel(LitteraleAbstraite* l);

bool isComplexe(LitteraleAbstraite* l);

#endif // LITTERALEABSTRAITE_H
