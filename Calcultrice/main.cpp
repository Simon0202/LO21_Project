#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include<iostream>
<<<<<<< HEAD
#include"strategieaddition.h"
#include"entier.h"
=======
#include "entier.h"
#include "complexe.h"
>>>>>>> 5db77839505caf60cd191a3971d9dfbd7d3f2869


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
