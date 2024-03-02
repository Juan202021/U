#ifndef SFML1_GAME_CPP
#define SFML1_GAME_CPP

#include "Game.h"

void Game::initVariables(){
    this->window = nullptr;
    this->live = true;
    this->exit = false;
    this->frame = 1;
    this->count = 0;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(1100,800),"Lab 6");
    this->window->setFramerateLimit(144);
}

void Game::initMenu() {
    // font
    this->font.loadFromFile("../NovaSquare-Regular.ttf");

    // text
    this->title.setString("RETO IMPOSIBLE");
    this->title.setFont(this->font);
    this->title.setCharacterSize(120);
    this->title.setPosition(60.f,150.f);
    this->title.setScale(1.f,1.5f);

    this->textBotton1.setString("Jugar");
    this->textBotton1.setFont(this->font);
    this->textBotton1.setPosition(515.f,510.f);

    this->textBotton2.setString("Salir");
    this->textBotton2.setFont(this->font);
    this->textBotton2.setPosition(520.f,610.f);

    // bottons
    this->botton1.setSize(sf::Vector2f(300.f,60.f));
    this->botton1.setPosition(400.f,500.f);
    this->botton1.setFillColor(sf::Color::Red);

    this->botton2.setSize(sf::Vector2f(300.f,60.f));
    this->botton2.setPosition(400.f,600.f);
    this->botton2.setFillColor(sf::Color::Red);
}

void Game::initPath(){
    sf::CircleShape piecePath(50.f,100);
    piecePath.setOutlineThickness(3.f);
    for (int i = 0; i < 8; i++){
        if (i == 5){
            piecePath.setFillColor(sf::Color(92, 236, 230));
            piecePath.setOutlineColor(sf::Color(105, 6, 225));
        }
        else {
            piecePath.setFillColor(sf::Color(105, 6, 225));
            piecePath.setOutlineColor(sf::Color::Green);
        }
        this->path.emplace_back(piecePath,i);
    }
}

void Game::initGraphPath(){
    for (auto& p : this->path){
        this->graphPath.addVertex(p);
    }
    this->graphPath.getVertex(0)->data.circle.setPosition(200.f,200.f);
    this->graphPath.getVertex(1)->data.circle.setPosition(500.f,100.f);
    this->graphPath.getVertex(2)->data.circle.setPosition(800.f,200.f);
    this->graphPath.getVertex(3)->data.circle.setPosition(400.f,350.f);
    this->graphPath.getVertex(4)->data.circle.setPosition(650.f,350.f);
    this->graphPath.getVertex(5)->data.circle.setPosition(250.f,550.f);
    this->graphPath.getVertex(6)->data.circle.setPosition(500.f,600.f);
    this->graphPath.getVertex(7)->data.circle.setPosition(750.f,550.f);

    this->graphPath.addEdge(0,1);
    this->graphPath.addEdge(0,3);
    this->graphPath.addEdge(0,5);
    this->graphPath.addEdge(1,2);
    this->graphPath.addEdge(1,3);
    this->graphPath.addEdge(1,4);
    this->graphPath.addEdge(2,4);
    this->graphPath.addEdge(2,7);
    this->graphPath.addEdge(3,5);
    this->graphPath.addEdge(3,6);
    this->graphPath.addEdge(4,6);
    this->graphPath.addEdge(4,7);
    this->graphPath.addEdge(5,6);
    this->graphPath.addEdge(6,7);

    this->graphPath.addEdge(1,0);
    this->graphPath.addEdge(3,0);
    this->graphPath.addEdge(5,0);
    this->graphPath.addEdge(2,1);
    this->graphPath.addEdge(3,1);
    this->graphPath.addEdge(4,1);
    this->graphPath.addEdge(4,2);
    this->graphPath.addEdge(7,2);
    this->graphPath.addEdge(5,3);
    this->graphPath.addEdge(6,3);
    this->graphPath.addEdge(6,4);
    this->graphPath.addEdge(7,4);
    this->graphPath.addEdge(6,5);
    this->graphPath.addEdge(7,6);
}

void Game::initLines(){
    lines.setPrimitiveType(sf::Lines);
    sf::Vertex vertexSFML;
    vertexSFML.color = sf::Color::Yellow;
    for (int i = 0; i < this->graphPath.vertexList.size(); i++){
        for (int j = 0; j < this->graphPath.getVertex(i)->connectedTo.size(); j++){
            auto v1 = this->graphPath.getVertex(i);
            vertexSFML.position = sf::Vector2f(v1->data.circle.getPosition().x + 50.f, v1->data.circle.getPosition().y + 50.f);
            lines.append(vertexSFML);
            auto v2 = v1->connectedTo.get(j);
            vertexSFML.position = sf::Vector2f(v2->to->data.circle.getPosition().x + 50.f, v2->to->data.circle.getPosition().y + 50.f);
            lines.append(vertexSFML);
        }
    }
}
void Game::initPlayer() {
    this->player.setPosition(800.f,200.f);
    this->player.setRadius(50.f);
    this->player.setPointCount(100);
    this->player.setFillColor(sf::Color::Black);
    this->player.setOutlineColor(sf::Color::Blue);
    this->player.setOutlineThickness(3.f);
    this->playerNode = 2;
    // texture and sprite
    this->texturePlayer.loadFromFile("../imagePlayer.png");
    this->spritePlayer.setTexture(texturePlayer);
    this->spritePlayer.setPosition(player.getPosition().x + 10.f, player.getPosition().y - 25.f);
    this->spritePlayer.setScale(0.3f,0.3f);
}
void Game::initEnemy(){
    this->enemy.setPosition(200.f,200.f);
    this->enemy.setRadius(50.f);
    this->enemy.setPointCount(100);
    this->enemy.setFillColor(sf::Color::Black);
    this->enemy.setOutlineColor(sf::Color::Red);
    this->enemy.setOutlineThickness(3.f);
    this->enemyNode = 0;
    // texture and sprite
    this->textureEnemy.loadFromFile("../imageEnemy.png");
    this->spriteEnemy.setTexture(textureEnemy);
    this->spriteEnemy.setPosition(enemy.getPosition().x + 10.f, enemy.getPosition().y - 40.f);
    this->spriteEnemy.setScale(0.3f,0.3f);

}
void Game::initMenuGameOver(){
    string text;
    // text
    if (this->live) text = "YOU WIN";
    else text = "YOU LOST";

    this->title.setString(text);
    this->title.setPosition(270.f,150.f);

    this->textBotton1.setString("Volver a intentar");
    this->textBotton1.setPosition(440.f,510.f);

    this->textBotton2.setString("Salir");
    this->textBotton2.setPosition(520.f,610.f);
}

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initMenu();
    this->initPath();
    this->initGraphPath();
    this->initLines();
    this->initPlayer();
    this->initEnemy();
}

Game::~Game() {
    delete this->window;
}

bool Game::runing() {
    return this->window->isOpen() && !this->exit;
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed){
            this->window->close();
        }
        if (event.type == sf::Event::Resized) {
            // Restablecer el tamaño de la ventana al tamaño deseado
            this->window->setSize(sf::Vector2u(1100,800));
        }
    }
}

void Game::updateMousePositions(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateMenu() {
    if (this->botton1.getGlobalBounds().contains(this->mousePosView)){
        this->botton1.setFillColor(sf::Color(144, 28, 4));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (this->frame == 1 || this->frame == 3)){
            this->frame = 2;
            this->initPlayer();
            this->initEnemy();
        }
    }
    else {
        this->botton1.setFillColor(sf::Color::Red);
    }
    if (this->botton2.getGlobalBounds().contains(this->mousePosView)){
        this->botton2.setFillColor(sf::Color(144, 28, 4));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (this->frame == 1 || this->frame == 3)){
            this->exit = true;
        }
    }
    else {
        this->botton2.setFillColor(sf::Color::Red);
    }
}

void Game::updatePlayer(){
    if (this->enemyNode == this->playerNode){
        this->live = false;
        this->frame = 3;
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }
    else if (this->playerNode == 5){
        this->live = true;
        this->frame = 3;
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        // Itera en la lista de vertices
        for (int i = 0; i < this->graphPath.vertexList.size(); i++){
            // Valida si esta cliqueando un circleShape
            if (this->graphPath.getVertex(i)->data.circle.getGlobalBounds().contains(this->mousePosView)){
                // Itera en las aristas del nodo donde se encuentra el player
                for (int j = 0; j < this->graphPath.getVertex(this->playerNode)->connectedTo.size(); j++){
                    // Valida si el que se está cliqueando es una arista del nodo donde se encuentra el player
                    if (this->graphPath.getVertex(this->playerNode)->connectedTo.get(j)->to->data.circle.getPosition().x == this->graphPath.getVertex(i)->data.circle.getPosition().x
                        && this->graphPath.getVertex(this->playerNode)->connectedTo.get(j)->to->data.circle.getPosition().y == this->graphPath.getVertex(i)->data.circle.getPosition().y){
                            this->player.setPosition(this->graphPath.getVertex(i)->data.circle.getPosition());
                            this->spritePlayer.setPosition(player.getPosition().x + 10.f, player.getPosition().y - 25.f);
                            this->playerNode = i;
                            if (this->playerNode != 5 && this->playerNode != this->enemyNode){
                                updateEnemy();
                            }
                            return;
                    }
                }
            }
        }
    }
}

void Game::updateEnemy(){
    this->enemyNode = (findNearestNodeV2(this->enemyNode,this->playerNode) != -1) ? findNearestNodeV2(this->enemyNode,this->playerNode) : this->playerNode;
    this->enemy.setPosition(this->graphPath.getVertex(this->enemyNode)->data.circle.getPosition());
    this->spriteEnemy.setPosition(enemy.getPosition().x + 10.f, enemy.getPosition().y - 40.f);
}

void Game::update() {
    this->pollEvents();
    this->updateMousePositions();
    if (this->frame == 1 || this->frame == 3) this->updateMenu();
    else if (this->frame == 2) this->updatePlayer();
}

void Game::renderMenu() {
    this->window->draw(title);
    this->window->draw(botton1);
    this->window->draw(botton2);
    this->window->draw(textBotton1);
    this->window->draw(textBotton2);
}

void Game::renderPath(){
    for (int i = 0; i < this->graphPath.vertexList.size(); i++){
        this->window->draw(this->graphPath.getVertex(i)->data.circle);
    }
}
void Game::renderLines(){
    this->window->draw(lines);
}

void Game::renderPlayer(){
    this->window->draw(this->player);
    this->window->draw(this->spritePlayer);
}

void Game::renderEnemy(){
    this->window->draw(this->enemy);
    this->window->draw(this->spriteEnemy);
}

void Game::renderMenuGameOver() {
    initMenuGameOver();
    renderMenu();
}

void Game::render() {
    /**
        @return void
     */

    // clear Old Frame
    this->window->clear(sf::Color::Black);


    if (this->frame == 1){
        renderMenu();
    }
    else if (this->frame == 2){
        // Draw shapes/objects
        this->renderLines();
        this->renderPath();
        this->renderPlayer();
        this->renderEnemy();
    }
    else {
        this->renderMenuGameOver();
        this->count++;
    }

    // Show/display in window
    this->window->display();
}

int Game::findNearestNodeV2(int from, int to) {
    int nearest, minMoves = 100, cantMoves;
    Vertex<CircleClass>* originVertex = this->graphPath.getVertex(from);
    Vertex<CircleClass>* destinyVertex = this->graphPath.getVertex(to);

    if (originVertex->data.id == destinyVertex->data.id){
        return -1;
    }
    for (int i = 0; i < originVertex->connectedTo.size(); i++){
        cantMoves = searchNearest(originVertex->connectedTo.get(i)->to, destinyVertex) + 1;
        if (cantMoves <= minMoves){
            minMoves = cantMoves;
            nearest = originVertex->connectedTo.get(i)->to->data.id;
        }
    }
    return nearest;
}

int Game::searchNearestHelper(Vertex<CircleClass>* originVertex, Vertex<CircleClass>* destinyVertex, int count, vector<int> visitados) {
    for (int i = 0; i < originVertex->connectedTo.size(); i++){
        if (originVertex->data.id == destinyVertex->data.id){
            return count;
        }
        for (int v : visitados){
            if (v == originVertex->connectedTo.get(i)->to->data.id) i++;
        }
        if (originVertex->connectedTo.get(i)->to->data.id == this->graphPath.getVertex(this->enemyNode)->data.id){
            continue;
        }
        visitados.push_back(originVertex->connectedTo.get(i)->to->data.id);
        count++;
        return searchNearestHelper(originVertex->connectedTo.get(i)->to, destinyVertex,count,visitados);
    }
}

int Game::searchNearest(Vertex<CircleClass>* originVertex, Vertex<CircleClass>* destinyVertex) {
    vector<int> visitados;
    return searchNearestHelper(originVertex, destinyVertex,0,visitados);
}



#endif