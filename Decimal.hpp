#ifndef DECIMAL_H
#define DECIMAL_H
#include "Numero.hpp"
#include <iostream>

using std::string;
using std::cout;

class Decimal : public Numero{
    public:
        Decimal(string s): Numero(s){};
        string toString(){return "Decimal: " + num;};
};
#endif