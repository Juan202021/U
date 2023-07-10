#include<iostream>
using namespace std;



void imprime_cadena(string cadena)
{
    cout<<cadena;
}
int main()
{

    string cadena = "Hola";
    imprime_cadena(cadena);
    imprime_cadena("mundo.\n");
}
