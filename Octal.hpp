#ifndef OCTAL_H
#define OCTAL_H
#include "Numero.hpp"
#include <iostream>

using std::string;
using std::cout;

class Octal : public Numero{
    private:
        void toDec(){Numero::dec = stoi(Numero::num, 0, 8);
            cout << dec;
        };
    public:
        Octal(string s): Numero(s){
            toDec();
        };
        string toString(){return "Octal: " + num;};
        int getDec() const {return Numero::dec;};
};
#endif