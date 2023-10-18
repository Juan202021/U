#include <iostream>
#include "Laberinto.h"
using namespace std;

int main() {
    Laberinto laberinto;
    Punto p(8,15);
    system("title LABERINTO C++");
    laberinto.cargar();
    laberinto.iniciar(p);
    system("pause");
    return 0;
}
