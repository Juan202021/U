#include <iostream>
#include "Laberinto.h"

using namespace std;

int main() {
    Laberinto laberinto;
    Punto p(9,16);
    laberinto.cargar();
    laberinto.iniciar(p);

    return 0;
}
