#ifndef NUMERO_H
#define NUMERO_H
#include <iostream>

using std::string;

class Numero{
    protected:
        string num;
        int dec;
        Numero(string s): num(s){};
        virtual void toDec() = 0;
    public:
        virtual int getDec() {return dec;};
        string getOriginal() const {return num;};
        virtual string toString() = 0;
};
#endif