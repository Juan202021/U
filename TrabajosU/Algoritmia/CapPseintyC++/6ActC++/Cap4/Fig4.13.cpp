#include <iostream>
#include <iomanip>
#include "LibroCalificacionesfig4.12.h"

using namespace std;

LibroCalificaciones::LibroCalificaciones(string nombre)
{
    establecerNombreCurso( nombre );
}
void LibroCalificaciones::establecerNombreCurso( string nombre )
{
    if (nombre.size()<= 25){
        nombreCurso=nombre;
    }
    else {
        nombreCurso=nombre.substr( 0,25);
        cerr<<"El nombre \""<< nombre << "\"  excede la longitud maxima (25).\n"
        <<"Se limito nombreCurso a los primeros 25 caracteres.\n" <<endl;
    }
}
string LibroCalificaciones::obtenerNombreCurso()const
{
    return nombreCurso;
}

void LibroCalificaciones::mostrarMensaje()const
{
    cout<<"Bienvenido al libro de calificaciones para \n"
    << obtenerNombreCurso()<<"!\n"
    <<endl;
}

void LibroCalificaciones::determinarPromedioClase()const
{
    int total=0;
    unsigned int contadorCalif=0;

    cout << "Escriba una calificacion o -1 para salir: " ;
    int calificacion = 0;
    cin >> calificacion;

    while (calificacion != -1)
    {
        total = total + calificacion;
        contadorCalif = contadorCalif + 1;
        cout << "Escriba una calificacion o -1 para salir: " ;
        cin >> calificacion;
    }
    if (contadorCalif != 0)
    {
        double promedio = static_cast< double >( total ) / contadorCalif;

        cout << "\nEl total de las " << contadorCalif
        << " calificaciones introducidas es "
        << total << endl;
        cout << setprecision(2) << fixed;
        cout << "El promedio de la clase es " << promedio << endl;
    } else {
        cout << "No se introdujeron calificaciones" << endl;
    }


}
