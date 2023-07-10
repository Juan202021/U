#include <iostream>

using namespace std;

int main()
{
/*Realiza un programa que lea un entero positivo N y encuentre e imprima cuantos números
naturales desde 2 hasta 10 son divisores exactos de N*/
    int num, divisores=0;
    cin >> num;

    for(int i=2; i<=10; i++){
        if (num%i==0){
            divisores +=1;
        }
    }
    cout<<divisores<<endl;

    return 0;
}
