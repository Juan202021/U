#include <iostream>

using namespace std;

int main()
{
    cout << "***Programa para calcular el suedo semanal de un trabajador***" << endl;
    int horas, valorHora, sueldo;
    cout << "Digite el valor de la hora de trabajo: ";
    cin >> valorHora;
    cout << "Digite la cantidad de horas que trabajo en la semana: ";
    cin >> horas;
    sueldo = valorHora * horas;
    cout << "Su sueldo semanal es de: "<< sueldo<< endl;

    return 0;
}
