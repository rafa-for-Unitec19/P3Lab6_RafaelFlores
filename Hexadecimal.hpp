#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include "Numero.hpp"
#include <iostream>

using std::string;
using std::cout;

class Hexadecimal : public Numero{
    private:
        void toDec(){Numero::dec = stoi(Numero::num, 0, 16);
            cout << dec;
        };
    public:
        Hexadecimal(string s) : Numero(s){
            toDec();
        };
        string toString(){return "Hexadecimal: " + num;};
        int getDec() const {return dec;};
};
#endif