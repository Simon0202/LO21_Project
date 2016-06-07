#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include<iostream>
#include"strategieaddition.h"
#include"entier.h"
#include "complexe.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




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
