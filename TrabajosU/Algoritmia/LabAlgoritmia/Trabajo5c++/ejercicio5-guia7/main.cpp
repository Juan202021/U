#include <iostream>

using namespace std;

int main()
{
/*Realizar un Algoritmo que lea un entero positivo (X) y genere e imprima los términos de la
seria de Fibonacci menores o iguales que x.
*/
    int ante, sig, x;
    ante=0;
    sig=1;

    cin >> x;

    for(int i=0; i<x; i++){

        if (ante <= x){
            cout << ante << endl;
        } else {
            break;
        }

        if (sig <= x){
            cout << sig << endl;
        } else {
            break;
        }
        ante += sig;
        sig += ante;

    }

    return 0;
}
