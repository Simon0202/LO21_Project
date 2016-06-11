#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QDebug>
#include <QVector>
#include <QSettings>
#include <QStringList>
#include "litteraleabstraite.h"
#include "atome.h"
#include "pile.h"
#include "operateur.h"


/**
 * @brief The Controleur class is the main important part. That class parse the expression from the line Edit and call the right method from strategies to the operators.
 */
class Controleur {
private:
    static Controleur* instance;
    /**
     * @brief Controleur is the default constructor.
     */
    Controleur() {}
    /**
      *@brief ~Controleur is the destructor. It calls the method liberer instance and delete the instance if it exists.
      */
     ~Controleur();
public:
    /**
     * @brief getInstance catch the instance if it exists and if not create a new one.
     * @return It returns the instance of the class.
     */
    static Controleur* getInstance();
    /**
     * @brief libererInstance is the method called by the destructor of controleur and that delete the instance, only if it exists.
     */
    static void libererInstance();

    /**
     * @brief parse parse a string in the line Edit. It uses thow methods : manualSplit and process. First it checks if the line edit is empty and then if it's not the case, it calls manualsplit on the receveived string. And it applies proocess on each word.
     * @param com is the received content from the line edit.
     */
    void parse(const QString& com);
    /**
     * @brief manualSplit is the method called by parse on the content of the lineEdit. It splits each part of the received string.
     * @param com is the recieved string from parse from the lineEdit.
     * @return  it returns a list of word which process gonna be called;
     */
    QStringList manualSplit(const QString& com);
    /**
     * @brief process is the metod called by parse. It calls the right method for each word the make the appropriate operation on it.
     * @param word is a part of the content of the line edit send to it in a list shape thanks to manualSplit and parse.
     */
    void process(const QString word);


    /**
     * @brief applyOperatorNum calls the right strategie of calculation for each operator (+ * - /)
     * @param op is the operator received in a Qstring shape.
     * @param nbOp is the type of op : unary, binary...
     */
    void applyOperatorNum(const QString& op, const int nbOp);
    /**
     * @brief applyOperatorPile choose the action to make for each pile operation
     * @param op is the operator received in a Qstring shape.
     * @param nbOp is the type of op : unary, binary...
     */
    void applyOperatorPile(const QString& op, const int nbOp);
    /**
     * @brief applyOperator determines which type of operator it is.
     * @param op is an operator. It can be Pile, Numeric or Logical operator
     */
    void applyOperator(const QString& op);
    void applyOperatorLog(const QString& op, const int nbOp);

};

/**
 * @brief typeLitteral determines the type of object. From an operator to a LitteraleAbstraite.
 * @param lit is a word that we need to know is type.
 * @return it returns the type of the word in a QString.
 */
QString typeLitteral(const QString& lit);
/**
 * @brief isOperatorNum
 * @param a is the received operator.
 * @return It returns true is a is a Litteral operator.
 */
bool isOperatorNum(const QString& a);
/**
 * @brief isOperatorPile
 * @param a is the received operator
 * @return It returns true is a is a Numeric operator.
 */
bool isOperatorPile(const QString& a);
/**
 * @brief isOperator returns true if a can be a type of operator.
 * @param a is the received operator.
 * @return It returns true of false in case a isn't an operator.
 */
bool isOperator(const QString& a);
bool isOperatorLog(const QString& a);



#endif // CONTROLEUR_H
