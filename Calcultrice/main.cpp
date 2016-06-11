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

    long int e=2;
    float r=2.1;

    bool res;
    res =(r>e);

    std::cout << "res est :"<< res<< std::endl;

    res = (r1.getVal() > e1.getVal());



    Complexe c1(&e1,&e2);
    StrategieAddition s;
    Complexe *res = s.Calcul(&c1,&e1);
    res->afficher();
    //Penser à delete
*/


    return a.exec();
}
