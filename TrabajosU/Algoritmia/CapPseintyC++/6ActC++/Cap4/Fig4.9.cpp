#include <iostream>
#include "LibroCalificacionesfig4.8.h"
using namespace std;

LibroCalificaciones::LibroCalificaciones ( string nombre )
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
    unsigned int contadorCalif=1;

    while (contadorCalif<=10)
    {
        cout<<"Escriba una calificacion: " ;
        int calificacion=0;
        cin>>calificacion;
        total=total+calificacion;
        contadorCalif=contadorCalif+1;
    }
    int promedio=total/10;

    cout<<"\nEl total de las 10 calificaciones es "<<total<<endl;
    cout<<"El promedio de la clase es "<<promedio<<endl;
}
