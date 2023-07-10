#include <iostream>

using namespace std;

int main()
{
    float num;
    cout << "***Programa para calcular si un numero es positivo o negativo***" << endl;
    cout << "Digite el numero: ";
    cin >> num;
    if (num > 0){
        cout << "El numero es positivo" << endl;
        
    } else if (num < 0){
        cout << "El numero es negativo" << endl;
    } else {
        cout << "El cero es neutro" << endl;
    }
    return 0;
}
