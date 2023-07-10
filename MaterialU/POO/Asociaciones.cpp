#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Person{
private:
    string nombre;
    int edad;
public:
    Person(){
        nombre = "";
        edad = 0;
    }
    Person(string nombre, int edad): nombre(nombre), edad(edad){

    }
    ~Person(){
        // Eliminar una variable que este almacenada en el segmento heap de la ram
    }

    virtual void print(ostream &out) = 0;
    virtual int getTipo() = 0;

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Person::nombre = nombre;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int edad) {
        Person::edad = edad;
    }

    friend ostream& operator<<(ostream &out, Person *p){
        out << endl << "Nombre: " << p->nombre << endl;
        out << "Edad: " << p->edad << endl;
        p->print(out);
        return out;
    }
};

class Paciente: public Person{
private:
    float peso, altura;
public:
    Paciente(){ peso = altura = 0; }
    Paciente(string nombre, int edad, float peso, float altura) :
        Person(nombre, edad), peso(peso), altura(altura) {}

    float getPeso() const {
        return peso;
    }

    void setPeso(float peso) {
        Paciente::peso = peso;
    }

    float getAltura() const {
        return altura;
    }

    void setAltura(float altura) {
        Paciente::altura = altura;
    }

    float imc(){
        return peso / (altura*altura);
    }

    int getTipo() override{
        return 0;
    }

    void print(ostream &out) override{
        out << "Peso: " << peso << endl;
        out << "Altura: " << altura << endl;
    }

};

class Especialidad{
    string nombre;
    int anio;
public:
    Especialidad(){
        this->nombre = "";
        this->anio = 0;
    }
    Especialidad(string nombre, int anio){
        this->nombre = nombre;
        this->anio = anio;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    friend ostream& operator<<(ostream &out, Especialidad e){
        out << "Nombre especialidad:" << e.nombre << endl;
        out << "Anio especialidad:" << e.anio << endl;
    }
};

class Medico: public Person{
private:
    Especialidad especialidad;// composición
public:
    Medico(){
        especialidad = Especialidad();
    }
    Medico(string nombre, int edad, string nombreEspecialidad, int anioEspecialidad) : Person(nombre, edad) {
        especialidad = Especialidad(nombreEspecialidad, anioEspecialidad);
    }

    Especialidad& getEspecialidad(){
        return especialidad;
    }

    void setEspecialidad(const Especialidad &especialidad) {
        Medico::especialidad = especialidad;
    }
    int getTipo() override{
        return 1;
    }
    void print(ostream &out) override{
        out << "Especialidad: " << endl << especialidad << endl;
    }
};

class IPS{
    string nombre;
    vector<Person *> usuarios; // agregación
public:
    IPS(){
        nombre = "";
        usuarios = {};
    }
    IPS(string nombre){
        this->nombre = nombre;
        usuarios = {};
    }
    IPS(string nombre, vector<Person *> usuarios){
        this->nombre = nombre;
        this->usuarios = usuarios; // agregación
    }
    friend ostream& operator<<(ostream &out, IPS i){
        out << "Nombre IPS: " << i.nombre << endl;
        if(!i.usuarios.empty()){
            for(Person *p: i.usuarios){
                cout << p << endl;
            }
        }else{
            cout << "No hay usuarios para mostrar." << endl;
        }

    }
    void setUsuarios(vector<Person*> lista){
        usuarios = lista;
    }
    vector<Person *> getUsuarios(){
        return usuarios;
    }
    void agregarUsuario(Person *p){
        usuarios.push_back(p);
    }
    void borrarUsuario(int posicion){
        usuarios.erase(usuarios.begin()+posicion);
    }
};

int main() {
    vector<Person *> listado_personas = {};
    listado_personas.push_back(new Paciente("Victor Jara", 32, 80, 180));
    listado_personas.push_back(new Paciente("Mercedes Sosa", 56, 100, 160));
    listado_personas.push_back(new Medico("Patch Adams", 45, "Internista", 1976));
    listado_personas.emplace_back("Juan", 20, "General", 2003);
    
    for(Person* p: listado_personas){
        if (p->getTipo() == 1){
            cout << p << endl;
        }
    }
    /*IPS ips("Nueva EPS");
    ips.setUsuarios(listado_personas);

    ips.agregarUsuario(new Paciente("Ali Primera", 67, 100, 160));

    int i = 1;
    int opc = 0;
    cout << "Cual de los siguientes usuarios desea eliminar?: " << endl;
    for(Person *p: ips.getUsuarios()){ // for each
        cout << i << ") "<<p->getNombre() << endl ;
        i++;
    }
    cout << "Ingrese el número del usuario: ";
    cin >> opc;

    ips.borrarUsuario(opc - 1);

    //Medico* m = (Medico *)ips.getUsuarios()[2]; //<-- error
    Medico* m = (Medico *)ips.getUsuarios()[1];
    m->getEspecialidad().setNombre("Pediatra");
    //m->setNombre("Roger");



    cout << ips;*/

    return 0;
}
