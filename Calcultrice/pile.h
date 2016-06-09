#ifndef PILE_H
#define PILE_H

#include <QObject>
#include <QString>
#include <QStack>
#include <QtCore/qmath.h>
#include <typeinfo>
#include "litteraleabstraite.h"
#include "atome.h"
#include "controleur.h"
#include "computerexception.h"
#include "memento.h"

class Pile : public QObject {
    Q_OBJECT

private:
    static Pile* instance;
    QStack<LitteraleAbstraite*> stack;
    QString message;
    unsigned int maxAffiche;
    Pile();
    ~Pile();

public:
    static Pile* getInstance();
    static void libererInstance();
    QString getMessage() const;
    void setMessage(const QString& msg);
    unsigned int getMaxAffiche() const;
    void setMaxAffiche(unsigned int);
    int getLength() const;
    bool isEmpty();
    void push(LitteraleAbstraite* lit);
    LitteraleAbstraite* pop();
    LitteraleAbstraite* top() const;
    QStack<LitteraleAbstraite*>::const_iterator getIteratorBegin() const;
    QStack<LitteraleAbstraite*>::const_iterator getIteratorEnd() const;
    void clear();
    void sauvegarde();
    void undo();
    void redo();

signals:
    void modificationEtat();
};

#endif // PILE_H
