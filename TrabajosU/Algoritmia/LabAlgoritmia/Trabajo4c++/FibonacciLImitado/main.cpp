#include <iostream>

using namespace std;

int main()
{
    int aux, ante, sig, n;
    ante = 0;
    sig = 1;

    cout << "***Programa que muestra los numeros de la serie de Fibonacci***" << endl;
    cout << "Digite la cantidad de numeros que desea generar: ";
    cin >> n;
    for(int i=0; i<n; i++){

        cout << " | " << ante;
        aux = ante;
        ante = sig;
        sig += aux;
    }
    return 0;
}

