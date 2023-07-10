#include <iostream>

using namespace std;

int main()
{
/*Realizar un Algoritmo que lea un entero positivo (N ) y calcule e imprima la sumatoria:
Ej: N =4 1+ ½ +1/3 +1/4 */

    int n;
    float resp=0;
    cin >> n;

    for(float i=1; i<=n; i++){
        resp += 1/i;
    }
    cout << "El resultado es: " << resp << endl;
    return 0;
}
