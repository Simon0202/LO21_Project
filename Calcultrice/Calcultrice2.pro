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
    fabrique.cpp

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
    fabrique.h \
    litterales.h

FORMS    += mainwindow.ui
