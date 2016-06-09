#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"
#include <QObject>
#include <QString>
#include <QStack>
#include <QtCore/qmath.h>
#include <typeinfo>
#include "litteraleabstraite.h"
#include "atome.h"
#include "controleur.h"
#include "computerexception.h"


class M_Undo: public QObject{

    Q_OBJECT

private:
    static M_Undo* instance;
    QStack <LitteraleAbstraite*> stack;
    QString message;
    unsigned int maxAffiche;
    M_Undo();
    ~M_Undo();

public:
    static M_Undo* getInstance();
    static void libererInstance();
    int getLength() const;
    bool isEmpty();
    QStack<LitteraleAbstraite*>::const_iterator getIteratorBegin() const;
    QStack<LitteraleAbstraite*>::const_iterator getIteratorEnd() const;
    void push(LitteraleAbstraite* lit);
    LitteraleAbstraite* pop();
    LitteraleAbstraite* top() const;
    void clear();
};

class M_Redo: public QObject{

    Q_OBJECT

private:
    static M_Redo* instance;
    QStack <LitteraleAbstraite*> stack;
    QString message;
    unsigned int maxAffiche;
    M_Redo();
    ~M_Redo();

public:
    static M_Redo* getInstance();
    static void libererInstance();
    int getLength() const;
    bool isEmpty();
    QStack<LitteraleAbstraite*>::const_iterator getIteratorBegin() const;
    QStack<LitteraleAbstraite*>::const_iterator getIteratorEnd() const;
    void push(LitteraleAbstraite* lit);
    LitteraleAbstraite* pop();
    LitteraleAbstraite* top() const;
    void clear();
};





/*

//Classe Cellule adaptee pour la classe Memento car son contenu ne pointe pas vers une Donnee mais vers une Pile

class CellMem
{
private :
    //pointeur vers une Pile.
    Pile* contenu;
    //Etat anterieur dans le Memento.
    CellMem* succ;

public :
    //Constructeur servant a initialiser une CellMem vide.
    CellMem(Pile* cont = 0,CellMem* next = 0) : contenu(cont),succ(next) {}
    Pile* getContent() const { return contenu; }
    CellMem* getSucc() const { return succ; }
};


//Pile de pointeurs vers des etats successifs de la Pile (Design pattern Memento)
class Memento
{
private :
    //etat de la Pile sauvegarde le plus recent
    CellMem* tete;
    //Taille de la Pile.
    int taille;

public :
    //initialise un Memento vide.
    Memento(CellMem* head = 0,int t = 0) : tete(head),taille (t) {}
    int longueur() { return taille; }

    //Sauvegardee un etat de la Pile.
    void save(Pile* stack);
    //Restaure un etat de la Pile.
    Pile* restore();
    //Remet le Memento a zero avec la methode clear de la Pile.
    void reset();
};

*/

#endif // MEMENTO_H

