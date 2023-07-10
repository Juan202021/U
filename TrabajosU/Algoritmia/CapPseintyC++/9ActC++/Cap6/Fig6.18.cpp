#include <iostream>
using namespace std;

void funcion1();
void funcion2( void );

int main()
{
    funcion1();
    funcion2();
}

void funcion1()
{
    cout << "funcion1 no recibe argumentos" << endl;
}

void funcion2( void )
{
    cout << "funcion2 tampoco recibe argumentos" << endl;
}
