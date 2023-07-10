#include <iostream>

using namespace std;

int main()
{
    int ante, sig, num, aux;
    ante=0;
    sig=1;

    cout << "**Programa que muestra los numeros menores o iguales de la serie de Fibonacci**" << endl;
    cout << "Digite un numero: ";
    cin >> num;

    while(ante<=num){
        cout << " | " << ante;
        aux = ante;
        ante = sig;
        sig += aux;
    }

    return 0;
}
