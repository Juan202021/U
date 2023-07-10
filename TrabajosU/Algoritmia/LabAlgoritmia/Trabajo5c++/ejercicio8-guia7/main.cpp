#include <iostream>

using namespace std;

int main()
{
/*Un algoritmo que lea un entero positivo (N) y genere e imprima
ej: N= 4
1 – ½ + 1/3 - 1/4 */

    int n;
    float resp=0, ope;
    cin >> n;

    for(int i=1; i<=n; i++){
        ope = 1/(float)i;
        if (i%2==0){
            ope *= -1;
        }
        resp += ope;
    }
    cout << "El resultado es: " << resp << endl;
    return 0;
}
