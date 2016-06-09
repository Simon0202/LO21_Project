#include"memento.h"
#include <QDebug>
#include"mainwindow.h"

//------------------------------------------------------------------
//              Fonctions Undo
//------------------------------------------------------------------

M_Undo* M_Undo::instance = nullptr;

M_Undo::M_Undo(): message(""), maxAffiche(0){
}

M_Undo::~M_Undo() {
    libererInstance();
}

M_Undo* M_Undo::getInstance() {
    if (!instance)
        instance = new M_Undo();
    return instance;
}

void M_Undo::libererInstance() {
    if (instance)
        delete instance;
}


int M_Undo::getLength() const {
    return stack.length();
}

bool M_Undo::isEmpty() {
    return stack.isEmpty();
}


QStack<LitteraleAbstraite*>::const_iterator M_Undo::getIteratorBegin() const {
    QStack<LitteraleAbstraite*>::const_iterator i = stack.constBegin();
    return i;
}

QStack<LitteraleAbstraite*>::const_iterator M_Undo::getIteratorEnd() const {
    QStack<LitteraleAbstraite*>::const_iterator i = stack.constEnd();
    return i;
}

void M_Undo::push(LitteraleAbstraite *lit) {
    stack.push(lit);

}



LitteraleAbstraite* M_Undo::pop(){
    if(stack.length()==0)
        throw ComputerException("Erreur : M_Undo vide");
    else
        return stack.pop();
}

LitteraleAbstraite* M_Undo::top() const{
    if(stack.length()==0)
        throw ComputerException("Erreur : M_Undo vide");
    else
        return stack.top();
}


void M_Undo::clear(){

    while(!isEmpty())
        pop();


}


//------------------------------------------------------------------
//              Fonctions Redo
//------------------------------------------------------------------

M_Redo* M_Redo::instance = nullptr;

M_Redo::M_Redo(): message(""), maxAffiche(0){
}

M_Redo::~M_Redo() {
    libererInstance();
}

M_Redo* M_Redo::getInstance() {
    if (!instance)
        instance = new M_Redo();
    return instance;
}

void M_Redo::libererInstance() {
    if (instance)
        delete instance;
}


int M_Redo::getLength() const {
    return stack.length();
}

bool M_Redo::isEmpty() {
    return stack.isEmpty();
}


QStack<LitteraleAbstraite*>::const_iterator M_Redo::getIteratorBegin() const {
    QStack<LitteraleAbstraite*>::const_iterator i = stack.constBegin();
    return i;
}

QStack<LitteraleAbstraite*>::const_iterator M_Redo::getIteratorEnd() const {
    QStack<LitteraleAbstraite*>::const_iterator i = stack.constEnd();
    return i;
}

void M_Redo::push(LitteraleAbstraite *lit) {
    stack.push(lit);

}



LitteraleAbstraite* M_Redo::pop(){
    if(stack.length()==0)
        throw ComputerException("Erreur : Redo vide");
    else
        return stack.pop();
}

LitteraleAbstraite* M_Redo::top() const{
    if(stack.length()==0)
        throw ComputerException("Erreur : M_Redo vide");
    else
        return stack.top();
}


void M_Redo::clear(){

    while(!isEmpty())
        pop();


}





/*

class Memento_undo{

private:

    static Memento_undo* instance;
    QStack<LitteraleAbstraite*> *q;
    QString message;
    unsigned int maxAffiche;

    ~Memento_undo;

public:

    static M_Undo* getInstance();
    static void libererInstance();
    void SaveM_Undo();
    void Undo();

};


class Memento_redo{




};













void Memento::save(M_Undo* stack)
{
    tete = new CellMem(stack->clone(),tete);
    ++taille;
}

M_Undo* Memento::restore()
{
    if(taille>0)
    {
        CellMem* cell = tete;
        tete = cell->getSucc();
        M_Undo* newstack = cell->getContent()->clone();
        cell->~CellMem();
        --taille;
        return newstack;
    }
        throw "Impossible d'annuler.";
}

void Memento::reset()
{
    while(tete) restore();
}
*/
