#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <QString>
#include <QMap>
#include <QList>

static const QMap<QString, int> opsNum{
    {"+", 2},
    {"-", 2},
    {"*", 2},
    {"/", 2},
    {"DIV", 2},
    {"MOD", 2},
    {"NEG", 1},
    {"NUM", 1},
    {"DEN", 1},
    {"$", 2},
    {"RE", 1},
    {"IM", 1},
    };

static const QMap<QString, int> opsPile {
    {"DUP", 0},
    {"SWAP", 2},
    {"LASTOP", 0},
    {"CLEAR", 0},
    {"EVAL", 1},
    {"STO", 2},
    {"FORGET", 1},
    {"EDIT", 1},
    {"IFT", 2},
    {"DROP", 0},
    {"UNDO",0},
    {"REDO",0}
};



#endif // OPERATEUR_H
