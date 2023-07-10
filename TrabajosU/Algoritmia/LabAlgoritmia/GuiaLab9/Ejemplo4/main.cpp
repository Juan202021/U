#include <iostream>
#include <cstdlib>

using namespace std;

class operaciones
{
public:
    int primero;
    int segundo;
    int resultado;

    void sumar()
    {
        resultado = primero + segundo;
        cout << resultado << endl;
    }

    void restar()
    {
        resultado =  primero - segundo;
        cout << resultado << endl;
    }
    operaciones(int,int);
};

operaciones::operaciones(int dato1,int dato2)
{
    primero = dato1;
    segundo = dato2;
}

int main()
{
    operaciones objeto1(30,10);
    objeto1.sumar();
    objeto1.restar();
    system("pause");
    return 0;
}
