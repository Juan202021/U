#include <iostream>
using namespace std;

int main()
{
    for ( unsigned int cuenta = 1; cuenta <= 10; ++cuenta )
    {
        if ( cuenta == 5 )
            continue;

        cout << cuenta << " ";
    }

    cout << "\nSe uso continue para no imprimir el 5" << endl;
}
