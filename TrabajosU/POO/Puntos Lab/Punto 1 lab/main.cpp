#include <iostream>
#include <iomanip> // Libreria para el setiosflags() y setw()

using namespace std;

// Prototipos de las funciones
void imprimir(int, int);
void imprimir_caracter1(int, int);
void imprimir_caracter2(int, int);

int main() {
    int tipo, tam;

    cout << "- Patrones:" << endl;
    cout << "(1):" << endl;
    cout << "   *" << endl;
    cout << "   **" << endl;
    cout << "   ***" << endl;
    cout << "(2):" << endl;
    cout << "   ***" << endl;
    cout << "   **" << endl;
    cout << "   *" << endl;
    cout << "(3):" << endl;
    cout << "   ***" << endl;
    cout << "    **" << endl;
    cout << "     *" << endl;
    cout << "(4):" << endl;
    cout << "     *" << endl;
    cout << "    **" << endl;
    cout << "   ***" << endl;

    cout << "Digite el tipo de patron que desea: ";
    cin >> tipo;
    cout << "Digite el tamanio de patron que desea (1 - 9): ";
    cin >> tam;
    imprimir(tipo, tam);
    return 0;
}

void imprimir(int t, int tamanio) {
    if (tamanio >= 1 && tamanio <=9){
        if (t == 1) {
            cout << endl;
            imprimir_caracter1(tamanio, 1);
        } else if (t == 2) {
            cout << endl;
            imprimir_caracter2(tamanio,1);
        } else if (t == 3) {
            cout << endl;
            imprimir_caracter2(tamanio,2);
        } else if (t == 4) {
            cout << endl;
            imprimir_caracter1(tamanio, 2);
        } else {
            cout << "Digito un tipo de patron invalido." << endl;
        }
    }
    else {
        cout << "Digito un tamanio invalido." << endl;
    }

}

void imprimir_caracter1(int num, int pos) {
    string car = "";
    if (pos == 1) {
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= i; j++) {
                car += "*";
            }
            cout << setiosflags(ios::left) // El setiosflags sirve para alinear el texto
                 << setw(num) << car << endl; // El setw sirve para ponerle un tamaño de espacio en el que se va a imprimir por pantalla
            car = "";
        }
    } else {
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= i; j++) {
                car += "*";
            }
            cout << setiosflags(ios::right)
                 << setw(num) << car << endl;
            car = "";
        }
    }

}

void imprimir_caracter2(int num, int pos) {
    string car = "";
    if (pos == 1) {
        for (int i = num; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                car += "*";
            }
            cout << setiosflags(ios::left)
                 << setw(num) << car << endl;
            car = "";
        }
    } else {
        for (int i = num; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                car += "*";
            }
            cout << setiosflags(ios::right)
                 << setw(num) << car << endl;
            car = "";
        }
    }
}