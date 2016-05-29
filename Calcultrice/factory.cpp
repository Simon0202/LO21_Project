/*
#include "factory.h"
#include "entier.h"
#include "reel.h"
#include "pile.h"

#include <sstream>

Entier* Factory::make_entier(std::string str)
{
    std::istringstream iss(str);
    int nb;
    iss >> nb;
    return new Entier(nb);
}

Rationnel* Factory::make_rationnel(std::string str)
{
    int i=0;
    int num = 0,denum = 1;
    std::string tmp, num_str, denum_str;
    while(str[i] != '\0' && str[i] != '/')
        num_str += str[i++];
    std::istringstream num_iss(num_str);
    num_iss >> num;
    if(str[i]=='/')
    {
        i++;
        while(str[i] != '\0')
            denum_str += str[i++];
        std::istringstream denum_iss(denum_str);
        denum_iss >> denum;
    }

    if (denum==0) throw "Fraction avec denominateur nul impossible.";
    return new Rationnel(num,denum);
}
*/
