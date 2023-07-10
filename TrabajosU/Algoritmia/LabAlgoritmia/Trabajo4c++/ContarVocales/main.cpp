#include <iostream>

using namespace std;

int main()
{
    char letra;
    int vocales=0;
    for (int i=1; i<=10; i++){
        cout << "Escriba una letra: " << endl;
        cin >> letra;
        letra = toupper(letra);
        if (letra == 'A' ||letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' ){
            vocales +=1;
        }
    }
    cout << "La cantidad de vocales es: " << vocales << endl;

    return 0;
}
