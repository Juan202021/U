//
// Created by Juan on 10/24/2023.
//

#ifndef L4_INTERFACES_H
#define L4_INTERFACES_H

#include <iostream>
#include <vector>
#include <string.h>

void menu_principal();
int menu(std::string titulo, std::vector<std::string> opciones, int y);
void reproducir_musica();
void elegir_posicion();
bool teclaPresionada(int tecla);
void gotoxy(int x,int y);
void cuadro(int x1, int y1, int ancho, int alto);
void erase(int x1, int y1, int ancho, int alto);

#endif //L4_INTERFACES_H
