#ifndef SFML1_GAME_H
#define SFML1_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Graph.h"
#include <cmath>
#include <cstdlib>
#include <thread>

class Game {
private:
    // window
    sf::RenderWindow* window;
    sf::Event event;
    // graph
    Graph<CircleClass> graphPath;
    std::vector<CircleClass> path;

    // shapes
    sf::Texture textureEnemy;
    sf::Texture texturePlayer;
    sf::Sprite spriteEnemy;
    sf::Sprite spritePlayer;
    sf::VertexArray lines;
    //std::vector<sf::CircleShape> path;
    sf::CircleShape player, enemy;
    sf::Font font;
    sf::Text title, textBotton1, textBotton2;
    sf::RectangleShape botton1, botton2;
    // mouse
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    // others
    bool live;
    int playerNode;
    int enemyNode;
    bool exit;
    int frame;
    int count;

    // private functions
    void initVariables();
    void initWindow();
    void initMenu();
    void initGraphPath();
    void initPath();
    void initLines();
    void initPlayer();
    void initEnemy();
    void initMenuGameOver();

public:
    Game();
    virtual ~Game();
    void update();
    void updateMousePositions();
    void updateMenu();
    void updatePlayer();
    void updateEnemy();
    bool runing();
    void pollEvents();
    void renderMenu();
    void renderPath();
    void renderLines();
    void renderPlayer();
    void renderEnemy();
    void renderMenuGameOver();
    void render();
    float findDistance(sf::Vector2f vertex1, sf::Vector2f vertex2);
    int findNearestNode();
    int findNearestNodeV2(int from, int to);
    int searchNearestHelper(Vertex<CircleClass>* vertex, Vertex<CircleClass>* destinyVertex, int count, vector<int> visitados);
    int searchNearest(Vertex<CircleClass>* vertex, Vertex<CircleClass>* destinyVertex);

};


#endif //SFML1_GAME_H
