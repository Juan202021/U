#include <iostream>

using namespace std;

int main()
{
/*Realizar un programa que lea un entero positivo (X) y determine e imprima si X es un
número perfecto, abundante o deficiente. Un número es perfecto cuando la suma de los
divisores da el mismo número (6). Un número es abundante cuando la suma de sus
divisores da más que el número (12). Un número es deficiente cuando la suma de sus
divisores da menos que el número (8).*/

    int n, divisores=0;
    cin >> n;

    for(int i=1; i<n; i++){
        if (n%i==0){
            divisores += i;
        }
    }
    if (divisores > n){
        cout << "El numero es abundante" << endl;
    } else if (divisores < n){
        cout << "El numero es deficiente" << endl;
    } else {
        cout << "El numero es perfecto" << endl;
    }

    return 0;
}
