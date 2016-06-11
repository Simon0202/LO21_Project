#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
#include<iostream>
#include"strategieaddition.h"
#include"entier.h"
#include "complexe.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QCoreApplication::setOrganizationName("LO21");
    QCoreApplication::setOrganizationDomain("LO21LL.com");
    QCoreApplication::setApplicationName("ZemaComputer");
    w.setWindowTitle("ZemaComputer");




/*
    Entier e1(5);
    Entier e2(2);
    Complexe c1(&e1,&e2);
    StrategieAddition s;
    Complexe *res = s.Calcul(&c1,&e1);
    res->afficher();
    //Penser à delete
*/


    return a.exec();
}
