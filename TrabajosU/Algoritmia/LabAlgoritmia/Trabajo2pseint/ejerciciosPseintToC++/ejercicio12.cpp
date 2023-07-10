#include <iostream>

using namespace std;

int main()
{
    int opc;
    float peso, dolar, euro;
    cout << "***Programa para convertir pesos a dolares y a euros***" << endl;
    cout << "Escriba el valor en pesos: " << endl;
    cin >> peso;
    cout << "Digite la opcion correspondiente al proceso que desea realizar: " << endl;
    cout << "Digite (1) si desea convertir a Dolar" << endl;
    cout << "Digite (2) si desea convertir a Euro" << endl;
    cin >> opc;
    switch (opc){
        case 1:
            dolar = peso / 4896.56;
            cout << "El valor en dolares es: " << dolar << endl;
        break;
        case 2:
            euro = peso / 4871.74;
            cout << "El valor en euros es: " << euro << endl;
        break;
        default:
            cout << "El valor que inserto es invalido."<< endl;
    }
    return 0;
}
