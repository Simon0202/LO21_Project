#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include"strategieaddition.h"
#include"entier.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}
