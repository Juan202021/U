#include <iostream>

using namespace std;

int main()
{
    cout << "***Programa para clacular el area de un rectangulo***" << endl;
    float base, altura, area;
    cout << "Digite la base del rectangulo (en centimetros): ";
    cin >> base;
    cout << "Digite la altura del rectangulo (en centimetros): ";
    cin >> altura;
    area = base * altura;
    cout << "El area del rectangulo es: "<< area<< endl;

    return 0;
}
