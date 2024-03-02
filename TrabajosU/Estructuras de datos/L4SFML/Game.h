//
// Created by Juan on 12/13/2023.
//

#ifndef L4SFML_GAME_H
#define L4SFML_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <thread>
#include "GameLogic.h"

using namespace sf;

class Game {
private:
    // Attributes
    RenderWindow* window;
    Event event;
    Vector2i mousePosWindow;
    Vector2f mousePosView;
    std::vector<RectangleShape> squares;
    std::vector<RectangleShape> buttonsMenu;
    std::vector<Text> textMenu;
    std::vector<RectangleShape> squaresLoadMenu;
    std::vector<Text> textLoadMenu;
    std::vector<std::string> mapFiles;
    std::vector<std::vector<RectangleShape>> laberinto;
    Texture textureHome;
    Sprite spriteHome;
    Texture textureBack;
    Sprite spriteBack;
    Texture textureReload;
    Sprite spriteReload;
    Font font;
    RectangleShape lastSquare;
    GameLogic logic;
    int frame; // 1: Initial menu, 2: Load Map, 3: Create map, 4: Choose Initial Map Position
    bool exit;
    float widthWindow, heightWindow;
    std::string loadMap;
    int timer;

    // Inits
    void pollEvents();
    void initVariables();
    void initWindow();
    void initMapas();
    void initMenu();
    void initMenuCargar();
    void initMenuCrear();
    void initMapStart();
    void initMap();

    // Updates
    void updateMousePositions();
    void updateMenu();
    void updateMenuCargar();
    void updateMenuCrear();
    void updateMapStart();
    void updateMap();

    // Renders
    void renderMenu();
    void renderMenuCargar();
    void renderMenuCrear();
    void renderMapStart();
    void renderMap();

public:
    // Functions
    Game();
    ~Game();
    bool isRunning();
    void update();
    void render();

};
#endif //L4SFML_GAME_H