#include "mainwindow.h"
#include"strategieaddition.h"
#include"entier.h"
#include "complexe.h"
#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
#include<iostream>




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

    long int e=2;
    float r=2.1;

    bool res;
    res =(r>e);

    std::cout << "res est :"<< res<< std::endl;

    res = (r1.getVal() > e1.getVal());

*/

    return a.exec();
}
