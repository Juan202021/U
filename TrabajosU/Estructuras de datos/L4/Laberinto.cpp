//
// Created by Juan on 10/13/2023.
//

#include "Laberinto.h"
#include <fstream>

Laberinto::Laberinto(){
    for (int i=0; i<11; i++){
        for (int j=0; j<22; j++){
            laberinto[i][j] = ' ';
        }
    }
}
Laberinto::Laberinto(char laberinto[11][22], Stack<Punto>& visitados, Stack<Punto>& alternativas):
        visitados(visitados), alternativas(alternativas){
    for (int i=0; i<11; i++){
        for (int j=0; j<22; j++){
            this->laberinto[i][j] = laberinto[i][j];
        }
    }
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
            for (int j=0; j<linea.size(); j++){
                laberinto[i][j] = linea[j];
            }
            i++;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }
}
void Laberinto::print(){
    for (int i=0; i<11; i++){
        for (int j=0; j<22; j++){
            cout << laberinto[i][j];
        }
        cout << endl;
    }
}
bool Laberinto::posValida(int fila, int columna){
    return ((fila >= 0 && fila <= 10 && columna >= 0
            && columna <= 21) && (laberinto[fila][columna] != '#'));
}
bool Laberinto::noPosAnterior(int fila, int columna){
    return (fila != visitados.top().getFil() && columna != visitados.top().getCol());
}
void Laberinto::iniciar(const Punto& salida){
    Punto currentSpot = salida;
    bool flag = false;
    if (posValida(salida.getFil(), salida.getCol())){
        flag = true;
        laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
        visitados.push(Punto(currentSpot.getFil(),currentSpot.getCol()));
        print();
    }
    while(flag){
        if (posValida(currentSpot.getFil() - 1, currentSpot.getCol())){
            currentSpot.setFil(currentSpot.getFil() - 1);
            if (noPosAnterior(currentSpot.getFil(),currentSpot.getCol())){
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
            }
            else {
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            }
            visitados.push(Punto(currentSpot.getFil(),currentSpot.getCol()));
        }
        else if (posValida(currentSpot.getFil(), currentSpot.getCol() + 1)){
            currentSpot.setCol(currentSpot.getCol() + 1);
            if (noPosAnterior(currentSpot.getFil(),currentSpot.getCol())){
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
            }
            else {
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            }
            visitados.push(Punto(currentSpot.getFil(),currentSpot.getCol()));
        }
        else if (posValida(currentSpot.getFil(), currentSpot.getCol() - 1)){
            currentSpot.setCol(currentSpot.getCol() - 1);
            if (noPosAnterior(currentSpot.getFil(),currentSpot.getCol())){
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
            }
            else {
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            }
            visitados.push(Punto(currentSpot.getFil(),currentSpot.getCol()));
        }
        else if (posValida(currentSpot.getFil() + 1, currentSpot.getCol())){
            currentSpot.setFil(currentSpot.getFil() + 1);
            if (noPosAnterior(currentSpot.getFil(),currentSpot.getCol())){
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
            }
            else {
                laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
            }
            visitados.push(Punto(currentSpot.getFil(),currentSpot.getCol()));
        }
        else if (currentSpot.getFil() == 2 && currentSpot.getCol() == 0){
            flag = false;
        }
        print();
    }
}