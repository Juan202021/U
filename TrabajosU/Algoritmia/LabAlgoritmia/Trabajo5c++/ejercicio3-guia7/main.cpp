#include <iostream>
#include <cmath>
using namespace std;

int main()
{
/*Realzar un programa que lea un entero positivo (X) y genere e imprima todos los naturales
cuyo cubo es menor que x.*/

    int x;
    cin >> x;

    for (int i=1; pow(i,3)<x; i++){
        cout << i <<endl;
    }

    return 0;
}
