#ifndef ZOMBIE_UI_CPP
#define ZOMBIE_UI_CPP

#include "UI.h"

void UI::initVariables(){
    window = nullptr;
    aunVive = true;
    salir = false;
    cuadro = 1;
    count = 0;
}

void UI::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1100,800),"ZOMBIE");
    window->setFramerateLimit(144);
    texturaFondo.loadFromFile("../Fondo.png");
    spriteFondo.setTexture(texturaFondo);
    spriteFondo.setPosition(0.f,0.f);
    spriteFondo.setScale(0.9f,1.1f);
}

void UI::initMenu() {
    fuenteTexto.loadFromFile("../Dhurjati-Regular.ttf");

    titulo.setString("ZOMBIELAND");
    titulo.setFillColor(sf::Color::Blue);
    titulo.setFont(fuenteTexto);
    titulo.setCharacterSize(120);
    titulo.setPosition(300.f, 150.f);
    titulo.setScale(1.f, 1.5f);

    textoBoton1.setString("Jugar");
    textoBoton1.setFont(fuenteTexto);
    textoBoton1.setFillColor(sf::Color::Black);
    textoBoton1.setPosition(515.f, 510.f);

    textoBoton2.setString("Salir");
    textoBoton2.setFont(fuenteTexto);
    textoBoton2.setFillColor(sf::Color::Black);
    textoBoton2.setPosition(520.f, 610.f);

    boton1.setSize(sf::Vector2f(300.f, 60.f));
    boton1.setPosition(400.f, 500.f);
    boton1.setFillColor(sf::Color::Cyan);

    boton2.setSize(sf::Vector2f(300.f, 60.f));
    boton2.setPosition(400.f, 600.f);
    boton2.setFillColor(sf::Color::Cyan);
}

void UI::initPath(){
    sf::CircleShape piecePath(50.f,6);
    piecePath.setOutlineThickness(3.f);
    for (int i = 0; i < 8; i++){
        if (i == 5){
            piecePath.setFillColor(sf::Color::Green);
            piecePath.setOutlineColor(sf::Color(105, 6, 225));

        }
        else {
            piecePath.setFillColor(sf::Color::Red);
            piecePath.setOutlineColor(sf::Color::Black);
        }
        caminos.emplace_back(piecePath, i);
    }
    texturaFondoNivel.loadFromFile("../fondoNivel.png");
    spriteFondoNivel.setTexture(texturaFondoNivel);
    spriteFondoNivel.setPosition(0.f,0.f);
    spriteFondoNivel.setScale(2.2f,2.6f);

}

void UI::initGraphPath(){
    for (auto& p : caminos){
        grafo.addVertex(p);
    }
    grafo.getVertex(0)->data.forma.setPosition(200.f, 200.f);
    grafo.getVertex(1)->data.forma.setPosition(500.f, 100.f);
    grafo.getVertex(2)->data.forma.setPosition(800.f, 200.f);
    grafo.getVertex(3)->data.forma.setPosition(400.f, 350.f);
    grafo.getVertex(4)->data.forma.setPosition(650.f, 350.f);
    grafo.getVertex(5)->data.forma.setPosition(250.f, 550.f);
    grafo.getVertex(6)->data.forma.setPosition(500.f, 600.f);
    grafo.getVertex(7)->data.forma.setPosition(750.f, 550.f);

    grafo.addEdge(0, 1);
    grafo.addEdge(0, 3);
    grafo.addEdge(0, 5);
    grafo.addEdge(1, 2);
    grafo.addEdge(1, 3);
    grafo.addEdge(1, 4);
    grafo.addEdge(2, 4);
    grafo.addEdge(2, 7);
    grafo.addEdge(3, 5);
    grafo.addEdge(3, 6);
    grafo.addEdge(4, 6);
    grafo.addEdge(4, 7);
    grafo.addEdge(5, 6);
    grafo.addEdge(6, 7);

    grafo.addEdge(1, 0);
    grafo.addEdge(3, 0);
    grafo.addEdge(5, 0);
    grafo.addEdge(2, 1);
    grafo.addEdge(3, 1);
    grafo.addEdge(4, 1);
    grafo.addEdge(4, 2);
    grafo.addEdge(7, 2);
    grafo.addEdge(5, 3);
    grafo.addEdge(6, 3);
    grafo.addEdge(6, 4);
    grafo.addEdge(7, 4);
    grafo.addEdge(6, 5);
    grafo.addEdge(7, 6);
}

void UI::initLines(){
    lineas.setPrimitiveType(sf::Lines);
    sf::Vertex vertexSFML;
    vertexSFML.color = sf::Color::Black;

    for (int i = 0; i < grafo.vertexList.size(); i++){
        for (int j = 0; j < grafo.getVertex(i)->connectedTo.size(); j++){
            auto v1 = grafo.getVertex(i);
            vertexSFML.position = sf::Vector2f(v1->data.forma.getPosition().x + 50.f, v1->data.forma.getPosition().y + 50.f);
            lineas.append(vertexSFML);
            auto v2 = v1->connectedTo.get(j);
            vertexSFML.position = sf::Vector2f(v2->to->data.forma.getPosition().x + 50.f, v2->to->data.forma.getPosition().y + 50.f);
            lineas.append(vertexSFML);
        }
    }
    texturaCasa.loadFromFile("../casa.png");
    spriteCasa.setTexture(texturaCasa);
    spriteCasa.setPosition(grafo.getVertex(5)->data.forma.getPosition().x - 50, grafo.getVertex(5)->data.forma.getPosition().y - 5);
    spriteCasa.setScale(0.29f,0.29f);
}
void UI::initPlayer() {
    jugador.setPosition(800.f, 200.f);
    jugador.setRadius(50.f);
    jugador.setPointCount(6);
    jugador.setFillColor(sf::Color::Red);
    jugador.setOutlineColor(sf::Color::Black);
    jugador.setOutlineThickness(3.f);
    nodoJugador = 2;
    texturaJugador.loadFromFile("../Jugador.png");
    spriteJugador.setTexture(texturaJugador);
    spriteJugador.setScale(0.2f,0.2f);
    spriteJugador.setPosition(jugador.getPosition().x + 28, jugador.getPosition().y);
}
void UI::initEnemy(){
    enemigo.setPosition(200.f, 200.f);
    enemigo.setRadius(50.f);
    enemigo.setPointCount(6);
    enemigo.setFillColor(sf::Color::Red);
    enemigo.setOutlineColor(sf::Color::Black);
    enemigo.setOutlineThickness(3.f);
    nodoEnemigo = 0;
    texturaEnemigo.loadFromFile("../enemigo.png");
    spriteEnemigo.setTexture(texturaEnemigo);
    spriteEnemigo.setScale(0.35f,0.35f);
    spriteEnemigo.setPosition(enemigo.getPosition().x - 40, enemigo.getPosition().y - 15);
}
void UI::initMenuGameOver(){
    string text;
    // text
    if (aunVive) {
        text = "SOLO FUE SUERTE";
        titulo.setPosition(170.f, 150.f);
    }
    else {
        text = "GAME OVER";
        titulo.setPosition(300.f, 150.f);
    }

    titulo.setString(text);

    textoBoton1.setString("Jugar de nuevo");
    textoBoton1.setPosition(460.f, 510.f);

    textoBoton2.setString("Salir");
    textoBoton2.setPosition(530.f, 610.f);
}

UI::UI() {
    initVariables();
    initWindow();
    initMenu();
    initPath();
    initGraphPath();
    initLines();
    initPlayer();
    initEnemy();
}

UI::~UI() {
    delete window;
}

bool UI::funcionando() {
    return window->isOpen() && !salir;
}

void UI::pollEvents() {
    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window->close();
        }
        if (event.type == sf::Event::Resized) {
            // Restablecer el tamaño de la ventana al tamaño deseado
            window->setSize(sf::Vector2u(1100,800));
        }
    }
}

void UI::updateMousePositions(){
    mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);
}

void UI::updateMenu() {
    if (boton1.getGlobalBounds().contains(mousePosView)){
        boton1.setFillColor(sf::Color(148, 198, 196));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (cuadro == 1 || cuadro == 3)){
            cuadro = 2;
            initPlayer();
            initEnemy();
        }
    }
    else {
        boton1.setFillColor(sf::Color::Cyan);
    }
    if (boton2.getGlobalBounds().contains(this->mousePosView)){
        boton2.setFillColor(sf::Color(148, 198, 196));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (cuadro == 1 || cuadro == 3)){
            salir = true;
        }
    }
    else {
        boton2.setFillColor(sf::Color::Cyan);
    }
}

void UI::updatePlayer(){
    if (nodoEnemigo == nodoJugador){
        aunVive = false;
        cuadro = 3;
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }
    else if (nodoJugador == 5){
        aunVive = true;
        cuadro = 3;
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        for (int i = 0; i < grafo.vertexList.size(); i++){
            if (grafo.getVertex(i)->data.forma.getGlobalBounds().contains(mousePosView)){
                for (int j = 0; j < grafo.getVertex(nodoJugador)->connectedTo.size(); j++){
                    if (grafo.getVertex(nodoJugador)->connectedTo.get(j)->to->data.forma.getPosition().x == grafo.getVertex(i)->data.forma.getPosition().x
                        && grafo.getVertex(nodoJugador)->connectedTo.get(j)->to->data.forma.getPosition().y == grafo.getVertex(i)->data.forma.getPosition().y){
                            jugador.setPosition(grafo.getVertex(i)->data.forma.getPosition());
                            nodoJugador = i;
                            spriteJugador.setPosition(jugador.getPosition().x + 28, jugador.getPosition().y);
                            if (nodoJugador != 5 && nodoJugador != nodoEnemigo){
                                updateEnemy();

                            }
                            return;
                    }
                }
            }
        }
    }
}

void UI::updateEnemy(){
    nodoEnemigo = (encontrarNodoMasCercano() != -1) ? encontrarNodoMasCercano() : nodoJugador;
    enemigo.setPosition(grafo.getVertex(nodoEnemigo)->data.forma.getPosition());
    spriteEnemigo.setPosition(enemigo.getPosition().x - 40, enemigo.getPosition().y - 15);
}

void UI::update() {
    pollEvents();
    updateMousePositions();
    if (cuadro == 1 || cuadro == 3) updateMenu();
    else if (cuadro == 2) updatePlayer();
}

void UI::renderMenu() {
    window->draw(spriteFondo);
    window->draw(titulo);
    window->draw(boton1);
    window->draw(boton2);
    window->draw(textoBoton1);
    window->draw(textoBoton2);
}

void UI::renderPath(){

    for (int i = 0; i < grafo.vertexList.size(); i++){
        window->draw(grafo.getVertex(i)->data.forma);
    }

}
void UI::renderLines(){
    window->draw(spriteFondoNivel);
    window->draw(lineas);
}

void UI::renderPlayer(){
    window->draw(jugador);

}

void UI::renderEnemy(){
    window->draw(enemigo);
    window->draw(spriteEnemigo);
}

void UI::renderMenuGameOver() {
    initMenuGameOver();
    renderMenu();
}

void UI::render() {
    window->clear(sf::Color::White);

    if (cuadro == 1){
        renderMenu();
    }
    else if (cuadro == 2){
        renderLines();
        renderPath();
        renderPlayer();
        renderEnemy();
        window->draw(spriteCasa);
        window->draw(spriteJugador);
        window->draw(spriteEnemigo);
    }
    else {
        renderMenuGameOver();
        count++;
    }
    window->display();
}

float UI::calcularDistancia(sf::Vector2f vertex1, sf::Vector2f vertex2) {
    return static_cast<float>( sqrt( pow(vertex2.x - vertex1.x,2) + pow(vertex2.y - vertex1.y,2) ) );
}
int UI::encontrarNodoMasCercano() {
    Vertex<Camino>* vertexEnemy = grafo.getVertex(nodoEnemigo);
    Vertex<Camino>* vertexPlayer = grafo.getVertex(nodoJugador);
    int nearestVertex;
    float minDistance = 100000.f;
    float distance;

    if (count % 2 == 0 && count > 20){
        srand(time(nullptr));
        nearestVertex = rand() % vertexEnemy->connectedTo.size();
        for (int i = 0; i < vertexEnemy->connectedTo.size(); i++){
            if (vertexEnemy->connectedTo.get(i)->to == grafo.getVertex(nodoJugador)){
                return -1;
            }
        }
        return vertexEnemy->connectedTo.get(nearestVertex)->to->data.numero;
    } else {
        for (int i = 0; i < vertexEnemy->connectedTo.size(); i++){
            if (vertexEnemy->connectedTo.get(i)->to == grafo.getVertex(nodoJugador)){
                return -1;
            }
            distance = calcularDistancia(sf::Vector2f(vertexEnemy->connectedTo.get(i)->to->data.forma.getPosition().x,
                                                      vertexEnemy->connectedTo.get(i)->to->data.forma.getPosition().y),
                                         sf::Vector2f(vertexPlayer->data.forma.getPosition().x, vertexPlayer->data.forma.getPosition().y));
            if (distance < minDistance){
                minDistance = distance;
                nearestVertex = vertexEnemy->connectedTo.get(i)->to->data.numero;
            }
        }
        return nearestVertex;
    }

}

#endif