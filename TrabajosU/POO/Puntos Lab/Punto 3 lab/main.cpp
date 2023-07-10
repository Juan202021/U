#include <iostream>

using namespace std;

int palindromo(int);

int main() {
    int num;
    cout << "Digite un numero: ";
    cin >> num;

    palindromo(num);
    return 0;
}
int palindromo(int numero){
    int arreglo[15], i=0;
    while(numero>0){
        arreglo[i] = numero%10;
        numero /= 10;
        i++;
    }
    for(int j=0; j<i; j++){
        if (arreglo[j] != arreglo[i-1]){
            cout << arreglo[j] << " " << arreglo[i-1] << endl;
            cout << "El numero NO es palindromo." << endl;
            return 0;
        }
        i--;
    }
    cout << "El numero es palindromo." << endl;
}