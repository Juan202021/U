#include "list.h"
#include "Punto.h"
#include <vector>
using namespace std;

void encabezado(){
    cout << "\n\n\tPROGRAMA PARA SUMAR ENTEROS GRANDES.\n\n" << endl;
    cout << "====================================================" << endl;
}

void mostrar(vector<List<int>>& v){
    if (!v.empty()){
        for(int i=0; i<v.size(); i++){
            cout << "(" << i+1 << ") -> ";
            v[i].printReverse();
            cout << endl;
        }
    } else {
        cout << "\n\nNo hay ninguno por el momento.\n" << endl;
    }
    cout << endl;
}

vector<string> generarOpciones(vector<List<int>>& v) {
    vector<string> opciones;
    for (int i = 0; i < v.size(); i++) {
        opciones.push_back(to_string(i+1));
    }
    return opciones;
}

int verificarOpcion(vector<string>& opciones, string& opcion){
    for (string& opc: opciones){
        if (opc==opcion){
            return stoi(opc)-1;
        }
    }
    return -1;
}

void error(){
    cout << "\n\n\t- Error! digito una opcion invalida. -\n" << endl;
}

void menu(){
    system("cls");
    encabezado();
    vector<List<int>> listas;
    string opc;
    do {
        cout << "\n\t\tMenu:" << endl;
        cout << "1. Mostrar todos los numeros grandes." << endl;
        cout << "2. Crear un numero grande." << endl;
        cout << "3. Sumar dos numeros grandes." << endl;
        cout << "4. Multiplicar dos numeros grandes." << endl;
        cout << "5. Cargar numeros grandes desde un archivo." << endl;
        cout << "6. Salir.\n" << endl;
        cout << "Que desea realizar?" << endl;
        cout << ">> ";
        cin >> opc;
        if (opc == "1"){
            system("cls");
            encabezado();
            cout << "\n\t- Mostrar todos los numeros grandes. -\n" << endl;
            mostrar(listas);
            system("pause");
        }
        else if (opc == "2"){
            system("cls");
            encabezado();
            cout << "\n\t- Crear un numero grande. -\n" << endl;
            List<int> n;
            n.crear_ngrande();
            if (n.size() != 0) listas.push_back(n);
            cout << endl;
            system("pause");
        }
        else if (opc == "3"){
            system("cls");
            encabezado();
            string n1,n2;
            int op1,op2;
            cout << "\n\t- Sumar dos numeros grandes. -\n" << endl;
            mostrar(listas);
            if (listas.size()<2) {
                cout << "Numeros insuficientes para realizar la operacion" << endl;
            }
            else if (listas.size()>=2){
                cout << "Digite la posicion del primer numero que desea sumar: ";
                cin >> n1;
                cout << "Digite la posicion del segundo numero que desea sumar: ";
                cin >> n2;

                vector<string> opciones = generarOpciones(listas);
                op1 = verificarOpcion(opciones,n1);
                op2 = verificarOpcion(opciones,n2);

                if (op1 != -1 && op2 != -1){
                    List<int> res = listas[stoi(n1)-1] + listas[stoi(n2)-1];
                    cout << " --> ";
                    listas[stoi(n1)-1].printReverse();
                    cout << " +  ";
                    listas[stoi(n2)-1].printReverse();
                    cout << " =  ";
                    res.printReverse();
                    listas.push_back(res);
                } else {
                    error();
                }
            }

            cout << "\n" << endl;
            system("pause");
        }
        else if (opc == "4"){
            system("cls");
            encabezado();
            string n1,n2;
            int op1,op2;
            cout << "\n\t- Multiplicar dos numeros grandes. -\n" << endl;
            mostrar(listas);
            if (listas.size()<2) cout << "Numeros insuficientes para realizar la operacion" << endl;
            else if (listas.size()>=2){
                cout << "Digite la posicion del primer numero que desea multiplicar: ";
                cin >> n1;
                cout << "Digite la posicion del segundo numero que desea multiplicar: ";
                cin >> n2;

                vector<string> opciones = generarOpciones(listas);
                op1 = verificarOpcion(opciones,n1);
                op2 = verificarOpcion(opciones,n2);

                if (op1 != -1 && op2 != -1){
                    List<int> res = listas[stoi(n1)-1] * listas[stoi(n2)-1];
                    cout << " --> ";
                    listas[stoi(n1)-1].printReverse();
                    cout << " *  ";
                    listas[stoi(n2)-1].printReverse();
                    cout << " =  ";
                    res.printReverse();
                    listas.push_back(res);
                } else {
                    error();
                }
            }
            cout << "\n" << endl;
            system("pause");
        }
        else if (opc == "5"){
            system("cls");
            encabezado();
            cout << "\n\t- Cargar numeros grandes desde un archivo. -\n" << endl;
            List<int> listArchivo;
            listArchivo.archivo(listas);
            cout << endl;
            listArchivo.printReverse();

            cout << "\n" << endl;
            system("pause");
        }
        else if (opc == "6"){
            cout << "\n- Hasta pronto. -\n" << endl;
            cout << endl;
            system("pause");
        }
        else {
            error();
            system("pause");
        }
    } while (opc != "6");
}

int main()
{
    menu();
    system("pause");
    return 0;
}
