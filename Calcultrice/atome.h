#ifndef ATOME_H
#define ATOME_H

#include "litteraleabstraite.h"
#include <QChar>
#include <QString>

class Atome : public LitteraleAbstraite
{
private:
    QString val;
public:
    Atome(QString atm);
    virtual void afficher(std::ostream& f=std::cout) const;
};

#endif // ATOME_H
