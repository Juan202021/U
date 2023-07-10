#include <iostream>

using namespace std;

int main()
{
    cout << "***Programa para calcular el area de un terreno***" << endl;
    float base, puntoAltTerreno, puntoBajTerreno, area1, area2, areaTotal;
    cout << "Digite la base del terreno: ";
    cin >> base;
    cout << "Digite el valor del punto mas alto de la altura del terreno: ";
    cin >> puntoAltTerreno;
    cout << "Digite el valor del punto mas bajo de la altura del terreno: ";
    cin >> puntoBajTerreno;
    area1 = base * puntoBajTerreno;
	area2 = base * (puntoAltTerreno - puntoBajTerreno) / 2;
	areaTotal = area1 + area2;
    cout << "El area del terreno es: "<< areaTotal<< endl;

    return 0;
}
