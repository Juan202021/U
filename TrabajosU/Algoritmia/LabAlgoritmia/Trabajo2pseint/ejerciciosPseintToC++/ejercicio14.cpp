#include <iostream>

using namespace std;

int main()
{
    int mes, dia;
    cout << "***Programa para calcular el signo zodiacal de alguien***" << endl;
    cout << "Digite el numero de su mes de nacimiento:" << endl;
    cin >> mes;
    cout << "Digite el numero de dia de su nacimiento: " << endl;
    cin >> dia;

    switch (mes){
        case 1:
            if (dia <= 20){
                cout << "Su signo es Capricornio" << endl;
            } else {
                cout << "Su signo es Acuario" << endl;
            }
        break;
        case 2:
            if (dia <= 20){
                cout << "Su signo es Acuario" << endl;
            } else {
                cout << "Su signo es Piscis" << endl;
            }
        break;
        case 3:
            if (dia <= 20){
                cout << "Su signo es Piscis" << endl;
            } else {
                cout << "Su signo es Aries" << endl;
            }
        break;
        case 4:
            if (dia <= 20){
                cout << "Su signo es Aries" << endl;
            } else {
                cout << "Su signo es Tauro" << endl;
            }
        break;
        case 5:
            if (dia <= 20){
                cout << "Su signo es Tauro" << endl;
            } else {
                cout << "Su signo es Geminis" << endl;
            }
        break;
        case 6:
            if (dia <= 20){
                cout << "Su signo es Geminis" << endl;
            } else {
                cout << "Su signo es Cancer" << endl;
            }
        break;
        case 7:
            if (dia <= 20){
                cout << "Su signo es Cancer" << endl;
            } else {
                cout << "Su signo es Leo" << endl;
            }
        break;
        case 8:
            if (dia <= 20){
                cout << "Su signo es Leo" << endl;
            } else {
                cout << "Su signo es Virgo" << endl;
            }
        break;
        case 9:
            if (dia <= 20){
                cout << "Su signo es Virgo" << endl;
            } else {
                cout << "Su signo es Libra" << endl;
            }
        break;
        case 10:
            if (dia <= 20){
                cout << "Su signo es Libra" << endl;
            } else {
                cout << "Su signo es Escorpio" << endl;
            }
        break;
        case 11:
            if (dia <= 20){
                cout << "Su signo es Escorpio" << endl;
            } else {
                cout << "Su signo es Sagitario" << endl;
            }
        break;
        case 12:
            if (dia <= 20){
                cout << "Su signo es Sagitario" << endl;
            } else {
                cout << "Su signo es Capricornio" << endl;
            }
        break;
        default:
            cout << "Ingreso un valor invalido." << endl;
    }

    return 0;
}
