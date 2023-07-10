#include <iostream>
#include <vector> // Uso de vectores
#include <sstream> // Uso del stringstram y los operadores de insercion
#include <iomanip> // Uso del fixed y el setprecision
#include <cstdlib> // Uso del system
#include <limits> // Uso del numeric_limits

using namespace std;

class Peliculas {
    string titulo, director, sinopsis, genero;
    int anio, duracion;
    double calificacion;
    bool disponible;
public:
    Peliculas() {
        titulo = "";
        director = "";
        anio = 0;
        sinopsis = "";
        duracion = 0;
        genero = "";
        calificacion = 0.0;
        disponible = false;
    }
    Peliculas(string titulo, string director, int anio, string sinopsis, int duracion, string genero,
              double calificacion, bool disponible) {
        this->titulo = titulo;
        this->director = director;
        this->anio = anio;
        this->sinopsis = sinopsis;
        this->duracion = duracion;
        this->genero = genero;
        this->calificacion = calificacion;
        this->disponible = disponible;
    }

    string duracionFormatoHora() const { // const porque no altera los atributos
        int horas = 0, minutos = duracion;
        while (minutos >= 60) {
            minutos -= 60;
            horas += 1;
        }
        return to_string(horas) + "h " + to_string(minutos) + " min";
    }
    string mostrarDisponible() const { // const porque no altera los atributos
        if (disponible) { return "Disponible"; }
        else { return "Prestado"; }
    }
    void resetear() {
        titulo = "";
        director = "";
        anio = 0;
        sinopsis = "";
        duracion = 0;
        genero = "";
        calificacion = 0.0;
        disponible = false;
    }

    string getTitulo() {
        return titulo;
    }
    void setTitulo(string titulo) {
        this->titulo = titulo;
    }

    string getDirector() {
        return director;
    }
    void setDirector(string director) {
        this->director = director;
    }

    string getSinopsis() {
        return sinopsis;
    }
    void setSinopsis(string sinopsis) {
        this->sinopsis = sinopsis;
    }

    string getGenero() {
        return genero;
    }
    void setGenero(string genero) {
        this->genero = genero;
    }

    int getAnio() {
        return anio;
    }
    void setAnio(int anio) {
        this->anio = anio;
    }

    int getDuracion() {
        return duracion;
    }
    void setDuracion(int duracion) {
        this->duracion = duracion;
    }

    double getCalificacion() {
        return calificacion;
    }
    void setCalificacion(double calificacion) {
        this->calificacion = calificacion;
    }

    bool getDisponible() {
        return disponible;
    }
    void setDisponible(bool disponible) {
        this->disponible = disponible;
    }

    string toString() {
        stringstream califi; // Creo un objeto stringstream.
        // Con los operadores de insersion, ingreso la calificacion con la presicion deseada
        // en el objeto califi, luego con la funcion califi.str() lo convierto a string.
        califi << fixed << setprecision(1) << calificacion;
        return "\nTitulo:        " + titulo + " (" + to_string(anio) + ")"
               + "\nCalificacion:  " + califi.str() + "\nDuracion:      " + duracionFormatoHora()
               + "\nDirector:      " + director + "\nGenero:        " + genero
               + "\nDisponible:    " + mostrarDisponible() + "\nSinopsis:\n" + sinopsis;
    }
};

void encabezado() {
    cout << "\n################################################" << endl;
    cout << "###       Sistema Gestion de Videoteca       ###" << endl;
    cout << "################################################\n" << endl;
}
int recibirOpcion(vector<int> &opcionesDisponibles) {
    string opc;
    do {
        cin >> opc;
        for (int opcion: opcionesDisponibles){
            if (to_string(opcion) == opc) { return stoi(opc); }
        } // El stoi convierte string a int
        cout << "\n--Digito una opcion incorrecta.--\n" << endl;
    } while (true);
}
double verificarCalificacion(){
    double num;
    do {
        cout << "Digite una entrada valida: ";
        cin >> num;
        if (cin.fail()){ // Pregunta si la entrada fue invalida
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora la entrada errada
            cout << "\n--Digito una opcion incorrecta.--\n" << endl;
        }
        else if (num >= 0 && num <= 10) { return num; }
        else {cout << "\n--Digito una opcion incorrecta.--\n" << endl;}
    } while (true);
}
bool verificarDisponibilidad(){
    string dispo;
    do {
        cout << "Digite una entrada valida: ";
        cin >> dispo;
        if (dispo == "Y" || dispo == "y") { return true; }
        else if (dispo == "N" || dispo == "n") { return false; }
        else { cout << "\n--Digito una opcion incorrecta.--\n" << endl; }
    } while (true);
}
void subMenuGuardarPeliculas(int &opc, vector<Peliculas> &vectPeliculas){
    string titulo, director, sinopsis, genero;
    int anio, duracion;
    double calificacion;
    bool disponible;
    cout << "\n-Digite el titulo" << endl;
    cin.ignore();
    getline(cin, titulo);
    vectPeliculas[opc - 1].setTitulo(titulo);
    cout << "\n-Digite el director" << endl;
    cin.ignore();
    getline(cin, director);
    vectPeliculas[opc - 1].setDirector(director);
    cout << "\n-Digite el anio" << endl;
    cin >> anio;
    vectPeliculas[opc - 1].setAnio(anio);
    cout << "\n-Digite la sinopsis" << endl;
    cin.ignore();
    getline(cin, sinopsis);
    vectPeliculas[opc - 1].setSinopsis(sinopsis);
    cout << "\n-Digite la duracion en minutos" << endl;
    cin >> duracion;
    vectPeliculas[opc - 1].setDuracion(duracion);
    cout << "\n-Digite el genero: " << endl;
    cin >> genero;
    vectPeliculas[opc - 1].setGenero(genero);
    cout << "\n-Digite la calificacion" << endl;
    calificacion = verificarCalificacion();
    vectPeliculas[opc - 1].setCalificacion(calificacion);
    cout << "\n-Digite la disponibilidad (Y/N)" << endl;
    disponible = verificarDisponibilidad();
    vectPeliculas[opc - 1].setDisponible(disponible);
}
void subMenuPeliculas(vector<Peliculas> &vectPeliculas) {
    for (int n = 0; n < 5; n++) {
        if (vectPeliculas[n].getTitulo() != "") {
            cout << n + 1 << ". " << vectPeliculas[n].getTitulo() << " ("
                 << vectPeliculas[n].getAnio() << ")" << endl;
        } else { cout << n + 1 << ". Otra pelicula " << n + 1 << endl; }
    }
}
void subMenuModificarPeliculas(int &opc, vector<Peliculas> &vectPeliculas, vector<int> &opcionesDisponibles){
    string titulo, director, sinopsis, genero;
    int anio, duracion, opc2;
    double calificacion;
    bool disponible;
    system("cls");
    encabezado();
    cout << "\t\tModificar pelicula" << endl;
    cout << "   " << vectPeliculas[opc - 1].getTitulo() << " ("
         << vectPeliculas[opc - 1].getAnio() << ")" << " - Director: "
         << vectPeliculas[opc - 1].getDirector() << endl;
    cout << "\n1. Titulo" << endl;
    cout << "2. Director" << endl;
    cout << "3. Anio" << endl;
    cout << "4. Sinopsis" << endl;
    cout << "5. Duracion" << endl;
    cout << "6. Genero" << endl;
    cout << "7. Calificacion" << endl;
    cout << "8. Disponible" << endl;
    cout << "\nQue desea cambiar?" << endl;
    opc2 = recibirOpcion(opcionesDisponibles={1,2,3,4,5,6,7,8});
    if (opc2 == 1) {
        cout << "\n-Digite el titulo" << endl;
        cin.ignore();
        getline(cin,titulo);
        vectPeliculas[opc - 1].setTitulo(titulo);
    } else if (opc2 == 2) {
        cout << "\n-Digite el director" << endl;
        cin.ignore();
        getline(cin, director);
        vectPeliculas[opc - 1].setDirector(director);
    } else if (opc2 == 3) {
        cout << "\n-Digite el anio" << endl;
        cin >> anio;
        vectPeliculas[opc - 1].setAnio(anio);
    } else if (opc2 == 4) {
        cout << "\n-Digite la sinopsis" << endl;
        cin.ignore();
        getline(cin, sinopsis);
        vectPeliculas[opc - 1].setSinopsis(sinopsis);
    } else if (opc2 == 5) {
        cout << "\n-Digite la duracion en minutos" << endl;
        cin >> duracion;
        vectPeliculas[opc - 1].setDuracion(duracion);
    } else if (opc2 == 6) {
        cout << "\n-Digite el genero" << endl;
        cin >> genero;
        vectPeliculas[opc - 1].setGenero(genero);
    } else if (opc2 == 7) {
        cout << "\n-Digite la calificacion" << endl;
        calificacion = verificarCalificacion();
        vectPeliculas[opc - 1].setCalificacion(calificacion);
    } else if (opc2 == 8) {
        cout << "\n-Digite la disponibilidad (Y/N)" << endl;
        disponible = verificarDisponibilidad();
        vectPeliculas[opc - 1].setDisponible(disponible);
    }
}
void menuPrincipal(vector<Peliculas> &vectPeliculas) {
    int opc, opc2;
    vector<int> opcionesDisponibles;
    do {
        system("cls");
        encabezado();
        cout << "Menu:" << endl;
        cout << "1. Mostrar todas las peliculas" << endl;
        cout << "2. Guardar una nueva pelicula" << endl;
        cout << "3. Modificar peliculas" << endl;
        cout << "4. Eliminar pelicula" << endl;
        cout << "5. Salir" << endl;
        cout << "\nQue desea realizar?" << endl;
        opc = recibirOpcion(opcionesDisponibles={1,2,3,4,5});
        opcionesDisponibles.clear();

        system("cls");
        if (opc == 1) {
            encabezado();
            cout << "\t\tPeliculas en la agenda\n" << endl;
            for (int n = 0; n < 5; n++) {
                if (vectPeliculas[n].getTitulo() != "") {
                    cout << vectPeliculas[n].toString() << endl;
                }
            }
            system("pause");
        } else if (opc == 2) {
            encabezado();
            cout << "\t\tGuardar pelicula\n" << endl;
            for (int n = 0; n < 5; n++) {
                if (vectPeliculas[n].getTitulo() == "") {
                    cout << n + 1 << ". Otra pelicula " << n + 1 << endl;
                    opcionesDisponibles.push_back(n + 1);
                }
            }
            cout << "\nDonde desea guardar la pelicula?" << endl;
            opc = recibirOpcion(opcionesDisponibles);
            subMenuGuardarPeliculas(opc, vectPeliculas);
        } else if (opc == 3) {
            encabezado();
            cout << "\t\tModificar peliculas\n" << endl;
            subMenuPeliculas(vectPeliculas);
            cout << "\nCual pelicula desea modificar?" << endl;
            opc = recibirOpcion(opcionesDisponibles={1,2,3,4,5});
            subMenuModificarPeliculas(opc, vectPeliculas, opcionesDisponibles);
        } else if (opc == 4) {
            encabezado();
            cout << "\t\tEliminar pelicula\n" << endl;
            subMenuPeliculas(vectPeliculas);
            cout << "\nCual pelicula desea eliminar?" << endl;
            opc2 = recibirOpcion(opcionesDisponibles={1,2,3,4,5});
            vectPeliculas[opc2 - 1].resetear();
        }
    } while (opc != 5);
}
int main() {
    string sipno1, sipno2;
    sipno1 = "La codicia y la discriminacion de clase amenazan la relacion simbiotica "
             "recien formada entre la acaudalada familia de Park y el indigente clan Kim.";
    sipno2 = "En Gotham City, el comediante con problemas mentales Arthur Fleck "
             "es ignorado y maltratado por la sociedad. Luego se embarca en una "
             "espiral descendente de revolucion y crimenes sangrientos. Este "
             "camino lo pone cara a cara con su alter ego: el Joker.";

    vector<Peliculas> vectPeliculas;
    vectPeliculas.push_back(Peliculas("Parasito", "Bong Joon Ho", 2019, sipno1, 132, "Drama", 8.6, true));
    vectPeliculas.push_back(Peliculas("Guason", "Todd Phillips", 2019, sipno2, 122, "Drama", 8.5, false));
    vectPeliculas.push_back(Peliculas());
    vectPeliculas.push_back(Peliculas());
    vectPeliculas.push_back(Peliculas());
    menuPrincipal(vectPeliculas);
    return 0;
}
