#include <iostream>

using namespace std;

int main()
{
    int valor, denominacion;

    cout << "***Programa para retirar dinero***" << endl;
    cout << "Digite la cantidad que desea retirar:" << endl;
    cin >> valor;
    cout << "Digite el valor de los billetes en los cuales desea recibir el dinero: " << endl;
    cout << "Digite (1) si desea recibir billetes de 10.000." << endl;
    cout << "Digite (2) si desea recibir billetes de 20.000." << endl;
    cout << "Digite (3) si desea recibir billetes de 50.000." << endl;
    cout << "Digite (4) si desea recibir billetes de 100.000." << endl;
    cin >> denominacion;

    switch (denominacion){
        case 1:
            valor = valor / 10000;
            cout << "Son " << valor << " billetes de 10.000." << endl;
        break;
        case 2:
            valor = valor / 20000;
            cout << "Son " << valor << " billetes de 20.000." << endl;
        break;
        case 3:
            valor = valor / 50000;
            cout << "Son " << valor << " billetes de 50.000." << endl;
        break;
        case 4:
            valor = valor / 100000;
            cout << "Son " << valor << " billetes de 100.000." << endl;
        break;
        default:
            cout << "Denominacion invalida." << endl;
    }

    return 0;
}
