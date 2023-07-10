#include <iostream>

using namespace std;

int main()
{
    unsigned int total=0;
    for (unsigned int numero=2; numero<=20;numero+=2)
        total+=numero;
    cout << "La suma es " << total << endl;
    return 0;
}
