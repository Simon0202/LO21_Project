#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T16:39:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calcultrice2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    litteraleabstraite.cpp \
    numerique.cpp \
    entier.cpp \
    rationnel.cpp \
    reel.cpp \
    complexe.cpp \
    expression.cpp \
    atome.cpp \
    pile.cpp \
    factory.cpp \
    memento.cpp \
    ../../Strategie_calcul/fabrique.cpp \
    ../../Strategie_calcul/strategie.cpp \
    fabrique.cpp \
    strategie.cpp \
    strategieaddition.cpp

HEADERS  += mainwindow.h \
    litteraleabstraite.h \
    numerique.h \
    entier.h \
    rationnel.h \
    reel.h \
    complexe.h \
    expression.h \
    atome.h \
    pile.h \
    factory.h \
    memento.h \
    ../../Strategie_calcul/fabrique.h \
    ../../Strategie_calcul/strategie.h \
    fabrique.h \
    strategie.h \
    litterale.h

FORMS    += mainwindow.ui
