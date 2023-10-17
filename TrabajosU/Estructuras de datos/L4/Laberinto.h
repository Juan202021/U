//
// Created by Juan on 10/13/2023.
//

#ifndef L4_LABERINTO_H
#define L4_LABERINTO_H
#include "Stack.h"
#include "Punto.h"

class Laberinto {
    char laberinto[11][22]{};
    Stack<Punto> visitados;
    Stack<Punto> alternativas;
public:
    Laberinto();
    Laberinto(char laberinto[11][22], Stack<Punto>& visitados, Stack<Punto>& alternativas);
    void cargar();
    void print();
    bool posValida(int fila, int columna);
    bool noPosAnterior(int fila, int columna);
    void buscarAlternativas(const Punto& currentSpot, int& cont);
    void iniciar(const Punto& salida);
};

#endif //L4_LABERINTO_H
