//
// Created by Juan on 10/13/2023.
//
#ifndef L4_LABERINTO_CPP
#define L4_LABERINTO_CPP
#include "Laberinto.h"

Laberinto::Laberinto(){
    laberinto = {};
}
Laberinto::Laberinto(vector<vector<char>>& laberinto, Stack<Punto>& visitados, Stack<Punto>& alternativas):
        visitados(visitados), alternativas(alternativas), laberinto(laberinto){}

bool Laberinto::cumpleTam(){
    auto tam = laberinto[0].size();

    for (const auto& fil : laberinto){
        if (fil.size() != tam) return false;
    }
    return true;
}
void Laberinto::cargar(){
    string docu,linea,fila;
    int i=0;
    cout<<"Ingrese el nombre del archivo sin ninguna extension, solo el nombre del archivo: ";
    cin>>docu;
    // Abrir el archivo
    ifstream archivo("C:\\Users\\Juan\\JAristizabal\\U\\TrabajosU\\Estructuras de datos\\L4\\" + docu + ".txt");
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            fila = linea;
            laberinto.emplace_back();
            for (int j=0; j<linea.size(); j++){
                laberinto[i].push_back(linea[j]);
            }
            i++;
        }
        archivo.close();
        if (!cumpleTam()){
            cout << "\n\t- El laberinto no cumple con las condiciones minimas. -\n" << endl;
            laberinto.clear();
        }
    } else {
        cout << "No se pudo abrir el archivo";
    }
}
void Laberinto::print(const Punto& currentSpot = Punto()){
    //system("cls");
    cout << endl;
    for (int i=0; i<laberinto.size(); i++){
        for (int j=0; j<laberinto[0].size(); j++){
            if (laberinto[i][j] == '#'){
                //cout << "\x1b[33m" << char(219) << "\x1b[0m"; paredes amarillas
                cout << "\x1b[1;35m" << char(219) << "\x1b[0m";
            }
            else if (i == currentSpot.getFil() && j == currentSpot.getCol()){
                //cout << "\x1b[5;35;46m" << char(254) << "\x1b[0m";
                cout << "\x1b[5;34;46m" << char(254) << "\x1b[0m";
            }
            else if (laberinto[i][j] == 'O'){
                //cout << "\x1b[36m" << char(219) << "\x1b[0m"; cian
                cout << "\x1b[1;36m" << char(219) << "\x1b[0m";
            }
            else if (laberinto[i][j] == '-'){
                cout << "\x1b[31m" << char(219) << "\x1b[0m";
            }
            else {
                //cout << "\x1b[34m" << char(219) << "\x1b[0m"; espacios azul
                cout << "\x1b[1;33m" << char(219) << "\x1b[0m";

            }

        }
        cout << endl;
    }
    cout << endl;
}
bool Laberinto::esSalida(const Punto& currentSpot){
    return (currentSpot.getFil() == 0
        || currentSpot.getFil() == laberinto.size() - 1
        || currentSpot.getCol() == 0
        || currentSpot.getCol() == laberinto[0].size() - 1);
}
bool Laberinto::posValida(int fila, int columna){
    return (fila >= 0 && fila < laberinto.size() && columna >= 0 && columna < laberinto[0].size() && laberinto[fila][columna] == ' ');
}
bool Laberinto::noPosAnterior(int fila, int columna){
    return ((fila != visitados.top().getFil()) || (columna != visitados.top().getCol()));
}
void Laberinto::buscarAlternativas(const Punto& currentSpot, int& cont){
    cont = 0;
    if (posValida(currentSpot.getFil() + 1, currentSpot.getCol())
        && noPosAnterior(currentSpot.getFil() + 1,currentSpot.getCol())){
        alternativas.push(Punto(currentSpot.getFil() + 1,currentSpot.getCol()));
        cont ++;
    }
    if (posValida(currentSpot.getFil(), currentSpot.getCol() - 1)
        && noPosAnterior(currentSpot.getFil(),currentSpot.getCol() - 1)){
        alternativas.push(Punto(currentSpot.getFil(),currentSpot.getCol() - 1));
        cont ++;
    }
    if (posValida(currentSpot.getFil(), currentSpot.getCol() + 1)
        && noPosAnterior(currentSpot.getFil(),currentSpot.getCol() + 1)){
        alternativas.push(Punto(currentSpot.getFil(),currentSpot.getCol() + 1));
        cont ++;
    }
    if (posValida(currentSpot.getFil() - 1, currentSpot.getCol())
        && noPosAnterior(currentSpot.getFil() - 1,currentSpot.getCol())){
        alternativas.push(Punto(currentSpot.getFil() - 1,currentSpot.getCol()));
        cont ++;
    }
}
bool Laberinto::continuar(){
    string res;
    do {
        cout << "Desea continuar? (S/N): ";
        cin >> res;
    } while (res != "S" && res != "s" && res != "N" && res != "n");
    if (res == "S" || res == "s") return true;
    return false;
}
void Laberinto::iniciar(const Punto& entrada){
    if (laberinto.empty()) return;
    Punto currentSpot = entrada;
    bool flag = true;
    int cont = 0;
    laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
    visitados.push(currentSpot);
    buscarAlternativas(currentSpot,cont);
    print(currentSpot);
    flag = continuar();
    while(flag){
        if (esSalida(currentSpot)){
            cout << "\n\tYOU WIN!\n" << endl;
            break;
        }
        else if (alternativas.size() == 0 && visitados.size() == 1){
            cout << "\n\tYOU'RE STUCK!\n" << endl;
            break;
        }
        else if (cont == 1){
            currentSpot = alternativas.top();
            alternativas.pop();
            visitados.push(currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            buscarAlternativas(currentSpot,cont);
        }
        else if (cont == 0 && visitados.size() > 1){
            visitados.pop();
            currentSpot = visitados.top();
            if (currentSpot.getFil() == -1 && currentSpot.getCol() == -1){
                visitados.pop();
                currentSpot = visitados.top();
                cont++;
            }
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
        }
        else if (cont > 1){
            currentSpot = alternativas.top();
            alternativas.pop();
            visitados.push(Punto());
            visitados.push(currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            buscarAlternativas(currentSpot,cont);
        }
        print(currentSpot);
        cout << "Contador: " << cont << endl;
        cout << "Current: " << currentSpot << endl;
        cout << "Visitados: " << endl;
        visitados.print();
        cout << "Alternativas: " << endl;
        alternativas.print();
        //flag = continuar();
    }
}
#endif