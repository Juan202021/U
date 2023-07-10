#include <iostream>
#include <iomanip>
#include "LibroCalificaciones7.22.h"

using namespace std;

LibroCalificaciones::LibroCalificaciones( const string &nombre, std::array< std::array< int, pruebas >, estudiantes > &arregloCalificaciones )
    : nombreCurso( nombre ), calificaciones( arregloCalificaciones ){
    }

void LibroCalificaciones::establecerNombreCurso( const string &nombre ){

    nombreCurso = nombre;
}

string LibroCalificaciones::obtenerNombreCurso() const{

    return nombreCurso;
}

void LibroCalificaciones::mostrarMensaje() const{

    cout << "Bienvenido al libro de calificaciones para\n"
    << obtenerNombreCurso() << "!"
        << endl;
}

void LibroCalificaciones::procesarCalificaciones() const{

    imprimirCalificaciones();

    cout << "\nLa calificacion mas baja en el libro de calificaciones es "
    << obtenerMinimo()
        << "\nLa calificacion mas alta en el libro de calificaciones es "
        << obtenerMaximo() << endl;

    imprimirGraficoBarras();
}

int LibroCalificaciones::obtenerMinimo() const{

    int calificacionInf = 100;

    for (auto const &estudiante : calificaciones){

        for (auto const &calificacion : estudiante){

            if (calificacion < calificacionInf)
                calificacionInf = calificacion;
        }
    }

    return calificacionInf;
}

int LibroCalificaciones::obtenerMaximo() const{

    int calificacionSup = 0;

    for ( auto const &estudiante : calificaciones ){

        for ( auto const &calificacion : estudiante ){

            if ( calificacion > calificacionSup )
                calificacionSup = calificacion;
        }
    }

    return calificacionSup;
}

double LibroCalificaciones::obtenerPromedio(const array<int, pruebas> &conjuntoDeCalificaciones) const{

    int total = 0;

    for (int calificacion : conjuntoDeCalificaciones)
        total += calificacion;

    return static_cast< double >(total) / conjuntoDeCalificaciones.size();
}

void LibroCalificaciones::imprimirGraficoBarras() const{

    cout << "\nDistribucion general de calificaciones:" << endl;

    const size_t tamanioFrecuencia = 11;
    array< unsigned int, tamanioFrecuencia > frecuencia = {};

    for (auto const &estudiante : calificaciones)
        for (auto const &prueba : estudiante)
            ++frecuencia[ prueba / 10 ];

    for (size_t cuenta = 0; cuenta < tamanioFrecuencia; ++cuenta){

        if (0 == cuenta)
            cout << "  0-9: ";
        else if (10 == cuenta)
            cout << "  100: ";
        else
            cout << cuenta * 10 << "-" << ( cuenta * 10 ) + 9 << ": ";

        for (unsigned int estrellas = 0; estrellas < frecuencia[ cuenta ]; estrellas++)
            cout << '*';

        cout << endl;
    }
}

void LibroCalificaciones::imprimirCalificaciones() const{

    cout << "\nLas calificaciones son:\n\n";
    cout << "          ";

    for ( size_t prueba = 0; prueba < pruebas; ++prueba )
        cout << "Prueba " << prueba + 1 << " ";

    cout << "Promedio" << endl;

    for (size_t estudiante = 0; estudiante < calificaciones.size(); ++estudiante){

        cout << "Estudiante " << setw( 2 ) << estudiante + 1;

        for (size_t prueba = 0; prueba < calificaciones[estudiante].size(); ++prueba)
            cout << setw(8) << calificaciones[ estudiante ][ prueba ];

        double promedio = obtenerPromedio(calificaciones[estudiante]);
        cout << setw(9) << setprecision( 2 ) << fixed << promedio << endl;
    }
}
