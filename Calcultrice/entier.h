#ifndef ENTIER_H
#define ENTIER_H

#include "numerique.h"
#include <QDebug>

/**
 * @brief The Entier class is the most basic type of LitteraleAbstraite that it inherits few methods.
 */
class Entier : public Numerique
{
private:
    /**
     * @brief _val is a long integer. It is the attribut of the class.
     */
    long int _val;
public:
    /**
     * @brief Entier is a constructor that initializes the attribut with a double. The convertion is implicite.
     * @param val is a double.
     */
    Entier(double val=1):_val(val){}
    /**
     * @brief Entier is a constructor that initialized the attribut with a string taken from the lineEdit.
     * @param s is a reference to a string. It is convert to initialized the attribut.
     */
    Entier(const QString& s):_val(s.toInt()){};



    //Accesseurs
    /**
     * @brief getVal it an accessor. It is a method that returns the attribut. It is used a lot in  the strategie to make the calculation.
     * @return it returns the attribut in a double shape.
     */
    double getVal(){return _val;}
    /**
     * @brief setVal is a setter. It allows us to change the value of the attribut.
     * @param val
     */
    void setVal(double val){_val=val;}


    /**
     * @brief afficher is an inherit method from LitteraleAbstraite and it displays the attribut.
     * @param f is a cout ostream
     */
    virtual void afficher(std::ostream& f=std::cout) const { f<<_val; }

    /**
     * @brief clone is a method to make a copie of an Entier.
     * @return it returns a pointer on a LitteraleAbstraite.
     */
    LitteraleAbstraite *clone() const;
    /**
     * @brief toString converts an Entier in a Qstring. It used by createLitteral.
     * @return It returns a string.
     */
    virtual QString toString() const;


    /**
     * @brief EstNul determins if the attribut is null or not.
     * @return It returns true or false.
     */
    bool EstNul(){return _val==0;}

    /**
     * @brief type send the type "entier" for the class Entier
     * @return a Qstring that contains the type of the class.
     */
    QString type(){return "entier";}
};
#endif // ENTIER_H
