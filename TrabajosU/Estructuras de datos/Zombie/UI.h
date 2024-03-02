#ifndef ZOMBIE_UI_H
#define ZOMBIE_UI_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Graph.h"
#include <cmath>
#include <cstdlib>
#include <thread>

class UI {
private:

    Graph<Camino> grafo;
    std::vector<Camino> caminos;

    sf::VertexArray lineas;
    sf::CircleShape jugador, enemigo;
    sf::Font fuenteTexto;
    sf::Text titulo, textoBoton1, textoBoton2;
    sf::RectangleShape boton1, boton2;
    sf::Texture texturaJugador, texturaEnemigo, texturaFondo, texturaFondoNivel, texturaCasa;
    sf::Sprite spriteJugador, spriteEnemigo, spriteFondo, spriteFondoNivel, spriteCasa;

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    sf::RenderWindow* window;
    sf::Event event;

    bool aunVive;
    int nodoJugador;
    int nodoEnemigo;
    bool salir;
    int cuadro;
    int count;

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
    UI();
    virtual ~UI();
    void update();
    void updateMousePositions();
    void updateMenu();
    void updatePlayer();
    void updateEnemy();
    bool funcionando();
    void pollEvents();
    void renderMenu();
    void renderPath();
    void renderLines();
    void renderPlayer();
    void renderEnemy();
    void renderMenuGameOver();
    void render();
    float calcularDistancia(sf::Vector2f vertex1, sf::Vector2f vertex2);
    int encontrarNodoMasCercano();
};


#endif //ZOMBIE_UI_H
