#ifndef ATOME_H
#define ATOME_H

#include "litteraleabstraite.h"
#include <QChar>
#include <QString>
/**
 * \brief The Atome class can represent a Variable or Atome identifier, or an operator however it is not implemant in our Computer.
 */
class Atome : public LitteraleAbstraite
{
private:
    /**
     * @brief val is an attribut which defines and represents the object.
     */
    QString val;
public:
    /**
     * @brief Atome Constructor
     * @param atm is a QString object. It initializes val.
     */
    Atome(QString atm);
    /**
     * @brief afficher is an herited method from LitteraleAbstraite. It allows us to master the way to show an atom to the user.
     * @param f is a cout ostream.
     */
    virtual void afficher(std::ostream& f=std::cout) const;
};

#endif // ATOME_H
