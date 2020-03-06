#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include "Numero.hpp"
#include <iostream>

using std::string;
using std::cout;

class Hexadecimal : public Numero{
    public:
        Hexadecimal(string s) : Numero(s){};
        string toString(){cout << "Hexadecimal: " + num;};
};
#endif