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
#include"strategielogique.h"

StrategieAddition stratAdd;
StrategieMultiplication stratMul;
StrategieSoustraction stratSous;
StrategieDivision stratDiv;

Controleur* Controleur::instance = nullptr;


void Controleur::parse(const QString& com) {

    // A chaque execution du parseur (entree) on fait:
    //Sauvegarde de la pile dans le memento si UNDO n'est pas appele
    //On efface le M_Redo si REDO n'est pas appelée : voir controleur::process


    if(com == "")
        throw ComputerException("La ligne de commande est vide !");

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

    if(word!="UNDO" ){
         M_Undo::undomarche= 1;
         if(M_Redo::redomarche){
         Pile::getInstance()->sauvegarde();
         }
    }
    if(word!="REDO"){
        M_Redo::redomarche= 1;
        if(M_Undo::undomarche){
        M_Redo::getInstance()->clear();
        }
    }

    if(isOperator(word)) {
        try {
            applyOperator(word);
        }
        catch(ComputerException c) {
            pile->setMessage(c.getInfo());
        }
        lastOp = word;
    }
    else if(type != "Inconnu") {
        try {
            pile->push(LitteraleAbstraite::createLitteral(word, type));
        }
        catch (ComputerException c) {
            pile->setMessage(c.getInfo());
        }

    }
    else {
        throw ComputerException("Commande inconnue !");
    }

}

QString typeLitteral(const QString& lit){
    if(isOperatorNum(lit)){
        return "OperatorNum";
    }
    else if(isOperatorPile(lit)){
        return "OperatorPile";
    }
    else if(isOperatorLog(lit)){
        return "OperatorLog";
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

    if(nbOp==2) {
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
                throw ComputerException("Creation d'un Entier");
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
        }//Fin du cas des rationnels pour +

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
        }//Fin du cas des complexes pour +
        //Impossible de faire un opérateur binaire
        else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
     }//Fin des additions

    //************
    //SOUSTRACTION
    //************
    else if(op=="-") {
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
        }//Fin du cas des entiers pour l'opérateur -

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
        }//Fin du cas des réels pour l'opérateur -

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
        }//Fin du cas des rationnels pour -

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
        }//Fin du cas des complexes pour -
        //Impossible de faire un opérateur binaire
        else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
     }//Fin soustraction

    //**************
    //MULTIPLICATION
    //**************
    else if(op=="*") {
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
        }//Fin du cas des entiers pour l'opérateur *

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
        }//Fin du cas des réels pour l'opérateur *

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
        }//Fin du cas des rationnels pour *

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
        }//Fin du cas des complexes pour *
        //Impossible de faire un opérateur binaire
        else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
    }//Fin Multiplication

    //********
    //DIVISION
    //********

    else if(op=="/") {
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

            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }

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

            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }

            else{ throw ComputerException("Erreur : Un opérateur numérique ne peut pas être appliqué");}
        }//Fin du cas des rationnels pour /

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
        }//Fin du cas des complexes pour /
      }//Fin Division

    //DEBUT DE DIV
    else if(op=="DIV") {
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
            /* Pas de div d'un entier par un complexe
            else if(isComplexe(temp2)){
                Complexe* y = dynamic_cast<Complexe*>(temp2);
                LitteraleAbstraite *res = stratDiv.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            */
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
        }//Fin du cas des rationnels pour /

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
        }//Fin du cas des complexes pour /
      }//Fin DIV



    /*
    else if(op=="MOD"){

    }*/

    else if(op=="$"){
        if((isEntier(temp1) || isReel(temp1) || isRationnel(temp1)) && (isEntier(temp2) || isReel(temp2) || isRationnel(temp2))){
            LitteraleAbstraite *res = new Complexe(temp2, temp1);
            pile->push(LitteraleAbstraite::createLitteral(res->toString(), typeLitteral(res->toString())));
        }
        else{
            pile->push(LitteraleAbstraite::createLitteral(temp2->toString(), typeLitteral(temp2->toString())));
            pile->push(LitteraleAbstraite::createLitteral(temp2->toString(), typeLitteral(temp2->toString())));
            throw ComputerException("Erreur : L'opérateur $ s'applique sur des opérandes entières, réelles ou rationnelles");
        }
    }
}//Fin de nbOp == 2
    if(op=="NEG"){
                Entier *x= new Entier(-1);
            if(isEntier(temp1)){
                Entier* y = dynamic_cast<Entier*>(temp1);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isReel(temp1)){
                Reel* y = dynamic_cast<Reel*>(temp1);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isRationnel(temp1)){
                Rationnel* y = dynamic_cast<Rationnel*>(temp1);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else if(isComplexe(temp1)){
                Complexe* y = dynamic_cast<Complexe*>(temp1);
                LitteraleAbstraite *res = stratMul.Calcul(x,y);
                pile->push(res);
                delete x;
                delete y;
            }
            else{ throw ComputerException("impossible de prendre la négation");}
        }//fin operateur NEG
    else if(op=="NUM"){
        if(isRationnel(temp1)){
            LitteraleAbstraite *resR = dynamic_cast<Rationnel*>(temp1)->getNumerateur();
            pile->push(temp1);
            pile->push(resR);
        }
        else if(isEntier(temp1)){
                pile->push(temp1->clone());
                pile->push(temp1->clone());
        }
        else{
            pile->push(LitteraleAbstraite::createLitteral(temp1->toString(), typeLitteral(temp1->toString())));
            throw ComputerException("Erreur : L'opérateur NUM s'applique sur une opérande rationnelle ou entière");
        }
    }
    else if(op=="DEN"){
        if(isRationnel(temp1)){
            LitteraleAbstraite *resR = dynamic_cast<Rationnel*>(temp1)->getDenumerateur();
            pile->push(temp1);
            pile->push(resR);
        }
        else if (isEntier(temp1)){
            pile->push(temp1->clone());
            pile->push(temp1->clone());
        }
        else{
            pile->push(LitteraleAbstraite::createLitteral(temp1->toString(), typeLitteral(temp1->toString())));
            throw ComputerException("Erreur : L'opérateur NUM s'applique sur une opérande rationnelle ou entière");
        }
    }
    else if(op=="RE"){
        if (isComplexe(temp1)){
        LitteraleAbstraite *resRE = dynamic_cast<Complexe*>(temp1)->getR();
        pile->push(temp1);
        pile->push(resRE);
        }
        else {
            pile->push(temp1);
            throw ComputerException("Impossible de prendre la partie Reelle");
           }
    }
    else if(op=="IM"){
        if (isComplexe(temp1)){
        LitteraleAbstraite *resIM = dynamic_cast<Complexe*>(temp1)->getI();
        pile->push(temp1);
        pile->push(resIM);
        }
        else{
            pile->push(temp1);
            throw ComputerException("Impossible de prendre la partie Reelle");

        }
    }
   else if(op == "NOT") {
        throw ComputerException("NOT n'est pas pris en charge par l'application");
    }

}//Fin de applyOperatorNUm

void Controleur::applyOperatorPile(const QString& op, const int nbOp) {
    Pile *pile = Pile::getInstance();
    LitteraleAbstraite *x;
    LitteraleAbstraite *y;

    if(nbOp != 0) {
        if(pile->getLength() < nbOp)
            throw ComputerException("Erreur : $ arguments empilés nécessaires (applyOperatorPile)", nbOp);

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

void Controleur::applyOperatorLog(const QString& op, const int nbOp){
    Pile *pile = Pile::getInstance();
try {

    if(pile->getLength()<nbOp)
        throw ComputerException("Erreur : $ arguments empilés nécessaires", nbOp);

    LitteraleAbstraite *temp1 = pile->pop();

    if(nbOp==2) {
    LitteraleAbstraite *temp2 = pile->pop();

    //********
    //Egal =
    //********

    if(op=="="){


        StrategieLogiqueEgal l;
        Entier* resultat;

        resultat=l.Comparer(temp1,temp2);

        delete temp1;
        delete temp2;
        pile->push(resultat);
        throw ComputerException("Creation d'un entier");


    }

    //********
    //Inegal !=
    //********
    if(op=="!="){


        StrategieLogiqueInegal l;
        Entier* resultat;

        resultat=l.Comparer(temp1,temp2);

        delete temp1;
        delete temp2;
        pile->push(resultat);
        throw ComputerException("Creation d'un entier");


    }
    //********
    //Inferieur <
    //********
    if(op=="<"){


        StrategieLogiqueInf l;
        Entier* resultat;

        resultat=l.Comparer(temp1,temp2);

        delete temp1;
        delete temp2;
        pile->push(resultat);
        throw ComputerException("Creation d'un entier");


    }

    //********
    //Inferieur ou egal <=
    //********

    if(op=="<="){


        StrategieLogiqueInfEg l;
        Entier* resultat;

        resultat=l.Comparer(temp1,temp2);

        delete temp1;
        delete temp2;
        pile->push(resultat);
        throw ComputerException("Creation d'un entier");


    }

    //********
    //Superieur >
    //********

    if(op==">"){


        StrategieLogiqueSup l;
        Entier* resultat;

        resultat=l.Comparer(temp1,temp2);

        delete temp1;
        delete temp2;
        pile->push(resultat);
        throw ComputerException("Creation d'un entier");


    }

    //********
    //Superieur ou egal >=
    //********

    if(op==">="){


        StrategieLogiqueSupEg l;
        Entier* resultat;

        resultat=l.Comparer(temp1,temp2);

        delete temp1;
        delete temp2;
        pile->push(resultat);
        throw ComputerException("Creation d'un entier");


    }







   }//fin de nbOP===2
    }catch(ComputerException e) {
            pile->setMessage(e.getInfo());
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
    else if(isOperatorPile(op))
        applyOperatorPile(op, opsPile.value(op));
    else applyOperatorLog(op, opsLog.value(op));
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

bool isOperatorLog(const QString& a) {
    return opsLog.contains(a);
}

bool isOperator(const QString& a){
    return isOperatorNum(a) || isOperatorPile(a) || isOperatorLog(a);
}

