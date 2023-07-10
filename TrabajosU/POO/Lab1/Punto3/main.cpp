#include <iostream>
#include <string>

using namespace std;

int contar_espacios(string);

int main()
{
    string cadena;
    cout << "Introduzca una cadena: ";
    getline(cin, cadena);

    cout << "Espacios: " << contar_espacios(cadena) << endl;
    return 0;
}

int contar_espacios(string cadena){
    int espacios = 0;
    for (int i=0; i<cadena.length(); i++){
        if (cadena[i]==' '){
            espacios++;
        }
    }
    return espacios;
}
