#include <iostream>

using namespace std;

int sumarDigitos(int);

int main() {
    int num;
    cout << "Digite un numero: ";
    cin >> num;
    cout << "La suma de los digitos de " << num << " es: " << sumarDigitos(num);
    return 0;
}

int sumarDigitos(int num){
    int suma=0;
    while(num>0){
        suma += num % 10;
        num /= 10;
    }
    return suma;
}