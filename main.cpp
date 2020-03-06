#include <iostream>
#include <vector>
#include "Numero.hpp"
#include "Decimal.hpp"
#include "Binario.hpp"
#include "Octal.hpp"
#include "Hexadecimal.hpp"

using namespace std;

int menu(){
    int op;
    cout << "Ingrese la opcion que desee:"
    << "\t\n1. Ingresar Numero"
    << "\t\n2. Listar Numero"
    << "\t\n3. Operar" << endl;
    cin >> op;
    return op;
}

void selector(){
    bool end = false;
    vector<Numero> num;
    do{
        switch (menu())
        {
        case 1:
            cout << "Insertar Numero" << endl;
            break;
        case 2:
            cout << "Listar Numero" << endl;
            break;
        case 3:
            cout << "Operar" << endl;
            break;
        case 4:
            end = true;
            break;
        default:
            cout << "NO es una opcion!!!" << endl;
            break;
        }
    }while(!end);
}

int main(){
    cout << "Hola Mundo";
    return 0;
}