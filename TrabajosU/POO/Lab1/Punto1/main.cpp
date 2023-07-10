#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

void to_int(string);
float promedio(int);
const int tam = 5;

int main()
{
    string str;

    cout << "Introduzca los numeros: ";
    getline(cin, str);
    to_int(str);

    return 0;
}
void to_int(string str){
    int num, suma=0;
    string aux;
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    for (int j=0; j<tam; j++){
        aux = str[j];
        istringstream(aux) >> num;
        suma += num;
    }
    cout << fixed << setprecision(1);
    cout << "La suma de los numeros es: " << suma << endl;
    cout << "El promedio es: " << promedio(suma) << endl;
}

float promedio(int num){
    float prom=num;
    prom /= 5.0;
    return prom;
}
