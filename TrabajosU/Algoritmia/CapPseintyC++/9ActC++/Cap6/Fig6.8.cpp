#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{

    for ( unsigned int contador = 1; contador <= 20; ++contador )
    {
        cout << setw( 10 ) << ( 1 + rand() % 6 );

        if ( contador % 5 == 0 )
            cout << endl;
    }
}
