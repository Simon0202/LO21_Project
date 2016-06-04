#ifndef PILE_H
#define PILE_H


#include <QObject>
#include <QString>
#include <QStack>
#include <QtCore/qmath.h>
#include <typeinfo>
#include <iostream>
#include "litteraleabstraite.h"
#include "atome.h"

class Pile : public QObject {
    Q_OBJECT

private:
    static Pile* instance;
    QStack<LitteraleAbstraite*> stack;
    QString message;
    unsigned int maxAffiche;
    Pile():message(""), maxAffiche(5){}

public:
    static Pile* getInstance();
    static void libererInstance();
    QString getMessage() const;
    void setMaxAffiche(int);
    void setMessage(const QString& msg);
    unsigned int getMaxAffiche() const;
    QStack<LitteraleAbstraite*>* getStack();
    void push(LitteraleAbstraite* lit);
    LitteraleAbstraite* pop();
    LitteraleAbstraite* top() const;

signals:
    void modificationEtat();
};

#endif // PILE_H
