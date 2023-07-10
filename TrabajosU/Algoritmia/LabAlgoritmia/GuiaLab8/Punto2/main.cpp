#include <iostream>

using namespace std;

int main()
{
    int tam, n;
    cout << "Digite el tamaño del cual desea crear los arreglos: ";
    cin >> tam;

    int arrA[tam], arrB[tam], arrC[tam];

    cout << endl;
    cout << "Digite los elementos del arreglo A: " << endl;
    for (int i=0; i<tam; i++){
            cin >> n;
            arrA[i] = n;
    }

    cout << endl;
    cout << "Digite los elementos del arreglo B: " << endl;
    for (int j=0; j<tam; j++){
            cin >> n;
            arrB[j] = n;
    }

    for (int k=0; k<tam; k++){
        arrC[k] = arrA[k] + arrB[k];
    }

    cout << endl;
    cout << "Arreglo A: " << endl;
    for (int i=0; i<tam; i++){
        cout << arrA[i] << " ";
    }

    cout << endl;
    cout << "Arreglo B: " << endl;
    for (int j=0; j<tam; j++){
        cout << arrB[j] << " ";
    }

    cout << endl;
    cout << "Arreglo C: " << endl;
    for (int k=0; k<tam; k++){
        cout << arrC[k] << " ";
    }

    return 0;
}
