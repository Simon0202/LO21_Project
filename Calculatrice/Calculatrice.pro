#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T23:14:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculatrice
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    litteraleabstraite.cpp \
    litteralenumerique.cpp \
    litteraleexpression.cpp \
    litteralecomplexe.cpp \
    litteralereelle.cpp \
    litteralleentiere.cpp \
    litteralerationnelle.cpp \
    litteralleatome.cpp \
    litteraleprogramme.cpp

HEADERS  += mainwindow.h \
    litteraleabstraite.h \
    litteralenumerique.h \
    litteraleexpression.h \
    litteralecomplexe.h \
    litteralereelle.h \
    litteralleentiere.h \
    litteralerationnelle.h \
    litteralleatome.h \
    litteraleprogramme.h

FORMS    += mainwindow.ui
