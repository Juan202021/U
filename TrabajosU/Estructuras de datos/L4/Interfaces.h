#ifndef L4_INTERFACES_H
#define L4_INTERFACES_H

#include <iostream>
#include <vector>
#include <string.h>
#include "Laberinto.h"
#include "OtherFunctions.h"

class Interfaces: public OtherFunctions {
    Laberinto laberintoObj;
public:
    Interfaces();
    void menu_principal();
    int menuContinuarLaberinto();
    void reproducir_musica();
    void elegir_posicion();
    bool teclaPresionada(int tecla);

};


#endif //L4_INTERFACES_H
