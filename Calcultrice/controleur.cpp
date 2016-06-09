#include "litteraleabstraite.h"
#include "operateur.h"
#include "controleur.h"
#include "complexe.h"
#include "strategieaddition.h"
#include "strategiedivision.h"
#include "strategiesoustraction.h"
#include "strategiemultiplication.h"
#include <QDebug>
#include <QRegularExpressionMatch>

StrategieAddition stratAdd;
StrategieMultiplication stratMul;
StrategieSoustraction stratSous;
StrategieDivision stratDiv;

Controleur* Controleur::instance = nullptr;


void Controleur::parse(const QString& com) {

    // A chaque execution du parseur (entree) on fait:
    //Sauvegarde de la pile dans le memento
    Pile::getInstance()->sauvegarde();
    //On efface le M_Redo si REDO n'est pas appelée : voir controleur::process


    if(com == "")
        throw ComputerException("La ligne de commande est vide !");

    Pile* pile = Pile::getInstance();

    QStringList words = manualSplit(com);

    foreach (QString word, words) {
        process(word);
    }
}

QStringList Controleur::manualSplit(const QString& com) {
    QStringList words;

    int i;
    QString temp;
    bool stop = false;

    for(i = 0; i < com.length(); i++) {
        if(com.at(i) == ' ') {
            if(temp != "") {
                words.append(temp);
                temp = "";
            }

            while(com.at(i) == ' ' && i != com.length() - 1) { //get to first character or end of string
                i++;
            }

            if(i == com.length() - 1) {
                if(com.at(i) != ' ')
                    temp.append(com.at(i));

                if(temp != "")
                    words.append(temp);

                temp = "";
                stop = true;
            }
        }

        if(!stop) {
            temp.append(com.at(i));

            if(com.at(i) == '[') {
                i++;

                do {
                    temp.append(com.at(i));
                    i++;
                } while(com.at(i) != ']');

                temp.append(com.at(i));
                words.append(temp);
                temp = "";
            }
        }
    }

    if(temp != "")
        words.append(temp);

    return words;
}

void Controleur::process(const QString word) {
    QString type = typeLitteral(word);
    Pile* pile = Pile::getInstance();

    if(word!="REDO"){
        M_Redo::getInstance()->clear();
    }

    if(isOperator(word)) {
        try {
            applyOperator(word);
        } catch(ComputerException c) {
            pile->setMessage(c.getInfo());
        }

    } else if(type != "Inconnu") {
        try {
            pile->push(LitteraleAbstraite::createLitteral(word, type));
        } catch (ComputerException c) {
            pile->setMessage(c.getInfo());
        }
    } else {
        pile->setMessage("Commande inconnue !");
    }

}

QString typeLitteral(const QString& lit){
    if(isOperatorNum(lit)){
        return "OperatorNum";
    }
    else if(isOperatorPile(lit)){
        return "OperatorPile";
    }
    else if(lit.count('$')==1 || lit.count('i')==1){
        qDebug()<<"complexe";
        return "Complexe";
    }
    else if(lit.count('.') == 1){
        qDebug()<<"reel";
        return "Reel";
    }
    else if(lit.count('/') == 1) {
        qDebug()<<"rationnel";
        return "Rationnel";
    }
    else if(lit == "0" || (lit.toInt() && lit.count('.') == 0 && (lit[0].isDigit() || (lit[0]=='-' && lit[1].isDigit())))){
        return "Entier";
    }
    else {
        QRegularExpression re("[A-Z][A-Z0-9]*"); //starts with a capital letter and is followed by letters or numbers
        QRegularExpressionMatch match = re.match(lit);

        if (match.hasMatch() && match.captured(0) == lit) { //if the whole string is matched
            return "Atome";
        }
    }

    return "Inconnu";
}


void Controleur::applyOperatorNum(const QString& op, const int nbOp){
    Pile *pile = Pile::getInstance();

    if(pile->getLength()<nbOp)
        throw ComputerException("Erreur : $ arguments empilés nécessaires", nbOp);

    LitteraleAbstraite *temp1 = pile->pop();

    if(nbOp==2){
        LitteraleAbstraite *temp2 = pile->pop();
    //********
    //ADDITION
    //********
    if(op=="+"){
        //Debut du cas des entiers
        if(isEntier(temp1)){
            Entier* x = dynamic_cast<Entier*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des entiers pour l'opérateur +

        //Debut du cas des Réels
        else if(isReel(temp1)){
            Reel* x = dynamic_cast<Reel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des réels pour l'opérateur +

        //Debut du cas des rationnels
        else if(isRationnel(temp1)){
            Rationnel* x = dynamic_cast<Rationnel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des rationnels

        //Debut du cas des complexes
        else if(isComplexe(temp1)){
            Complexe* x = dynamic_cast<Complexe*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratAdd.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des complexes
        //Impossible de faire un opérateur binaire
        else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
     }

    //************
    //SOUSTRACTION
    //************
    else if(op=="-"){
        //Debut du cas des entiers
        if(isEntier(temp1)){
            Entier* x = dynamic_cast<Entier*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des entiers pour l'opérateur +

        //Debut du cas des Réels
        else if(isReel(temp1)){
            Reel* x = dynamic_cast<Reel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des réels pour l'opérateur +

        //Debut du cas des rationnels
        else if(isRationnel(temp1)){
            Rationnel* x = dynamic_cast<Rationnel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des rationnels

        //Debut du cas des complexes
        else if(isComplexe(temp1)){
            Complexe* x = dynamic_cast<Complexe*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratSous.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des complexes
        //Impossible de faire un opérateur binaire
        else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
     }

    //**************
    //MULTIPLICATION
    //**************
    else if(op=="*"){
        //Debut du cas des entiers
        if(isEntier(temp1)){
            Entier* x = dynamic_cast<Entier*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des entiers pour l'opérateur +

        //Debut du cas des Réels
        else if(isReel(temp1)){
            Reel* x = dynamic_cast<Reel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des réels pour l'opérateur +

        //Debut du cas des rationnels
        else if(isRationnel(temp1)){
            Rationnel* x = dynamic_cast<Rationnel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des rationnels

        //Debut du cas des complexes
        else if(isComplexe(temp1)){
            Complexe* x = dynamic_cast<Complexe*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des complexes
        //Impossible de faire un opérateur binaire
        else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
    }

    //********
    //DIVISION
    //********

    else if(op=="/"){
        //Debut du cas des entiers
        if(isEntier(temp1)){
            Entier* x = dynamic_cast<Entier*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }

            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des entiers pour l'opérateur /

        //Debut du cas des Réels
        else if(isReel(temp1)){
            Reel* x = dynamic_cast<Reel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            /* Pas de div d'un reel par un complexe
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            */
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des réels pour l'opérateur /

        //Debut du cas des rationnels
        else if(isRationnel(temp1)){
            Rationnel* x = dynamic_cast<Rationnel*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            /* Pas de div d'un rationnel par un complexe
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            */
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des rationnels

        //Debut du cas des complexes
        else if(isComplexe(temp1)){
            Complexe* x = dynamic_cast<Complexe*>(temp1);
            if(isEntier(temp2)){
                Entier* y = dynamic_cast<Entier*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp2)){
                Reel* y = dynamic_cast<Reel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp2)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des complexes
      }
}
else{throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
/*
    else if(op=="DIV"){
        if(isEntier(x) && isEntier(y)){
            Litteral *res
            try{
                res = div(*y, *x);
                pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
            }catch(ComputerException c){
                pile->setMessage(c.getInfo());
                pile->push(Litteral::createLitteral(y->toString(), typeLitteral(y->toString())));
                pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            }
        }
        else{
            pile->push(Litteral::createLitteral(y->toString(), typeLitteral(y->toString())));
            pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            throw ComputerException("Erreur : L'opérateur DIV s'applique sur des opérandes entières");
        }
    }
    else if(op=="MOD"){
        if(isEntier(x) && isEntier(y)){
            Litteral *res;
            try{
                res = mod(*y, *x);
                pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
            }catch(ComputerException c){
                pile->setMessage(c.getInfo());
                pile->push(Litteral::createLitteral(y->toString(), typeLitteral(y->toString())));
                pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            }
        }
        else{
            pile->push(Litteral::createLitteral(y->toString(), typeLitteral(y->toString())));
            pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            throw ComputerException("Erreur : L'opérateur MOD s'applique sur des opérandes entières");
        }
    }
    else if(op=="NEG"){
        Litteral *res = neg(*x);
        pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
    }
    else if(op=="NUM"){
        if(isRationnel(*x) || isEntier(*x)){
            Litteral *res;
            res = num(*x);
            pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
        }
        else{
            pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            throw ComputerException("Erreur : L'opérateur NUM s'applique sur une opérande rationnelle ou entière");
        }
    }
    else if(op=="DEN"){
        if(isRationnel(x) || isEntier(x)){
            Litteral *res;
            res = den(*x);
            pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
        }
        else{
            pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            throw ComputerException("Erreur : L'opérateur NUM s'applique sur une opérande rationnelle ou entière");
        }
    }
    else if(op=="$"){
        if((isEntier(x) || isReel(x) || isRationnel(x)) && (isEntier(y) || isReel(y) || isRationnel(y))){
            Litteral *res = createComplexe(*y, *x);
            pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
        }
        else{
            pile->push(Litteral::createLitteral(y->toString(), typeLitteral(y->toString())));
            pile->push(Litteral::createLitteral(x->toString(), typeLitteral(x->toString())));
            throw ComputerException("Erreur : L'opérateur $ s'applique sur des opérandes entières, réelles ou rationnelles");
        }
    }
    else if(op=="RE"){
        Litteral *res = re(*x);
        pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
    }
    else if(op=="IM"){
        Litteral *res = im(*x);
        pile->push(Litteral::createLitteral(res->toString(), typeLitteral(res->toString())));
    }*/
}

void Controleur::applyOperatorPile(const QString& op, const int nbOp) {
    Pile *pile = Pile::getInstance();
    LitteraleAbstraite *x;
    LitteraleAbstraite *y;

    if(nbOp != 0) {
        if(pile->getLength() < nbOp)
            throw ComputerException("Erreur : $ arguments empilés nécessaires", nbOp);

        x = pile->pop();

        if(nbOp == 2) {
            y = pile->pop();
        }
    }

    if(op == "DUP") {
        try {
            x = pile->top();
            pile->push(LitteraleAbstraite::createLitteral(x->toString(), typeLitteral(x->toString())));
        } catch(ComputerException e) {
            pile->setMessage(e.getInfo());
        }
    } else if(op == "DROP") {
        try {
            pile->pop();
        } catch(ComputerException e) {
            pile->setMessage(e.getInfo());
        }
    } else if(op == "SWAP") {
        pile->push(LitteraleAbstraite::createLitteral(x->toString(), typeLitteral(x->toString())));
        pile->push(LitteraleAbstraite::createLitteral(y->toString(), typeLitteral(y->toString())));
    } else if(op == "CLEAR") {
        while(!pile->isEmpty())
            pile->pop();
    }

    else if(op== "UNDO"){
     try {
        Pile::getInstance()->undo();
      } catch(ComputerException e) {
          pile->setMessage(e.getInfo());
      }


    }
    else if(op=="REDO"){
    try {
        if (M_Redo::getInstance()->isEmpty()){
            throw ComputerException("Pas de Undo pour faire un Redo");
        }
        else{
            Pile::getInstance()->redo();

        }
    }catch(ComputerException e) {
            pile->setMessage(e.getInfo());
        }

    }

}

Controleur* Controleur::getInstance() {
    if(!instance)
        instance = new Controleur();
    return instance;
}

void Controleur::applyOperator(const QString& op) {
    if(isOperatorNum(op))
        applyOperatorNum(op, opsNum.value(op));
    else
        applyOperatorPile(op, opsPile.value(op));
}

void Controleur::libererInstance() {
    if (instance)
        delete instance;
}

Controleur::~Controleur() {
    libererInstance();
}


bool isOperatorNum(const QString& a) {
    return opsNum.contains(a);
}

bool isOperatorPile(const QString& a) {
    return opsPile.contains(a);
}

bool isOperator(const QString& a){
    return isOperatorNum(a) || isOperatorPile(a);
}

