#include <iostream>

using namespace std;

int main()
{
    int edad;
    char sexo;
    cout << "***Programa para calcular si la persona ya alcanzo la edad para pension***" << endl;
    cout << "Digite (m) si es hombre o digite (f) si es mujer: ";
    cin >> sexo;
    cout << "Digite su edad: ";
    cin >> edad;
    switch (sexo){
        case 'M':
        case 'm':
            if (edad >= 62){
                cout << "Tiene la edad necesaria para pensionarse" << endl;
            } else {
                cout << "No tiene la edad necesaria para pensionarse" << endl;
            }
            break;
        case 'F':
        case 'f':
            if (edad >= 57){
                cout << "Tiene la edad necesaria para pensionarse" << endl;
            } else {
                cout << "No tiene la edad necesaria para pensionarse" << endl;
            }
            break;
    }
    
    return 0;
}
