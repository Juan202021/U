#include <iostream>
#include "LibroCalificaciones5.9.h"

using namespace std;

LibroCalificaciones::LibroCalificaciones( string nombre )
    : aCuenta( 0 ),
      bCuenta( 0 ),
      cCuenta( 0 ),
      dCuenta( 0 ),
      fCuenta( 0 )
{
    establecerNombreCurso( nombre );
}

void LibroCalificaciones::establecerNombreCurso( string nombre )
{
    if ( nombre.size() <= 25 )
        nombreCurso = nombre;
    else
    {
        nombreCurso = nombre.substr( 0, 25 );
        cerr << "El nombre \"" << nombre << "\" excede la longitud maxima (25).\n"
             << "Se limito nombreCurso a los primeros 25 caracteres.\n" << endl;
    }
}

string LibroCalificaciones::obtenerNombreCurso() const
{
    return nombreCurso;
}

void LibroCalificaciones::mostrarMensaje() const
{
    cout << "Bienvenido al libro de calificaciones para\n" << obtenerNombreCurso()
         << "!\n"
         << endl;
}

void LibroCalificaciones::recibirCalificaciones()
{
    int calificacion;
    cout << "Escriba las calificaciones de letra." << endl
         << "Escriba el caracter EOF para terminar la entrada." << endl;

    while ( ( calificacion = cin.get() ) != EOF )
    {
        switch ( calificacion )
        {
        case 'A':
        case 'a':
            ++aCuenta;
            break;
        case 'B':
        case 'b':
            ++bCuenta;
            break;
        case 'C':
        case 'c':
            ++cCuenta;
            break;

        case 'D':
        case 'd':
            ++dCuenta;
            break;

        case 'F':
        case 'f':
            ++fCuenta;
            break;

        case '\n':
        case '\t':
        case ' ':
            break;

        default:
            cout << "Se introdujo una letra de calificacion incorrecta."
                 << " Escriba una nueva calificacion." << endl;
            break;
        }
    }
}

void LibroCalificaciones::mostrarReporteCalificaciones() const
{
    cout << "\n\nNumero de estudiantes que recibieron cada calificacion de letra:"
         << "\nA: " << aCuenta
         << "\nB: " << bCuenta
         << "\nC: " << cCuenta
         << "\nD: " << dCuenta
         << "\nF: " << fCuenta
         << endl;
}
