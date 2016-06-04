#ifndef COMPUTEREXCEPTION_H
#define COMPUTEREXCEPTION_H

#include <QString>
#include <QSettings>
#include <QMediaPlayer>

class ComputerException {
private:
    QString info;
    void playBeep() const;

public:

    ComputerException(const QString& str, const int n=-1);
    QString getInfo() const;
};
#endif // COMPUTEREXCEPTION_H

