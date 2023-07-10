#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "***Programa para calcular el area de una circunferencia***" << endl;
    float radio, area;
    cout << "Escriba el valor del radio de la circunferencia (en centimetros): ";
    cin >> radio;
    area = M_PI * radio*radio;
    cout << "El area de la circunferencia es: "<< area<< endl;

    return 0;
}
