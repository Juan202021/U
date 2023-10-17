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
    return (fila >= 0 && fila <= 10 && columna >= 0 && columna <= 21 && laberinto[fila][columna] == ' ');
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
    Punto exitSpot(2,0), currentSpot = entrada;
    bool flag = true;
    int cont = 0;
    laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
    visitados.push(currentSpot);
    buscarAlternativas(currentSpot,cont);
    print();
    while(flag){
        if (currentSpot == exitSpot){
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
    }
}