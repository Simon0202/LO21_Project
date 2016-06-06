#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T16:39:47
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia


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
    memento.cpp \
    fabrique.cpp \
    strategiecalcul.cpp \
    strategieaddition.cpp \
    strategiemultiplication.cpp \
    strategiesoustraction.cpp \
    strategiedivision.cpp \
    computerexception.cpp \
    controleur.cpp

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
    memento.h \
    fabrique.h \
    strategiecalcul.h \
    strategieaddition.h \
    strategiemultiplication.h \
    strategiesoustraction.h \
    strategiedivision.h \
    computerexception.h \
    controleur.h \
    operateur.h

FORMS    += mainwindow.ui
