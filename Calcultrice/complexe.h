#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "litteraleabstraite.h"
#include "numerique.h"

//Rajouter un destructeur
/**
 * @brief The Complexe class store 2 Numeriques to be represented
 */
class Complexe : public Numerique{
private:
    /**
     * @brief Represent the real part of a Complexe.
     * Entier or Rationnel or Reel pointer object.
     */
    Numerique *a;
    /**
     * @brief Represent the imaginary part of a Complexe.
     * Entier or Rationnel or Reel pointer object.
     */
    Numerique *b;

public:
    /**
     * @brief Default constructor
     */
    Complexe();
    /**
    *@brief Destructor of Complexe. It deletes the real an imaginary parts before being destroyed.
    * Avoid memory leak
    */
    ~Complexe(){
        delete a;
        delete b;
    }
    /**
     * @brief Complexe constructor with two Numerique pointers. It is used with all calculations stategies
     * @param Re is a Numerique pointer, it permis the computer to be dynamic.
     * @param Im is a Numerique pointer, it permis the computer to be dynamic.
     */
    Complexe(Numerique *Re,Numerique *Im): a(Re), b(Im){}
    /**
     * @brief Complexe constructor with two LitteraleAbstraite pointers. It is used with all calculations stategies
     * @param Re is a LitteraleAbstraite pointer, it permis the computer to be dynamic.
     * @param Im is a LitteraleAbstraite pointer, it permis the computer to be dynamic.
     */
    Complexe(LitteraleAbstraite* Re, LitteraleAbstraite* Im);
    /**
     * @brief Complexe Constructor with two strings. It is used with the parser of the application that send string
     * @param pRe is a Qtring reference. It sets a
     * @param pIm is a Qstring reference. It sets b
     */
    Complexe(const QString& pRe, const QString& pIm);
    /**
     * @brief getR allows us to return the right type a the real part
     * @return It returns a pointer to a numeric and so on the type of the real part
     */
    Numerique* getR() const{return a;}
    /**
     * @brief getI allows us to return the right type a the real part
     * @return It returns a pointer to a numeric and so on the type of the imaginary part
     */
    Numerique* getI() const{return b;}


    //Héritage
    /**
     * @brief afficher is herited from LitteraleAbstraite. It permits to display the right form of the complexe
     * @param f is a cout ostream
     */
    virtual void afficher(std::ostream& f=std::cout) const;
    /**
     * @brief toString is herited from LitteraleAbstraite and it converts the complexe into a Qstring. It is used by createLitteral.
     * @return It returns a Qstring formed by a complexe.
     */
    virtual QString toString() const;

    /**
     * @brief conjugue is used for division to conjuguate the complexe
     * @return It returns the conjuguate part
     */
    Complexe* conjugue();

    /**
     * @brief clone duplicate the complexe
     * @return It returns a pointer to a LitteraleAbstraite to be pushed inside the stack
     */
    virtual LitteraleAbstraite* clone() const;
    /**
     * @brief EstNul allows us to know if the real or the imaginary part is null
     * @return true or false
     */
    bool EstNul(){return (a->EstNul() && b->EstNul());}
    /**
     * @brief type get the type of the LitteraleAbstraite for complexe. Use by the controller
     * @return the type complexe
     */
    QString type(){return "complexe";}

};

#endif // COMPLEXE_H
