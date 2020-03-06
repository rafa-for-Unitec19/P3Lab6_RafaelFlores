#ifndef BINARIO_H
#define BINARIO_H
#include "Numero.hpp"
#include <iostream>

using std::string;
using std::cout;

class Binario : public Numero{
    public:
        Binario(string s): Numero(s){};
        string toString(){return "Binario: " + num;};
};
#endif