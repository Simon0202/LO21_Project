#ifndef COMPUTEREXCEPTION_H
#define COMPUTEREXCEPTION_H

#include <QString>
#include <QSettings>
#include <QMediaPlayer>

/**
 * @brief The ComputerException class manages Exception and throw those to the message bar.
 */
class ComputerException {
private:
    /**
     * @brief info is the attribut which is initialized by an exception and send to the message bar.
     */
    QString info;

public:
    /**
     * @brief ComputerException is the default constructor for the class.
     */
    ComputerException(){}
    /**
     * @brief ComputerException is the constructeur mainly used to create an exception. It receives two parameter.
     * @param str is a Qstring that catch the received message.
     * @param n is initialized at "-1" to treat the catch.
     */
    ComputerException(const QString& str, const int n=-1);
    /**
     * @brief getInfo method permits to use info in which is stored the exception message.
     * @return It returns a Qstring which contains the info message.
     */
    QString getInfo() const;

};
#endif // COMPUTEREXCEPTION_H

