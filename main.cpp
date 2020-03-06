#include <iostream>
#include <vector>
#include "Numero.hpp"
#include "Decimal.hpp"
#include "Binario.hpp"
#include "Octal.hpp"
#include "Hexadecimal.hpp"

using namespace std;
vector<Numero*> arrNum;

int menu(){
    int op;
    cout << "Ingrese la opcion que desee:"
    << "\t\n1. Ingresar Numero"
    << "\t\n2. Listar Numero"
    << "\t\n3. Operar" 
    << "\t\n4. Salida"<< endl;
    cin >> op;
    return op;
}

void crearNumero(string num){
    if (num.find("b") != string::npos){
        num.resize(num.length()-1);
        arrNum.push_back(new Binario(num));
        cout << "Se a creado un binario con exito" << endl;
    }else if(num.find("x") == 1){
        arrNum.push_back(new Hexadecimal(num));
        cout << "Se a creado un Hexadecimal con exito" << endl;
    }else if(num.find("c") == 1){
        arrNum.push_back(new Octal(num));
        cout << "Se a creado un Octal con exito" << endl;
    }else{
        arrNum.push_back(new Decimal(num));
        cout << "Se a creado un Decimal con exito" << endl;
    }
}

void listarNumero(){
    cout << "Enntra\n";
    for (size_t i = 0; i < arrNum.size(); i++)
    {
        cout << "Enntra al for\n";
        /*cout << "---> "<< id << " <----" << endl;
        if (typeid(*arrNum[i]) == typeid(Decimal)){
            cout << "Enntra al If Decimal\n";
            dynamic_cast<Decimal*>(arrNum[i])->toString();
            cout << "Creo que muere\n";
        }else if(typeid(arrNum[i]) == typeid(Binario)){
            cout << "Enntra al If Binario\n";
            dynamic_cast<Binario*>(arrNum[i])->toString();
            cout << "Creo que muere\n";
        }else if(typeid(arrNum[i]) == typeid(Octal)){
            cout << "Enntra al If Ocatl\n";
            dynamic_cast<Octal*>(arrNum[i])->toString();
            cout << "Creo que muere\n";
        }else if(typeid(arrNum[i]) == typeid(Hexadecimal)){
            cout << "Enntra al If hEXA\n";
            dynamic_cast<Hexadecimal*>(arrNum[i])->toString();
            cout << "Creo que muere\n";
        }*/
        cout << arrNum[i]->toString() << endl;
    }
    
}

void selector(){
    bool end = false;
    do{
        switch (menu())
        {
        case 1:{
            cout << "Insertar Numero" << endl;
            string str;
            cout << "Ingrese el NUmero que desee crear" << endl;
            cin >> str;
            crearNumero(str);
            break;
            }
        case 2:
            cout << "Listar Numero" << endl;
            if (arrNum.size() == 0){
                cout << "No hay numeros a listar" << endl;
            }else{
                listarNumero();
            }
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
    selector();
    return 0;
}