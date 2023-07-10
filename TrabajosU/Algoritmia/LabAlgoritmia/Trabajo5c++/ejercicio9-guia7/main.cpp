#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*Un algoritmo que lea 2 enteros positivos (A,B). Se puede asumir A< B. Encuentre e imprima en el
    rango desde A hasta B, cual número es el que tiene mas divisores. */

    int a, b, divisores=0, cantDivisores=0, masDivisores;

    cin >> a >> b;

    for (int i=a; i<=b; i++)
    {
        for (int j=1; j<i; j++)
        {
            if (i%j==0)
            {
                divisores += 1;
            }
        }
        if (divisores>cantDivisores){
                cantDivisores = divisores;
                masDivisores = i;
            }
        divisores = 0;
    }
    cout << "El numero con mayor cantidad de divisores es: " << masDivisores;
    return 0;
}
