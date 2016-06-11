#ifndef FABRIQUE_H
#define FABRIQUE_H

#include"litteraleabstraite.h"
#include"numerique.h"
#include"entier.h"
#include"reel.h"
#include"rationnel.h"
#include"complexe.h"

/**
 * @brief The FabEntier class build an instance of Entier class.
 */
class FabEntier{
public:
    /**
     * @brief Fabriquer returns dynamically an instance of Entier.
     * @param e is the value received to set up the attribut of Entier.
     * @return It returns a pointer on an Entier.
     */
    Entier* Fabriquer(long int e);
};

/**
 * @brief The FabReel class build an instance of Reel class.
 */
class FabReel{
public:
    /**
     * @brief Fabriquer returns dynamically an instance of Real
     * @param r is the value received to set up the attribut of Reel.
     * @return It returns a pointer on a Real.
     */
    Reel* Fabriquer(float r);
};


/**
 * @brief The FabComplexe class build an instance of Complexe class.
 */
class FabComplexe{
public:
    /**
    * @brief Fabriquer returns dinamically an instance of Complexe.
    * @param c1 is a pointer that initialized the real part dynamically.
    * @param c2 is a pointer that initialized the imaginary part dinamically.
    * @return It returns a pointer on a Complexe.
    */
   Complexe* Fabriquer(Numerique* c1, Numerique* c2);
};

/**
 * @brief The FabRationnel class build an instance of Rationnel class.
 */
class FabRationnel{
public:
    /**
     * @brief Fabriquer returns dinamically an instance of Rationnel.
     * @param r1 is a pointer that initialized the numerator part.
     * @param r2 is a pointer that initialized the denominator part.
     * @return It returns a pointer on a Rationnel Class.
     */
    Rationnel* Fabriquer(Entier* r1, Entier* r2);
};

/**
 * @brief The FabExpression class build an instance of Expression class. Not implemented yet.
 */
class FabExpression{
public:
};

/**
 * @brief The FabProgramme class build an instance of Expression class. Not implemented yet.
 */
class FabProgramme{
public:
};




#endif // FABRIQUE_H
