#include "rationnel.h"

double Rationnel::pgcd(unsigned long int a,unsigned long int b)
{
    int r =a%b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

void Rationnel::simplifier(){

        if(_num->getVal() != 0)
            {
                double p = pgcd(_num->getVal(),_denum->getVal());
                _num->setVal(_num->getVal()/p);
                _denum->setVal(_denum->getVal()/p);
                if (_denum->getVal()<0 && _num->getVal()<0 )
                {
                    _num->setVal(-1*_num->getVal());
                    _denum->setVal(-1*_denum->getVal());
                }
                if (_denum->getVal() < 0)
                {
                    _num->setVal(-1*_num->getVal());
                    _denum->setVal(-1*_denum->getVal());
                }

            }
            else
                 _denum->setVal(1);
}


Rationnel::Rationnel(double n, double d){
    _num = new Entier(n);
    _denum = new Entier(d);
    simplifier();
}



LitteraleAbstraite* Rationnel::clone() const
{
    return new Rationnel(_num,_denum);
}

Rationnel& Rationnel::operator=(const Rationnel& n){
    if(this != &n){
        _num= n._num;
        _denum= n._denum;
    }
    return *this;
}

//Methode toString()
QString Rationnel::toString() const {
    return _num->toString() + "/" + _denum->toString();
}

Rationnel::Rationnel(const QString& s):_num(new Entier(s.split('/').at(0).toInt())), _denum(new Entier(s.split('/').at(1).toInt())){
    if (s.split('/').at(1) == "0") {
        throw ComputerException("Le denominateur ne peut pas etre nul!");
    }
    simplifier();
}
