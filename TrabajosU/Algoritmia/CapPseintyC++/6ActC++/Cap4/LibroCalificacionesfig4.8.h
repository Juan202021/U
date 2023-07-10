#ifndef LIBROCALIFICACIONESFIG4_8_H_INCLUDED
#define LIBROCALIFICACIONESFIG4_8_H_INCLUDED
#include <string>

class LibroCalificaciones
{
public:
    explicit LibroCalificaciones( std::string );
    void establecerNombreCurso ( std::string );
    std::string obtenerNombreCurso() const;
    void mostrarMensaje() const;
    void determinarPromedioClase() const;

private:
    std::string nombreCurso;
};


#endif // LIBROCALIFICACIONESFIG4_8_H_INCLUDED
