#include <iostream>
using namespace std;

int cuadrado( int );

int main()
{
    int a = 10;

    cout << a << " al cuadrado: " << cuadrado( a ) << endl; // muestra a al cuadrado
}

int cuadrado( int x )
{
    return x * x;
}
