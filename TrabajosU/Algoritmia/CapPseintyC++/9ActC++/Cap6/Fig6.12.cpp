#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    default_random_engine motor( static_cast<unsigned int>( time(0) ) );
    uniform_int_distribution<unsigned int> intAleatorio( 1, 6 );

    for ( unsigned int contador = 1; contador <= 10; ++contador )
    {
        cout << setw( 10 ) << intAleatorio( motor );
        if ( contador % 5 == 0 )
            cout << endl;
    }
}

