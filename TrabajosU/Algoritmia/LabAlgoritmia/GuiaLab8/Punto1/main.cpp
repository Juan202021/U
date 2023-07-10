#include <iostream>

using namespace std;

int main()
{
    int num[10], posicion[10];
    int n, mayor=0, cantidad, x;

    for (int i=0; i<10; i++)
    {
        cin >> n;
        num[i] = n;
    }

    cout << endl;

    for (int j=0; j<10; j++){
        if (num[j] > mayor){
            mayor = num[j];
            cantidad = 1;
            x = 0;
            posicion[x] = j;
        }
        else if (num[j] == mayor){
            cantidad++;
            x++;
            posicion[x] = j;
        }
    }

    cout << "\nEl numero mayor es " << mayor
         << " Aparece en el array " << cantidad << " veces,"
         << " localizado en la(s) posicion(es): " << endl;

    for (int k=0; k<cantidad; k++)
    {
        cout << posicion[k] << endl;
    }
    cout << endl;
    return 0;
}
