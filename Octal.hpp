#ifndef OCTAL_H
#define OCTAL_H
#include "Numero.hpp"
#include <iostream>

using std::string;
using std::cout;

class Octal : public Numero{
    public:
        Octal(string s): Numero(s){};
        string toString(){return "Octal: " + num;};
};
#endif