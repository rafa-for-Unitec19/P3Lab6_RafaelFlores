#ifndef NUMERO_H
#define NUMERO_H
#include <iostream>

using std::string;

class Numero{
    protected:
        string num;
        Numero(string s): num(s){};
    public:
        virtual string toString() = 0;
};
#endif