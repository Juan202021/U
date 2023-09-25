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

class Medico: public Person{
private:
    string especialidad;
public:
    Medico(){ especialidad = ""; }
    Medico(string nombre, int edad, string especialidad) :
            Person(nombre, edad), especialidad(especialidad) {}

    string getEspecialidad() const {
        return especialidad;
    }

    void setEspecialidad(const string &especialidad) {
        Medico::especialidad = especialidad;
    }
    int getTipo() override{
        return 1;
    }
    void print(ostream &out) override{
        out << "Especialidad: " << especialidad << endl;
    }
};

int main() {
    vector<Person *> listado_personas = {};

    Paciente paciente = Paciente("Castro", 18, 78, 1.80);
    listado_personas.push_back(&paciente);
    bool flag = true;
    while(flag){
        int opc = 0;
        cout << "Menú:\n1) Ingresar pacientes\n2) Ingresar medicos\n3) Mostrar listado\n4) Especialidad\n5) imc\n 6) Salir" << endl;
        cin >> opc;
        if(opc == 1){
            string nombre;
            int edad;
            float peso, altura;
            cout << "Ingresar pacientes"<< endl ;
            cout << "Nombre: ";
            cin >>nombre;
            cout << "Edad: ";
            cin >>edad;
            cout << "Peso: ";
            cin >>peso;
            cout << "Altura: ";
            cin >>altura;
            Paciente *p = new Paciente(nombre, edad, peso, altura);
            listado_personas.push_back(p);
        }
        else if(opc == 2){
            cout << "Ingresar medicos" << endl;
            string nombre, especialidad;
            int edad;
            cout << "Ingresar pacientes"<< endl ;
            cout << "Nombre: ";
            cin >>nombre;
            cout << "Edad: ";
            cin >>edad;
            cout << "Especialidad: ";
            cin >>especialidad;
            listado_personas.push_back(new Medico(nombre, edad, especialidad));
        }
        else if(opc == 3){
            cout << "Mostrar el listado" << endl;
            for(Person *p: listado_personas){
                cout << p;
            }
        }else if(opc == 4){
            cout << "especialidad de los medicos" << endl;
            for(Person *p: listado_personas){
                if(p->getTipo() == 1){
                    Medico* m = (Medico*)p;
                    cout << m->getEspecialidad() << endl;
                }
            }
        }else if(opc == 5){
            cout << "IMC de los pacientes" << endl;
        }else if(opc == 6){
            flag = false;
        }else{
            cout << "Error" << endl;
            assert(false);
        }
    }

    return 0;
}
