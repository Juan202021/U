#include <iostream>
#include <string>
using namespace std;

class LibroCalificaciones
{
public:
    explicit LibroCalificaciones( string nombre )
    : nombreCurso ( nombre )
    {

    }
    void establecerNombreCurso( string nombre )
    {
        nombreCurso = nombre;
    }
    string obtenerNombreCurso()const
    {
        return nombreCurso;
    }
    void mostrarMensaje()const
    {
        cout <<"Bienvenido al libro de calificaciones para\n"
        <<obtenerNombreCurso()
        <<"!"<<endl;
    }
private:
    string nombreCurso;
};

int main()
{
    LibroCalificaciones libroCalificaciones1( "CS101 Introduccion a la programacion en C++" );
    LibroCalificaciones libroCalificaciones2( "CS102 Estructuras de datos en C++" );
    cout << "libroCalificaciones1 se creo para el curso: "
    << libroCalificaciones1.obtenerNombreCurso()
    <<"\nlibroCalificaciones2 se creo para el curso: "
    <<libroCalificaciones2.obtenerNombreCurso()
    << endl;

}

