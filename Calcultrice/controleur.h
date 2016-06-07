#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QDebug>
#include <QVector>
#include <QSettings>
#include <QStringList>
#include "litteraleabstraite.h"
#include "atome.h"
#include "pile.h"
#include "operateur.h"



class Controleur {
private:
    static Controleur* instance;
    Controleur() {}
     ~Controleur();
public:
    static Controleur* getInstance();
    static void libererInstance();

    //parse une string sur la pile
    void parse(const QString& com);
    QStringList manualSplit(const QString& com);
    void process(const QString word);


    void applyOperatorNum(const QString& op, const int nbOp);
    void applyOperatorPile(const QString& op, const int nbOp);
    void applyOperator(const QString& op);

};

QString typeLitteral(const QString& lit);
bool isOperatorNum(const QString& a);
bool isOperatorPile(const QString& a);
bool isOperator(const QString& a);



#endif // CONTROLEUR_H
