#include "UI.h"

int main() {
    UI game;

    while (game.funcionando()){
        game.update();
        game.render();
    }

    return 0;
}
