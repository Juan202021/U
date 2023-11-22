//
// Created by Juan on 10/13/2023.
//

#ifndef L4_LABERINTO_H
#define L4_LABERINTO_H
#include <vector>
#include "Stack.h"
#include "Punto.h"
#include <fstream>
#include <chrono>
#include <thread>
#include "OtherFunctions.h"

class Laberinto: public OtherFunctions {
public: // BUSCAR UNA FORMA MAS OPTIMA DE HACERLO
    vector<vector<char>> laberinto;
    vector<vector<char>> laberintoCopia;
    Stack<Punto> visitados;
    Stack<Punto> alternativas;

    Laberinto();
    Laberinto(vector<vector<char>>& laberinto, Stack<Punto>& visitados, Stack<Punto>& alternativas);
    bool cumpleTam();
    bool cargar();
    void print(const Punto& currentSpot, int x, int y);
    void print2(const Punto& currentSpot, int x, int y);
    void printPos(Punto& lastSpot, Punto& currentSpot, int x, int y);
    void printPos2(Punto& lastSpot, Punto& currentSpot, int x, int y);
    bool esSalida(const Punto& currentSpot);
    bool posValida(int fila, int columna);
    bool noPosAnterior(int fila, int columna);
    void buscarAlternativas(Punto& currentSpot);
    void printInfo();
    void iniciar(const Punto& salida);
    int getTamanioF();
    int getTamanioC();
    void printPuntosRecorridos();
    void printCamino(Punto currentSpot = Punto());
    void reset();
    int visitadosSize();
};


#endif //L4_LABERINTO_H
