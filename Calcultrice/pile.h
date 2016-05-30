#ifndef PILE_H
#define PILE_H

/*

#include "litteraleabstraite.h"
#include <iostream>

//implementee sous la forme d'une liste chainee.
class Cellule
{
private :
    //Une Cellule contient un pointeur vers une LitteraleAbstraite.
    LitteraleAbstraite* contenu;
    //Le deuxieme attribut de la classe Cellule permet d'acceder a son successeur.
    Cellule* succ;

public :
    //Constructeur servant a initialiser une Pile vide.
    Cellule(LitteraleAbstraite* cont = 0,Cellule* next = 0) : contenu(cont),succ(next) {}
    //Destructeur de la classe.
    ~Cellule() { delete contenu; }
    //Getter pour le contenu.
    LitteraleAbstraite* getContent() const { return contenu; }
    //Getter pour le successeur.
    Cellule* getSucc() const { return succ; }
    //Setter pour le contenu.
    void setContent(LitteraleAbstraite* content) { contenu = content; }
    //Setter pour le successeur.
    void setSucc(Cellule* next) { succ = next; }
};

//Pile de LitteraleAbstraites.
class Pile
{
private :
    //Tete de la Pile.
    Cellule* tete;
    //Taille de la Pile.
    int taille;

public :
    //Constructeur.
    Pile(Cellule* head = 0,int t = 0) : tete(head),taille(t) {}
    //Destructeur.
    ~Pile() { clear(); }
    //Getter pour la taille.
    int longueur() const { return taille; }

    //Empile une LitteraleAbstraite sur la Pile.
    void empiler(LitteraleAbstraite* elt);
    //Depile une LitteraleAbstraite.
    LitteraleAbstraite* depiler();

    //Affiche la Pile.
    void afficher(std::ostream& f=std::cout) const;
    //Surcharge de l'operateur << pour l'affichage
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }
    //Renvoie une copie de la Pile quand on pour la gestion des sauvegardes.
    Pile* clone() const;

    void drop();
    void clear();
    void dup();
    void sum();
    void swap();
    void mean();
};
*/
#endif // PILE_H
