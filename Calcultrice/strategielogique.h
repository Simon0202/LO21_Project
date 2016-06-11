#ifndef STRATEGIELOGIQUE_H
#define STRATEGIELOGIQUE_H
#include"litteraleabstraite.h"
#include"entier.h"



class StrategieLogique
{
public:

    virtual Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y)=0;

};

class StrategieLogiqueEgal : public StrategieLogique
{
public:

    Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y);

};

class StrategieLogiqueInegal : public StrategieLogique
{
public:

    Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y);

};

class StrategieLogiqueInf : public StrategieLogique
{
public:

    Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y);

};

class StrategieLogiqueInfEg : public StrategieLogique
{
public:

    Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y);

};

class StrategieLogiqueSup : public StrategieLogique
{
public:

    Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y);

};

class StrategieLogiqueSupEg : public StrategieLogique
{
public:

    Entier* Comparer(LitteraleAbstraite* x, LitteraleAbstraite* y);

};




















#endif // STRATEGIELOGIQUE_H
