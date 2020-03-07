#include <iostream>
#include <vector>
#include "Numero.hpp"
#include "Decimal.hpp"
#include "Binario.hpp"
#include "Octal.hpp"
#include "Hexadecimal.hpp"

using namespace std;
vector<Numero *> arrNum;

int menu()
{
    int op;
    cout << "Ingrese la opcion que desee:"
         << "\t\n1. Ingresar Numero"
         << "\t\n2. Listar Numero"
         << "\t\n3. Operar"
         << "\t\n4. Salida" << endl;
    cin >> op;
    return op;
}

int menuOp()
{
    while (true)
    {
        int op;
        cout << "Ingrese la opcion que desee:"
             << "\t\n1. Suma"
             << "\t\n2. Resta"
             << "\t\n3. Multiplicacion"
             << "\t\n4. Division" << endl;
        cin >> op;
        if (op > 0 && op < 5)
        {
            return op;
        }
        else
        {
            cout << "Opcion Invalida!!!!" << endl;
        }
    }
}

void crearNumero(string num)
{
    if (num.find("b") != string::npos)
    {
        num.resize(num.length() - 1);
        arrNum.push_back(new Binario(num));
        cout << "Se a creado un binario con exito" << endl;
    }
    else if (num.find("x") == 1)
    {
        arrNum.push_back(new Hexadecimal(num));
        cout << "Se a creado un Hexadecimal con exito" << endl;
    }
    else if (num.find("c") == 1)
    {
        arrNum.push_back(new Octal(num));
        cout << "Se a creado un Octal con exito" << endl;
    }
    else
    {
        arrNum.push_back(new Decimal(num));
        cout << "Se a creado un Decimal con exito" << endl;
    }
}

void listarNumero()
{
    for (size_t i = 0; i < arrNum.size(); i++)
    {
        cout << arrNum[i]->toString() << endl;
    }
}

int getIndex(string num)
{
    while (true)
    {
        listarNumero();
        cout << "Ingrese el numero " << num << endl;
        int op;
        cin >> op;
        if (op <= 0 || op >= arrNum.size())
        {
            cout << "Es un indice invalido!!!" << endl;
        }
        else
        {
            return op;
        }
    }
}

void operaciones(int op)
{
    Numero *p1 = arrNum[getIndex("1")];
    Numero *p2 = arrNum[getIndex("2")];
    switch (op)
    {
    case 1:
    {

        if (typeid(*p1) == typeid(Decimal))
        {
            Decimal temp = dynamic_cast<Decimal &>(*p1) + p2;
            arrNum.push_back(new Decimal(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Binario))
        {
            Binario temp = dynamic_cast<Binario &>(*p1) + p2;
            arrNum.push_back(new Binario(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Octal))
        {
            cout << "Entra 2" << endl;
        }
        else if (typeid(*p1) == typeid(Hexadecimal))
        {
            cout << "Entra 3" << endl;
        }

        break;
    }/*
    case 2:
    {
        if (typeid(*p1) == typeid(Decimal))
        {
            Decimal temp = dynamic_cast<Decimal &>(*p1) - p2;
            arrNum.push_back(new Decimal(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Binario))
        {
            Binario temp = dynamic_cast<Binario &>(*p1) - p2;
            arrNum.push_back(new Binario(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Octal))
        {
            cout << "Entra 2" << endl;
        }
        else if (typeid(*p1) == typeid(Hexadecimal))
        {
            cout << "Entra 3" << endl;
        }
        break;
    }
    case 3:
    {
        if (typeid(*p1) == typeid(Decimal))
        {
            Decimal temp = dynamic_cast<Decimal &>(*p1) * p2;
            arrNum.push_back(new Decimal(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Binario))
        {
            Binario temp = dynamic_cast<Binario &>(*p1) * p2;
            arrNum.push_back(new Binario(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Octal))
        {
            cout << "Entra 2" << endl;
        }
        else if (typeid(*p1) == typeid(Hexadecimal))
        {
            cout << "Entra 3" << endl;
        }
        break;
    }
    case 4:
    {
        if (typeid(*p1) == typeid(Decimal))
        {
            Decimal temp = dynamic_cast<Decimal &>(*p1) / p2;
            arrNum.push_back(new Decimal(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Binario))
        {
            Binario temp = dynamic_cast<Binario &>(*p1) / p2;
            arrNum.push_back(new Binario(temp.getOriginal()));
        }
        else if (typeid(*p1) == typeid(Octal))
        {
            cout << "Entra 2" << endl;
        }
        else if (typeid(*p1) == typeid(Hexadecimal))
        {
            cout << "Entra 3" << endl;
        }
        break;
    }*/
    }
    delete p1;
    delete p2;
}

void selector()
{
    bool end = false;
    do
    {
        switch (menu())
        {
        case 1:
        {
            cout << "Insertar Numero" << endl;
            string str;
            cout << "Ingrese el NUmero que desee crear" << endl;
            cin >> str;
            crearNumero(str);
            break;
        }
        case 2:
            cout << "Listar Numero" << endl;
            if (arrNum.size() == 0)
            {
                cout << "No hay numeros a listar" << endl;
            }
            else
            {
                listarNumero();
            }
            break;
        case 3:
        {
            if (arrNum.size() == 0)
            {
                cout << "No hay numeros para operar" << endl;
            }
            else
            {
                operaciones(menuOp());
            }
        }
        break;
        case 4:
            end = true;
            for (auto p : arrNum){
                delete p;
            } 
            arrNum.clear();
            break;
        default:
            cout << "NO es una opcion!!!" << endl;
            break;
        }
    } while (!end);
}

int main()
{
    selector();
    return 0;
}