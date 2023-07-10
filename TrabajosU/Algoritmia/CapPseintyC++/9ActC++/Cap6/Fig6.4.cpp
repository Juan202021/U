#include <iostream>
using namespace std;

#include "LibroCalificacionesFig6.3.h"

LibroCalificaciones::LibroCalificaciones( string nombre )
    : calificacionMaxima( 0 )
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

    cout << "Bienvenido al libro de calificaciones para\n"
         << obtenerNombreCurso() << "!\n"
         << endl;
}

void LibroCalificaciones::recibirCalificaciones()
{
    int calificacion1;
    int calificacion2;
    int calificacion3;

    cout << "Introduzca tres calificaciones enteras: ";
    cin >> calificacion1 >> calificacion2 >> calificacion3;

    calificacionMaxima = maximo( calificacion1, calificacion2, calificacion3 );
}

int LibroCalificaciones::maximo( int x, int y, int z ) const
{
    int valorMaximo = x;

    if ( y > valorMaximo )
        valorMaximo = y;

    if ( z > valorMaximo )
        valorMaximo = z;

    return valorMaximo;
}

void LibroCalificaciones::mostrarReporteCalificaciones() const
{
    cout << "Calificacion maxima introducida: " << calificacionMaxima << endl;
}
