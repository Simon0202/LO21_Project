#include "pile.h"
#include "atome.h"
#include "complexe.h"
#include "entier.h"
#include "reel.h"
#include "factory.h"

/*
void Pile::afficher(std::ostream& f) const
{
    int compteur = 0;
    Cellule* cell = tete;
    while(cell)
    {
        ++compteur;
        f<<compteur<<": ";
        cell->getContent()->afficher(f);
        f<<"\n";
        cell = cell->getSucc();
    }
}


Pile* Pile::clone() const {
    if(taille == 0)
        return new Pile;
    Cellule* cell = new Cellule(tete->getContent()->clone());
    Cellule* newhead = cell;
    Cellule* next = tete->getSucc();
    while(next)
    {
        cell->setSucc(new Cellule(next->getContent()->clone()));
        next = next->getSucc();
        cell = cell->getSucc();
    }
    return new Pile(newhead,taille);
}

void Pile::drop()
{
    Cellule* cell = tete;
    if(tete)
    {
        tete = tete->getSucc();
        cell->~Cellule();
        --taille;
    }
}

void Pile::clear()
{
    while(tete) drop();
}

void Pile::dup()
{
    if(taille>=1)
    {
        Cellule* cell = new Cellule(tete->getContent()->clone(),tete);
        tete = cell;
        ++taille;
    }
    else
        throw "Pile vide.";
}



void Pile::swap()
{
    if(taille<2)
        throw "La pile ne contient pas suffisamment d'éléments.";
    else
    {
        Cellule* newhead = tete->getSucc();
        tete->setSucc(newhead->getSucc());
        newhead->setSucc(tete);
        tete = newhead;
    }
}
*/
