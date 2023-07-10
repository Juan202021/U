#include <iostream>
using namespace std;

void usarLocal();
void usarLocalStatic();
void usarGlobal();

int x = 1;

int main()
{
    cout << "la x global en main es " << x << endl;
    int x = 5;

    cout << "la x local en el alcance exterior de main es " << x << endl;

    {
        int x = 7;

        cout << "la x local en el alcance interior de main es " << x << endl;
    }

    cout << "la x local en el alcance exterior de main es " << x << endl;

    usarLocal();
    usarLocalStatic();
    usarGlobal();
    usarLocal();
    usarLocalStatic();
    usarGlobal();

    cout << "\nla x local en main es " << x << endl;
}
void usarLocal()
{
    int x = 25;

    cout << "\nla x local es " << x << " al entrar a usarLocal" << endl;

    ++x;
    cout << "la x local es " << x << " al salir de usarLocal" << endl;
}
void usarLocalStatic()
{

    static int x = 50;
    cout << "\nla x local estatica es " << x << " al entrar a usarLocalStatic"
         << endl;
    ++x;
    cout << "la x local estatica es " << x << " al salir de usarLocalStatic"
         << endl;
}
void usarGlobal()
{
    cout << "\nla x global es " << x << " al entrar a usarGlobal" << endl;
    x *= 10;
    cout << "la x global es " << x << " al salir de usarGlobal" << endl;
}
