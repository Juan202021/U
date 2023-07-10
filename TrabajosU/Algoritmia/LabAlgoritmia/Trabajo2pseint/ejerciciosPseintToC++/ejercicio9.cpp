#include <iostream>

using namespace std;

int main(){
    
    float nota1, nota2, nota3, notaFinal, validador1 = 1, validador2 = 1, validador3 = 1;
    
    cout << "***Algoritmo para calcular la nota final***" << endl;
        
    while (validador1 == 1)
    {
        cout << "Ingrese la primera nota, un numero entre 0 y 5 (valor porcentual: 30%): " << endl;
        cin >> nota1;
        if (nota1 >= 0 && nota1 <= 5) {
            validador1 = 0;
        }
    }
    while (validador2 == 1)
    {
        cout << "Ingrese la segunda nota, un numero entre 0 y 5 (valor porcentual: 30%): " << endl;
        cin >> nota2;
        if (nota2 >= 0 && nota2 <= 5) {
            validador2 = 0;
        }
    }
    while (validador3 == 1)
    {
        cout << "Ingrese la tercera nota, un numero entre 0 y 5 (valor porcentual: 40%): " << endl;
        cin >> nota3;
        if (nota3 >= 0 && nota3 <= 5) {
            validador3 = 0;
        }
    }

    nota1 = nota1 * 0.30;
    nota2 = nota2 * 0.30;
    nota3 = nota3 * 0.40;
    notaFinal = nota1 + nota2 + nota3;
    cout << "La nota definitiva es: " << notaFinal <<endl; 
    
    return 0;
}
