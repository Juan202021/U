#include "LibroCalificaciones5.9.h"

int main()
{
    LibroCalificaciones miLibroCalificaciones( "CS101 Programacion en C++" );

    miLibroCalificaciones.mostrarMensaje();

    miLibroCalificaciones.recibirCalificaciones();

    miLibroCalificaciones.mostrarReporteCalificaciones();
}
