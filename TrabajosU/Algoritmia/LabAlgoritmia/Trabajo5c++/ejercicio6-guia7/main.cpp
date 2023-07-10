#include <iostream>

using namespace std;

int main()
{
/*Realizar un Algoritmo que lea un entero positivo X e imprima cuantos términos de la serie
de Fibonacci son menores o iguales que X.*/

    int ante, sig, x, cant=0;
    ante=0;
    sig=1;

    cin >> x;

    for(int i=0; i<x; i++){

        if (ante <= x){
            cant ++;
        } else {
            break;
        }

        if (sig <= x){
            cant ++;
        } else {
            break;
        }
        ante += sig;
        sig += ante;

    }
    cout << "La cantidad de numeros de Fibonacci que hay menores al numero es de: " << cant << endl;

    return 0;
}
