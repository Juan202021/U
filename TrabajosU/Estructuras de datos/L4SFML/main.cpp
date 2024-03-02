#include "Game.h"

int main() {
    Game laberinto;

    while(laberinto.isRunning()){
        laberinto.update();
        laberinto.render();
    }

    return 0;
}
