//
// Created by Juan on 10/13/2023.
//

#include "Laberinto.h"
#include <fstream>

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
void Laberinto::print(){
    for (int i=0; i<laberinto.size(); i++){
        for (int j=0; j<laberinto[0].size(); j++){
            cout << laberinto[i][j];
        }
        cout << endl;
    }
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
void Laberinto::iniciar(const Punto& entrada){
    if (laberinto.empty()) return;
    Punto currentSpot = entrada;
    bool flag = true;
    int cont = 0;
    laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
    visitados.push(currentSpot);
    buscarAlternativas(currentSpot,cont);
    print();
    while(flag){
        if (esSalida(currentSpot)){
            cout << "\n\tYOU WIN!\n" << endl;
            break;
        }
        else if (cont == 0 && visitados.size() == 1){
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
            }
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
            cont++;
            /*currentSpot = alternativas.top();
            alternativas.pop();
            visitados.push(currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            buscarAlternativas(currentSpot,cont);*/
        }
        else if (cont > 1){
            currentSpot = alternativas.top();
            alternativas.pop();
            visitados.push(Punto());
            visitados.push(currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            buscarAlternativas(currentSpot,cont);
        }
        print();
        cout << "Contador: " << cont << endl;
        cout << "Current: " << currentSpot << endl;
        cout << "Visitados: " << endl;
        visitados.print();
        cout << "Alternativas: " << endl;
        alternativas.print();
    }
}