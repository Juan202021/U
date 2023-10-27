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

class Laberinto {
    vector<vector<char>> laberinto;
    Stack<Punto> visitados;
    Stack<Punto> alternativas;
public:
    Laberinto();
    Laberinto(vector<vector<char>>& laberinto, Stack<Punto>& visitados, Stack<Punto>& alternativas);
    bool cumpleTam();
    bool cargar();
    void print(const Punto& currentSpot);
    void printPos(const Punto& currentSpot);
    bool esSalida(const Punto& currentSpot);
    bool posValida(int fila, int columna);
    bool noPosAnterior(int fila, int columna);
    void buscarAlternativas(Punto& currentSpot);
    bool continuar();
    void iniciar(const Punto& salida);
    int getTamanioF();
    int getTamanioC();
    void gotoxy(int x,int y);
    void cuadro(int x1, int y1, int ancho, int alto);
};


#endif //L4_LABERINTO_H
