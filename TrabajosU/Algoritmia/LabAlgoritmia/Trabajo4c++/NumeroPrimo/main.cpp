#include <iostream>

using namespace std;

int main()
{
    int num, divisores=0;
    cout<<"Escriba un numero: " << endl;
    cin >> num;
    for (int i=2; i<num; i++){

        if (num%i==0){
            divisores ++;
        }
    }
    if (divisores > 0 || num == 1 || num == 0){
        cout << "El numero no es primo" << endl;
    } else {
        cout << "El numero es primo" << endl;
    }
    return 0;
}
