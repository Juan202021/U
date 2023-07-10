#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int rollDice();

unsigned int tirarDados()
{
    unsigned int dado1 = 1 + rand() % 6;
    unsigned int dado2 = 1 + rand() % 6;
    unsigned int suma = dado1 + dado2;
    cout << "El jugador tiro " << dado1 << " + " << dado2
         << " = " << suma << endl;
    return suma;
}

int main()
{

    enum Estado { CONTINUAR, GANO, PERDIO };

    srand( static_cast<unsigned int>( time( 0 ) ) );

    unsigned int miPunto = 0;
    Estado estadoJuego = CONTINUAR;
    unsigned int sumaDeDados = tirarDados() ;

    switch ( sumaDeDados )
    {
    case 7:
    case 11:
        estadoJuego = GANO;
        break;
    case 2:
    case 3:
    case 12:
        estadoJuego = PERDIO;
        break;
    default:
        estadoJuego = CONTINUAR;
        miPunto = sumaDeDados;
        cout << "El punto es " << miPunto << endl;
        break;
    }

    while ( CONTINUAR == estadoJuego )
    {
        sumaDeDados = tirarDados();

        if ( sumaDeDados == miPunto )
            estadoJuego = GANO;
        else if ( sumaDeDados == 7 )
            estadoJuego = PERDIO;
    }

    if ( GANO == estadoJuego )
        cout << "El jugador gana" << endl;
    else
        cout << "El jugador pierde" << endl;
}


