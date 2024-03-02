#include "Game.h"

int main() {
    Game juegoImposible;

    while (juegoImposible.runing()){
        juegoImposible.update();
        juegoImposible.render();
    }

    return 0;
}
