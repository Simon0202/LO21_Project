#include <QDebug>
#include <QStack>
#include "pile.h"
#include"mainwindow.h"
#include "memento.h"

Pile* Pile::instance = nullptr;

Pile::Pile(): message(""), maxAffiche(0) {
}

Pile::~Pile() {
    libererInstance();

}

Pile* Pile::getInstance() {
    if (!instance)
        instance = new Pile();
    return instance;
}

void Pile::libererInstance() {
    if (instance)
        delete instance;
}

QString Pile::getMessage() const {
    return message;
}

void Pile::setMessage(const QString& msg) {
    message = msg;
}

void Pile::setMaxAffiche(unsigned int i) {
    maxAffiche = i;
}

unsigned int Pile::getMaxAffiche() const {
    return maxAffiche;
}


void Pile::push(LitteraleAbstraite *lit) {
    stack.push(lit);
    emit modificationEtat();
}



LitteraleAbstraite* Pile::pop(){
    if(stack.length()==0)
        throw ComputerException("Erreur : Pile vide");
    else
        return stack.pop();
}

LitteraleAbstraite* Pile::top() const{
    if(stack.length()==0)
        throw ComputerException("Erreur : Pile vide");
    else
        return stack.top();
}


int Pile::getLength() const {
    return stack.length();
}

bool Pile::isEmpty() {
    return stack.isEmpty();
}


QStack<LitteraleAbstraite*>::const_iterator Pile::getIteratorBegin() const {
    QStack<LitteraleAbstraite*>::const_iterator i = stack.constBegin();
    return i;
}

QStack<LitteraleAbstraite*>::const_iterator Pile::getIteratorEnd() const {
    QStack<LitteraleAbstraite*>::const_iterator i = stack.constEnd();
    return i;
}

void Pile::clear(){

    while(!isEmpty())
        pop();


}

void Pile::sauvegarde(){

    // On supprime les valeurs existante du memento undo
    M_Undo::getInstance()->clear();

    //On sauvegarde la pile dans le memento undo
    QStack<LitteraleAbstraite*>::const_iterator it;
    for(it=Pile::getIteratorBegin();it!=Pile::getIteratorEnd();it++){
        M_Undo::getInstance()->push((*it)->clone());

    }



}

void Pile::undo(){

    if(M_Undo::undomarche){
    //On sauvegarde la pile dans le memento redo (redo est vide au debut de chaque execution d'un undo car diff d'un REDO)
        QStack<LitteraleAbstraite*>::const_iterator it;
        for(it=Pile::getIteratorBegin();it!=Pile::getIteratorEnd();it++){
            M_Redo::getInstance()->push((*it)->clone());
        }
    qDebug() << "sauvegarde de la pile effectuee";


    // On supprime les valeurs existante de la pile
    Pile::getInstance()->clear();


    qDebug() << "clear effectue";

    //On remplace la pile par le memento undo
    for(it=M_Undo::getInstance()->getIteratorBegin();it!=M_Undo::getInstance()->getIteratorEnd();it++){
        Pile::getInstance()->push((*it)->clone());

    }
    M_Undo::undomarche=0;
    emit modificationEtat();
    }
    else throw ComputerException("UNDO deja realisé");
}

void Pile::redo(){

    if(M_Redo::redomarche){

    //On supprime les valeurs de la pile
    Pile::getInstance()->clear();

    QStack<LitteraleAbstraite*>::const_iterator it;
    //On remplace la pile par le memento redo
    for(it=M_Redo::getInstance()->getIteratorBegin();it!=M_Redo::getInstance()->getIteratorEnd();it++){
        Pile::getInstance()->push((*it)->clone());


    }
    M_Redo::redomarche= 0;
    emit modificationEtat();
    }
    else throw ComputerException("REDO deja realisé");
}










