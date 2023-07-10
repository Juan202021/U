#include <iostream>
#include <vector>

using namespace std;

class Usuario{
protected:
    string nombre;
    int edad;
    string cedula;
public:
    Usuario(string nombre, int edad, string cedula){
        this->nombre=nombre;
        this->edad=edad;
        this->cedula=cedula;
    }
    virtual void print() = 0;
};

class DenunciaC{
protected:
    Usuario* denunciante;
    Usuario* denunciado;
    string fecha;
    string descripcion;
    string estado;
public:
    DenunciaC(Usuario* denunciante, Usuario* denunciado, string fecha, string descripcion): estado("Sin revisar"){}

    Usuario* getDenunciante() const { return denunciante; }
    void setDenunciante(Usuario *denunciante) { this -> denunciante = denunciante; }
    Usuario* getDenunciado() const { return denunciado; }
    void setDenunciado(Usuario *denunciado) { this -> denunciado = denunciado; }
    string getFecha() const { return fecha; }
    void setFecha(string fecha) { DenunciaC::fecha = fecha; }
    string getDescripcion() const { return descripcion; }
    void setDescripcion(string descripcion) { this -> descripcion = descripcion; }
    string getEstado() const { return estado; }
    void setEstado(string estado) { this -> estado = estado; }
};

class Denuncia{
public:
    virtual void denunciar(Usuario*,string,string) = 0;
};


class Estudiante: public Usuario, public Denuncia{
protected:
    string carrera;
    int semestre;
public:
    Estudiante(string carrera, int semestre, string nombre, int edad, string numeroCedula):
                carrera(carrera), semestre(semestre), Usuario(nombre, edad, numeroCedula){}

    string getCarrera() { return carrera; }
    void setCarrera(string carrera) { this -> carrera = carrera; }
    int getSemestre() { return semestre; }
    void setSemestre(int semestre) { this -> semestre = semestre; }
    void denunciar(Usuario* denunciado, string fecha, string descripcion) override {
        DenunciaC(this, denunciado, fecha, descripcion);
    }
    void print() override {}
};

class Profesor: public Usuario, public Denuncia{
protected:
    string departamento;
    string categoria;
public:
    Profesor(string departamento, string categiria, string nombre, int edad, string numeroCedula) :
            departamento(departamento), categoria(categiria), Usuario(nombre, edad, numeroCedula) {}
    void denunciar(Usuario* denunciado, string fecha, string descripcion) override{
        DenunciaC(this, denunciado, fecha, descripcion);
    }
    void print() override {}

    string getDepartamento() const { return departamento; }
    void setDepartamento(string departamento) { this -> departamento = departamento; }
    string getCategoria() const { return categoria; }
    void setCategoria(string categoria) { this -> categoria = categoria; }
};

class Admin: public Usuario{
public:
    Admin(string nombre, int edad, string cedula): Usuario(nombre,edad,cedula){}
    void revisarDenuncia(DenunciaC denuncia){
        denuncia.setEstado("Revisado");
    }
    void print() override {}
};

void encabezado() {
    cout << "##########################################" << endl;
    cout << "####### Denuncias De Acoso Sexual ########" << endl;
    cout << "##########################################\n" << endl;
}
int main(){
    vector<Usuario*> usuarios;
    int opc, opc2;
    do{
        system("cls");
        encabezado();
        cout << "\n-Menu De Opciones\n" << endl;
        cout << "1. Registrar denuncia" << endl;
        cout << "2. Ver denuncias" << endl;
        cout << "3. Moderar denuncias" << endl;
        cout << "4. Administrar usuarios" << endl;
        cout << "5. Generar reportes" << endl;
        cout << "6. Salir del sistemas\n" << endl;
        cout << "Ingrese el numero correspondiente a la opcion deseada:" << endl;
        cin >> opc;

        system("cls");
        if (opc == 1){
            encabezado();
            cout <<"\tCrear Denuncia"<<endl;

        }

        else if (opc == 2){
            encabezado();
            cout <<"\tMostrar Denuncias"<<endl;

        }

        else if (opc == 3){
            encabezado();
            cout << "Moderando denuncias";
            cout << "Cual denuncia desea moderar";
            cout << "1.p\n2.p\n3.p\n4.p\n5.p"<<endl;
            cin >> opc2;
            if(opc2==1){}
            else if(opc2==2){}
            else if(opc2==3){}
            else if(opc2==4){}
            else if(opc2==5){}
            else {cout << "--Digito una opcion incorrecta.--"<<endl;}

        }
        else if (opc == 4){
            encabezado();
            cout << "Administrar usuario";
            cout << "Cual usuaro desea administrar ";
            cout << "1.p\n2.p\n3.p\n4.p\n5.p"<<endl;
            cin >> opc2;
            if(opc2==1){}
            else if(opc2==2){}
            else if(opc2==3){}
            else if(opc2==4){}
            else if(opc2==5){}
            else {cout << "--Digito una opcion incorrecta.--"<<endl;}

        }
        else if (opc == 5){
            encabezado();
            cout << "Generar reportes";

        }
        else if (opc == 6){ cout << "--Hasta pronto.--"<<endl; }
        else { cout << "--Digito una opcion incorrecta.--"<<endl; }
    } while (opc!=6);

    return 0;}
