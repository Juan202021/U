#include <iostream>

using namespace std;

int main()
{
    cout << "***Algoritmo para calcular la suma de dos numeros***" << endl;
    float num1, num2, suma;
    cout << "Escriba el primer numero: ";
    cin >> num1;
    cout << "Escriba el segundo numero: ";
    cin >> num2;
    suma = num1 + num2;
    cout << "El resultado de la suma es: "<< suma<< endl;

    return 0;
}
