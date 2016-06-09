#include "computerexception.h"
#include "mainwindow.h"

//Constructeur
ComputerException::ComputerException(const QString &str, const int n) {
    if(n==-1){
        info = str;
    }
    else{
        QStringList l = str.split('$', QString::KeepEmptyParts);
        info = l.at(0) + QString::number(n) + l.at(1);
    }
        MainWindow fctUser;
        fctUser.playSound();
}


//récupère le message
QString ComputerException::getInfo() const {
    return info;
}
