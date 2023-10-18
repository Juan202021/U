//
// Created by Juan on 10/13/2023.
//

#ifndef L4_LABERINTO_H
#define L4_LABERINTO_H
#include <vector>
#include "Stack.h"
#include "Punto.h"
#include <fstream>

class Laberinto {
    vector<vector<char>> laberinto;
    Stack<Punto> visitados;
    Stack<Punto> alternativas;
public:
    Laberinto();
    Laberinto(vector<vector<char>>& laberinto, Stack<Punto>& visitados, Stack<Punto>& alternativas);
    bool cumpleTam();
    void cargar();
    void print(const Punto& currentSpot);
    bool esSalida(const Punto& currentSpot);
    bool posValida(int fila, int columna);
    bool noPosAnterior(int fila, int columna);
    void buscarAlternativas(const Punto& currentSpot, int& cont);
    bool continuar();
    void iniciar(const Punto& salida);
};

#endif //L4_LABERINTO_H
