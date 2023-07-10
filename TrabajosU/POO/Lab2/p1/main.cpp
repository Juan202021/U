#include <iostream>

using namespace std;

class Estudiante{
    string nombre, documento;
    int tipo_documento;
    string asignatura;
    float nota_corte1, nota_corte2, nota_corte3;
public:
    Estudiante(){
        nombre = "";
        documento = "";
        tipo_documento = 0;
        asignatura = "";
        nota_corte1 = 0.0;
        nota_corte2 = 0.0;
        nota_corte3 = 0.0;
    }

    Estudiante(string nombre, string documento, int tipo_documento, string asignatura, float nota_corte1, float nota_corte2, float nota_corte3){
        this -> nombre = nombre;
        this -> documento = documento;
        this -> tipo_documento = tipo_documento;
        this -> asignatura = asignatura;
        this -> nota_corte1 = nota_corte1;
        this -> nota_corte2 = nota_corte2;
        this -> nota_corte3 = nota_corte3;
    }

    float obtenerPromedio(){
        float prom;
        prom = nota_corte1*0.3 + nota_corte2*0.3 + nota_corte3*0.4;
        return prom;
    }

    string siAprobo(){
        if (obtenerPromedio() >= 3.0){
            return "Aprobo";
        } else {
            return "No Aprobo";
        }
    }

    void resetear(){
        nombre = "";
        documento = "";
        tipo_documento = 0;
        asignatura = "";
        nota_corte1 = 0.0;
        nota_corte2 = 0.0;
        nota_corte3 = 0.0;
    }

    string getNombre(){
        return nombre;
    }
    void setNombre(string nombre){
        this -> nombre = nombre;
    }

    string getDocumento(){
        return documento;
    }
    void setDocumento(string documento){
        this -> documento = documento;
    }

    int getTipoDocumento(){
        return tipo_documento;
    }
    void setTipoDocumento(int tipo_documento){
        this -> tipo_documento = tipo_documento;
    }

    string getAsignatura(){
        return asignatura;
    }
    void setAsignatura(string asignatura){
        this -> asignatura = asignatura;
    }

    float getNotaCorte1(){
        return nota_corte1;
    }
    void setNotaCorte1(float nota_corte1){
        this -> nota_corte1 = nota_corte1;
    }

    float getNotaCorte2(){
        return nota_corte2;
    }
    void setNotaCorte2(float nota_corte2){
        this -> nota_corte2 = nota_corte2;
    }

    float getNotaCorte3(){
        return nota_corte3;
    }
    void setNotaCorte3(float nota_corte3){
        this -> nota_corte3 = nota_corte3;
    }

    string toString(){
        string info;
        info = nombre + " " + documento + " " + to_string(tipo_documento) + " " + asignatura + " " + to_string(nota_corte1) + " " + to_string(nota_corte2) + " " + to_string(nota_corte3);
        return info;
    }

};
int menuEstudiante(){
    int obj;
    cout << "1. Estudiante (1)" << endl;
    cout << "2. Estudiante (2)" << endl;
    cout << "3. Estudiante (3)" << endl;
    cout << "\nDigite el estudiante: ";
    cin >> obj;
    return obj;
}

int menuModificarEstudiante(){
    int opc;
    cout << "1. Nombre" << endl;
    cout << "2. Documento" << endl;
    cout << "3. Tipo de documento" << endl;
    cout << "4. Asignatura" << endl;
    cout << "5. Nota corte 1" << endl;
    cout << "6. Nota corte 2" << endl;
    cout << "7. Nota corte 3" << endl;
    cout << "\nDigite el campo que desea modificarar: ";
    cin >> opc;
    return opc;
}

void menu(Estudiante e1, Estudiante e2, Estudiante e3){
    int res, obj, opc, tipo_doc;
    string nom, doc, asignatura;
    float notaC1, notaC2, notaC3;
    do{
        cout << "\nMenu:" << endl;
        cout << "1. Crear un estudiante" << endl;
        cout << "2. Modificar datos de estudiante" << endl;
        cout << "3. Mostrar datos estudiante" << endl;
        cout << "4. Eliminar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "\n¿Que desea realizar?" << endl;
        cin >> res;
        if(res == 1){
            obj = menuEstudiante();
            if (obj == 1){
                cout << "Digite el nombre: ";
                cin >> nom;
                e1.setNombre(nom);
                cout << "Digite el documento: ";
                cin >> doc;
                e1.setDocumento(doc);
                cout << "Digite el tipo de documento: ";
                cin >> tipo_doc;
                e1.setTipoDocumento(tipo_doc);
                cout << "Digite el asignatura: ";
                cin >> asignatura;
                e1.setAsignatura(asignatura);
                cout << "Digite la nota del corte 1: ";
                cin >> notaC1;
                e1.setNotaCorte1(notaC1);
                cout << "Digite la nota del corte 2: ";
                cin >> notaC2;
                e1.setNotaCorte2(notaC2);
                cout << "Digite la nota del corte 3: ";
                cin >> notaC3;
                e1.setNotaCorte3(notaC3);
            }
            else if (obj == 2){
                cout << "Digite el nombre: ";
                cin >> nom;
                e2.setNombre(nom);
                cout << "Digite el documento: ";
                cin >> doc;
                e2.setDocumento(doc);
                cout << "Digite el tipo de documento: ";
                cin >> tipo_doc;
                e2.setTipoDocumento(tipo_doc);
                cout << "Digite el asignatura: ";
                cin >> asignatura;
                e2.setAsignatura(asignatura);
                cout << "Digite la nota del corte 1: ";
                cin >> notaC1;
                e2.setNotaCorte1(notaC1);
                cout << "Digite la nota del corte 2: ";
                cin >> notaC2;
                e2.setNotaCorte2(notaC2);
                cout << "Digite la nota del corte 3: ";
                cin >> notaC3;
                e2.setNotaCorte3(notaC3);
            }
            else if (obj == 3){
                cout << "Digite el nombre: ";
                cin >> nom;
                e3.setNombre(nom);
                cout << "Digite el documento: ";
                cin >> doc;
                e3.setDocumento(doc);
                cout << "Digite el tipo de documento: ";
                cin >> tipo_doc;
                e3.setTipoDocumento(tipo_doc);
                cout << "Digite el asignatura: ";
                cin >> asignatura;
                e3.setAsignatura(asignatura);
                cout << "Digite la nota del corte 1: ";
                cin >> notaC1;
                e3.setNotaCorte1(notaC1);
                cout << "Digite la nota del corte 2: ";
                cin >> notaC2;
                e3.setNotaCorte2(notaC2);
                cout << "Digite la nota del corte 3: ";
                cin >> notaC3;
                e3.setNotaCorte3(notaC3);
            }
            else {
                cout << "--Digito una opcion incorrecta.--" << endl;
            }

        }
        else if (res == 2){
            obj = menuEstudiante();
            if (obj == 1){
                opc = menuModificarEstudiante();
                if(opc == 1){
                    cout << "Digite el nombre del estudiante: ";
                    cin >> nom;
                    e1.setNombre(nom);
                }
                else if(opc == 2){
                    cout << "Digite el documento del estudiante: ";
                    cin >> doc;
                    e1.setDocumento(doc);
                }
                else if(opc == 3){
                    cout << "Digite el tipo de documento del estudiante: ";
                    cin >> tipo_doc;
                    e1.setTipoDocumento(tipo_doc);
                }
                else if(opc == 4){
                    cout << "Digite la asignatura del estudiante: ";
                    cin >> asignatura;
                    e1.setAsignatura(asignatura);
                }
                else if(opc == 5){
                    cout << "Digite la nota del corte 1 del estudiante: ";
                    cin >> notaC1;
                    e1.setNotaCorte1(notaC1);
                }
                else if(opc == 6){
                    cout << "Digite la nota del corte 2 del estudiante: ";
                    cin >> notaC2;
                    e1.setNotaCorte2(notaC2);
                }
                else if(opc == 7){
                    cout << "Digite la nota del corte 3 del estudiante: ";
                    cin >> notaC3;
                    e1.setNotaCorte3(notaC3);
                }
                else {
                    cout << "--Digito una opcion incorrecta.--" << endl;
                }
            }
            else if(obj == 2){
                opc = menuModificarEstudiante();
                if(opc == 1){
                    cout << "Digite el nombre del estudiante: ";
                    cin >> nom;
                    e2.setNombre(nom);
                }
                else if(opc == 2){
                    cout << "Digite el documento del estudiante: ";
                    cin >> doc;
                    e2.setDocumento(doc);
                }
                else if(opc == 3){
                    cout << "Digite el tipo de documento del estudiante: ";
                    cin >> tipo_doc;
                    e2.setTipoDocumento(tipo_doc);
                }
                else if(opc == 4){
                    cout << "Digite la asignatura del estudiante: ";
                    cin >> asignatura;
                    e2.setAsignatura(asignatura);
                }
                else if(opc == 5){
                    cout << "Digite la nota del corte 1 del estudiante: ";
                    cin >> notaC1;
                    e2.setNotaCorte1(notaC1);
                }
                else if(opc == 6){
                    cout << "Digite la nota del corte 2 del estudiante: ";
                    cin >> notaC2;
                    e2.setNotaCorte2(notaC2);
                }
                else if(opc == 7){
                    cout << "Digite la nota del corte 3 del estudiante: ";
                    cin >> notaC3;
                    e2.setNotaCorte3(notaC3);
                }
                else {
                    cout << "--Digito una opcion incorrecta.--" << endl;
                }
            }
            else if(obj == 3){
                opc = menuModificarEstudiante();
                if(opc == 1){
                    cout << "Digite el nombre del estudiante: ";
                    cin >> nom;
                    e3.setNombre(nom);
                }
                else if(opc == 2){
                    cout << "Digite el documento del estudiante: ";
                    cin >> doc;
                    e3.setDocumento(doc);
                }
                else if(opc == 3){
                    cout << "Digite el tipo de documento del estudiante: ";
                    cin >> tipo_doc;
                    e3.setTipoDocumento(tipo_doc);
                }
                else if(opc == 4){
                    cout << "Digite la asignatura del estudiante: ";
                    cin >> asignatura;
                    e3.setAsignatura(asignatura);
                }
                else if(opc == 5){
                    cout << "Digite la nota del corte 1 del estudiante: ";
                    cin >> notaC1;
                    e3.setNotaCorte1(notaC1);
                }
                else if(opc == 6){
                    cout << "Digite la nota del corte 2 del estudiante: ";
                    cin >> notaC2;
                    e3.setNotaCorte2(notaC2);
                }
                else if(opc == 7){
                    cout << "Digite la nota del corte 3 del estudiante: ";
                    cin >> notaC3;
                    e3.setNotaCorte3(notaC3);
                }
                else {
                    cout << "--Digito una opcion incorrecta.--" << endl;
                }
            }
        }
        else if (res == 3){
            obj = menuEstudiante();
            if (obj == 1){
                cout << e1.toString() << endl;
            }
            else if(obj == 2){
                cout << e2.toString() << endl;
            }
            else if(obj == 3){
                cout << e3.toString() << endl;
            }
            else {
                cout << "--Digito una opcion incorrecta.--" << endl;
            }
        }
        else if (res == 4){
            obj = menuEstudiante();
            if (obj == 1){
                e1.resetear();
            }
            else if(obj == 2){
                e2.resetear();
            }
            else if(obj == 3){
                e3.resetear();
            }
            else {
                cout << "--Digito una opcion incorrecta.--" << endl;
            }
        }
        else if (res != 5){
            cout << "--Digito una opcion incorrecta.--" << endl;
        }
    } while (res != 5);
}

int main() {
    Estudiante e1 = Estudiante("Alex", "160004903", 1, "POO", 5.0, 4.5, 4.0);
    Estudiante e2 = Estudiante("Juan", "1006799568", 1, "Calculo", 5.0, 5.0, 5.0);
    Estudiante e3 = Estudiante();

    menu(e1,e2,e3);

    return 0;
}
