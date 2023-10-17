#include <iostream>
#include "Laberinto.h"

using namespace std;

int main() {
    Laberinto laberinto;
    Punto p(8,15);
    laberinto.cargar();
    laberinto.iniciar(p);


    return 0;
}
