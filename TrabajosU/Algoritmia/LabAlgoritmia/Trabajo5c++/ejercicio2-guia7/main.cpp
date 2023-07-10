#include <iostream>

using namespace std;

int main()
{
/*Realizar un programa que lea un entero positivo N y encuentre e imprima si N es o no un
número primo. (Nota: N es primo si en el rango desde 2 hasta N – 1 no tiene ningún divisor
exacto)*/
    int n, divisores=0;
    cin >> n;

    for (int i=2; i<n; i++){
        if (n%i==0){
            divisores++;
        }
    }
    if (divisores != 0){
        cout << "El numero "<<n<< " NO es primo. "<< endl;
    } else{
        cout << "El numero "<<n<< " es primo. "<< endl;
    }

    return 0;
}
