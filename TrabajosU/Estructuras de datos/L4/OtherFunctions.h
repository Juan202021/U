#ifndef L4_OTHERFUNCTIONS_H
#define L4_OTHERFUNCTIONS_H
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#define TECLA_ARRIBA 72
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define TECLA_ABAJO 80
#define ENTER 13

class OtherFunctions {
public:
    void gotoxy(int x,int y);
    void cuadro(int x1, int y1, int ancho, int alto);
    void erase(int x1, int y1, int ancho, int alto);
    int plantilla_menu(std::string& titulo, std::vector<std::string> opciones, int x, int y);
};

#endif //L4_OTHERFUNCTIONS_H
