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

/**
 * @brief The M_Undo class is made to make the undo action. But we built it for a one shot step action. It is a full Qobject.
 */
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
    static bool undomarche;
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
    static bool redomarche;
};








#endif // MEMENTO_H

