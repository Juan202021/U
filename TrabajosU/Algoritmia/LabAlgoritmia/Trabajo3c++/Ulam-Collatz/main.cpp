#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "***Programa que muestra los numeros de la serie de Ulam-Collatz***" << endl;
    cout << "Escriba un numero:" << endl;
    cin >> num;

    if (num>0)
    {
        while (!(num == 1))
        {
            if (num % 2 ==0)
            {
                num /= 2;
                cout << num << endl;
            }
            else
            {
                num = num*3+1;
                cout << num << endl;
            }

        }
    } else {
        cout << "Digito un numero invalido" << endl;
    }



    return 0;
}
