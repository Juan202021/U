#include <iostream>

using namespace std;

int main()
{
    cout << "***Programa para calcular el promedio de las notas***" << endl;
    float n1, n2, n3, n4, suma, prom;
    cout << "Digite la primera nota: ";
    cin >> n1;
    cout << "Digite la segunda nota: ";
    cin >> n2;
    cout << "Digite la tercera nota: ";
    cin >> n3;
    cout << "Digite la cuarta nota: ";
    cin >> n4;
    suma = n1 + n2 + n3 + n4;
    prom = suma / 4;
    cout << "El promedio de notas es: "<< prom<< endl;

    return 0;
}
