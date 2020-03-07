#ifndef DECIMAL_H
#define DECIMAL_H
#include "Numero.hpp"

#include <iostream>

using std::string;
using std::cout;
using std::to_string;
using std::endl;

class Decimal : public Numero{
    private:
        void toDec(){Numero::dec = stoi(Numero::num);};
    public:
        Decimal(string s): Numero(s){
            toDec();
        };
        string toString(){return "Decimal: " + num;};
        int getDec() const {return Numero::dec;};
        Decimal operator+(Numero* n){
            int res;
            string chr = "";
            res = Numero::dec + n->getDec();
            cout << res;
            chr = to_string(res);
            Decimal temp(chr);   
            cout << temp.toString();
            return temp;
        }
        Decimal operator-(Numero* n){
            int res;
            string chr = "";
            res = Numero::dec - n->getDec();
            cout << res;
            chr = to_string(res);
            Decimal temp(chr);   
            cout << temp.toString();
            return temp;
        }
        Decimal operator*(Numero* n){
            int res;
            string chr = "";
            res = Numero::dec * n->getDec();
            cout << res;
            chr = to_string(res);
            Decimal temp(chr);   
            cout << temp.toString();
            return temp;
        }
        Decimal operator/(Numero* n){
            int res;
            string chr = "";
            if (n->getDec() == 0)
            {
                res = Numero::dec;
            }else{
                res = Numero::dec / n->getDec();
            }
            cout << res;
            chr = to_string(res);
            Decimal temp(chr);   
            cout << temp.toString();
            return temp;
        }
};
#endif