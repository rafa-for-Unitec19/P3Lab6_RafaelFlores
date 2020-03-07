#ifndef BINARIO_H
#define BINARIO_H
#include "Numero.hpp"

#include <iostream>

using std::string;
using std::cout;
using std::to_string;
using std::endl;


class Binario : public Numero{
    private:
        void toDec(){Numero::dec = stoi(Numero::num, 0, 2);
            cout << dec;
        };
    public:
        Binario(string s): Numero(s){
            toDec();
        };
        string toString(){return "Binario: " + num;};
        int getDec() const {return Numero::dec;};
        Binario operator+(Numero* n){
            string chr = "";
            int res;
            res = Numero::dec + n->getDec();
            for(int i=0; res>0; i++){    
                chr += to_string(res % 2);    
                res = res/2;  
            } 
            Binario temp(chr);   
            return temp;
        }
        Binario operator-(Numero* n){
            string chr = "";
            int res;
            res = Numero::dec - n->getDec();
            for(int i=0; res>0; i++){    
                chr += to_string(res % 2);    
                res = res/2;  
            } 
            Binario temp(chr);   
            return temp;
        }
        Binario operator*(Numero* n){
            string chr = "";
            int res;
            res = Numero::dec * n->getDec();
            for(int i=0; res>0; i++){    
                chr += to_string(res % 2);    
                res = res/2;  
            } 
            Binario temp(chr);   
            return temp;
        }
        Binario operator/(Numero* n){
            string chr = "";
            int res;
            if (n->getDec() == 0)
            {
                res = Numero::dec;
            }else{
                res = Numero::dec / n->getDec();
            }
            for(int i=0; res>0; i++){    
                chr += to_string(res % 2);    
                res = res/2;  
            } 
            Binario temp(chr);   
            return temp;
        }
};
#endif