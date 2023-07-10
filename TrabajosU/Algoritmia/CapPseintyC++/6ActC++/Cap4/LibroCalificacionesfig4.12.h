#ifndef LIBROCALIFICACIONES_H_INCLUDED
#define LIBROCALIFICACIONES_H_INCLUDED

#include <string>

class LibroCalificaciones
{
public:
    explicit LibroCalificaciones( std::string );
    void establecerNombreCurso( std::string );
    std::string obtenerNombreCurso()const;
    void mostrarMensaje()const;
    void determinarPromedioClase()const;

private:
    std::string nombreCurso;
};
#endif // LIBROCALIFICACIONES_H_INCLUDED
