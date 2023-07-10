#include <iostream>
#include "LibroCalificacionesfig3.15.h"

using namespace std;

int main()
{
    LibroCalificaciones libroCalificaciones1( "CS101 Introduccion a la programacion en C++" );

    LibroCalificaciones libroCalificaciones2( "CS102 C++:Estruc de datos" );

    cout << "el nombre inicial del curso de libroCalificaciones1 es: "
        << libroCalificaciones1.obtenerNombreCurso()
        << "\nel nombre inicial del curso de libroCalificaciones2 es: "
        << libroCalificaciones2.obtenerNombreCurso() << endl;

    libroCalificaciones1.establecerNombreCurso( "CS101 Programacion en C++");

    cout << "\nel nombre del curso de libroCalificaciones1 es: "
        << libroCalificaciones1.obtenerNombreCurso()
        << "\nel nombre del curso de libroCalificaciones2 es: "
        << libroCalificaciones2.obtenerNombreCurso() << endl;
}
