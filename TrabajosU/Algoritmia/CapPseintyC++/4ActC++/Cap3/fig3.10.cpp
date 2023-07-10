#include <iostream>
#include "LibroCalificacionesfig3.9.h"
using namespace std;

int main()
{
    LibroCalificaciones libroCalificaciones1( "CS101 Introduccion a la programacion en C++");
    LibroCalificaciones libroCalificaciones2( "CS102 Estructura de datos en C++");
    cout << "libroCalificaciones1 creado para el curso: "
    <<libroCalificaciones1.obtenerNombreCurso()
        <<"\nlibroCalificaciones2 creado para el curso: "<<libroCalificaciones2.obtenerNombreCurso()
        << endl;
}
