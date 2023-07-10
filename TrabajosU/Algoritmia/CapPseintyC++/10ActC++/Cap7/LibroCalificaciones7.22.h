#include <array>
#include <string>

class LibroCalificaciones{

public:
    static const size_t estudiantes = 10;
    static const size_t pruebas = 3;

    LibroCalificaciones(const std::string &, std::array< std::array< int, pruebas >, estudiantes > &);

    void establecerNombreCurso(const std::string &);

    std::string obtenerNombreCurso() const;
    void mostrarMensaje() const;
    void procesarCalificaciones() const;

    int obtenerMinimo() const;
    int obtenerMaximo() const;

    double obtenerPromedio( const std::array< int, pruebas > & ) const;
    void imprimirGraficoBarras() const;

    void imprimirCalificaciones() const;

private:
    std::string nombreCurso;
    std::array< std::array< int, pruebas >, estudiantes > calificaciones;
};
