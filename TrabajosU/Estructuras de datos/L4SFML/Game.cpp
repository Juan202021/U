//
// Created by Juan on 12/13/2023.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include "Game.h"

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)){

        if (this->event.type == Event::Closed){
            this->window->close();
        }
        else if (event.type == Event::MouseWheelMoved) {
            // event.mouseWheel.delta contiene el desplazamiento de la rueda del ratón
            int delta = event.mouseWheel.delta;

            // Puedes usar el valor de delta para determinar la dirección y la cantidad de movimiento
            if (delta > 0) {
                // Rueda hacia arriba
                if (squaresLoadMenu[0].getGlobalBounds().contains(mousePosView)){
                    if (squaresLoadMenu[3].getPosition().y < squaresLoadMenu[0].getPosition().y + 5.f){
                        for (int i = 3; i < squaresLoadMenu.size() + 3; i++){
                            this->squaresLoadMenu[i].setPosition(squaresLoadMenu[i].getPosition().x,squaresLoadMenu[i].getPosition().y + 40.f);
                            this->textLoadMenu[i-2].setPosition(textLoadMenu[i-2].getPosition().x,textLoadMenu[i-2].getPosition().y + 40.f);
                            this->squaresLoadMenu[2].setPosition(squaresLoadMenu[2].getPosition().x,squaresLoadMenu[2].getPosition().y - 1.3f);
                        }
                    }
                }
            }
            else if (delta < 0) {
                // Rueda hacia abajo
                if (squaresLoadMenu[0].getGlobalBounds().contains(mousePosView)){
                    if (squaresLoadMenu[mapFiles.size()+2].getPosition().y + squaresLoadMenu[mapFiles.size()+2].getSize().y + 5.f > squaresLoadMenu[0].getPosition().y + squaresLoadMenu[0].getSize().y){
                        for (int i = 3; i < squaresLoadMenu.size() + 3; i++){
                            this->squaresLoadMenu[i].setPosition(squaresLoadMenu[i].getPosition().x,squaresLoadMenu[i].getPosition().y - 40.f);
                            this->textLoadMenu[i-2].setPosition(textLoadMenu[i-2].getPosition().x,textLoadMenu[i-2].getPosition().y - 40.f);
                            this->squaresLoadMenu[2].setPosition(squaresLoadMenu[2].getPosition().x,squaresLoadMenu[2].getPosition().y + 1.3f);
                        }
                    }
                }
            }
        }
        else if (Mouse::isButtonPressed(Mouse::Left)){
            if (this->frame == 1){
                for (int i = 0; i < buttonsMenu.size(); i++){
                    if (buttonsMenu[i].getGlobalBounds().contains(mousePosView)){
                        std::this_thread::sleep_for(std::chrono::milliseconds(200));
                        switch (i) {
                            case 0:
                                this->frame = 2;
                                return;
                            case 1:
                                this->frame = 3;
                                return;
                            case 2:
                                this->exit = true;
                                return;
                            default:
                                return;
                        }
                    }
                }
            }
            else if (this->frame == 2){
                if (spriteHome.getGlobalBounds().contains(mousePosView)){
                    this->frame = 1;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteBack.getGlobalBounds().contains(mousePosView)){
                    this->frame = 1;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteReload.getGlobalBounds().contains(mousePosView)){
                    initMapas();
                    initMenuCargar();
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                for (int i = 3; i < squaresLoadMenu.size(); i++){
                    if (squaresLoadMenu[i].getGlobalBounds().contains(mousePosView)){
                        this->loadMap = textLoadMenu[i-2].getString();
                        std::cout << loadMap << std::endl;
                        initMapStart();
                        this->frame = 4;
                        std::this_thread::sleep_for(std::chrono::milliseconds(200));
                        return;
                    }
                }
            }
            else if (this->frame == 3){
                if (spriteHome.getGlobalBounds().contains(mousePosView)){
                    this->frame = 1;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteBack.getGlobalBounds().contains(mousePosView)){
                    this->frame = 1;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteReload.getGlobalBounds().contains(mousePosView)){
                    initMenuCrear();
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
            }
            else if (this->frame == 4){
                if (spriteHome.getGlobalBounds().contains(mousePosView)){
                    this->frame = 1;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteBack.getGlobalBounds().contains(mousePosView)){
                    this->frame = 2;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    /*initMapas();
                    initMenuCargar();*/
                    return;
                }
                else if (spriteReload.getGlobalBounds().contains(mousePosView)){
                    initMapStart();
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                for (auto& row : this->laberinto){
                    for (auto& element : row){
                        if (element.getGlobalBounds().contains(mousePosView)){
                            this->frame = 5;
                            initMap();
                            std::this_thread::sleep_for(std::chrono::milliseconds(200));
                            return;
                        }
                    }
                }
            }
            else if (this->frame == 5){
                if (spriteHome.getGlobalBounds().contains(mousePosView)){
                    this->frame = 1;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteBack.getGlobalBounds().contains(mousePosView)){
                    this->frame = 4;
                    initMapStart();
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
                else if (spriteReload.getGlobalBounds().contains(mousePosView)){
                    initMapStart();
                    initMap();
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    return;
                }
            }

        }
    }
}

void Game::initVariables() {
    this->window = nullptr;
    this->squares = {};
    this->textMenu = {};
    this->buttonsMenu = {};
    this->squaresLoadMenu = {};
    this->textLoadMenu = {};
    this->mapFiles = {};
    this->laberinto = {};
    this->frame = 1;
    this->exit = false;
    this->textureHome.loadFromFile("../../Resources/home.png");
    this->spriteHome.setTexture(textureHome);
    this->spriteHome.setPosition(10.f,10.f);
    this->spriteHome.setScale(0.25f,0.25f);
    this->textureBack.loadFromFile("../../Resources/back.png");
    this->spriteBack.setTexture(textureBack);
    this->spriteBack.setPosition(65.f,10.f);
    this->spriteBack.setScale(0.18f,0.18f);
    this->textureReload.loadFromFile("../../Resources/reload1.png");
    this->spriteReload.setTexture(textureReload);
    this->spriteReload.setPosition(120.f,10.f);
    this->spriteReload.setScale(0.17f,0.17f);
    this->timer = 0;
}

void Game::initWindow() {
    this->window = new RenderWindow(VideoMode(600,600),"LABERINTO");
    //this->window->setFramerateLimit(30);
    this->window->setKeyRepeatEnabled(false);
    this->widthWindow = static_cast<float>(this->window->getSize().x);
    this->heightWindow = static_cast<float>(this->window->getSize().y);
}

void Game::initMapas() {
    std::string directorio = "../../Mapas", name;
    mapFiles.clear();
    for (const auto& entry : std::filesystem::directory_iterator(directorio)) {
        if (std::filesystem::is_regular_file(entry) && entry.path().extension() == ".txt") {
            auto nombreArchivo = entry.path().filename();
            name = nombreArchivo.string();
            mapFiles.push_back(name);
        }
    }
}

void Game::initMenu() {
    float var;
    std::vector<std::string> buttonTexts;

    var = 0.f;
    buttonTexts.emplace_back("LABERINTO");
    buttonTexts.emplace_back("Cargar nivel");
    buttonTexts.emplace_back("Crear nivel");
    buttonTexts.emplace_back("Salir");

    // Font
    this->font.loadFromFile("../NovaSquare-Regular.ttf");

    // Buttons
    for(int i = 0; i < 3; i++){
        this->buttonsMenu.emplace_back(Vector2f(200.f,50.f));
        this->buttonsMenu[i].setFillColor(Color::White);
        this->buttonsMenu[i].setPosition( widthWindow / 3.f,heightWindow / 2.f + var);
        var += 70.f;
    }

    // Text
    for (int i = 0; i < buttonTexts.size(); i++){
        if (i == 0){
            this->textMenu.emplace_back(buttonTexts[i],this->font,70);
            this->textMenu[i].setFillColor(Color::White);
            this->textMenu[i].setPosition(widthWindow / 5.f,100.f);
        }
        else {
            this->textMenu.emplace_back(buttonTexts[i],this->font,22);
            this->textMenu[i].setFillColor(Color::Black);
            this->textMenu[i].setPosition(((this->buttonsMenu[i-1].getSize().x - (static_cast<float>(buttonTexts[i].size()) * 10.5)) / 2) + this->buttonsMenu[i-1].getPosition().x,this->buttonsMenu[i-1].getPosition().y + 10.f);
        }
    }

}

void Game::initMenuCargar() {
    textLoadMenu.clear();
    squaresLoadMenu.clear();
    float var = 0.f;
    // Tittle
    this->textLoadMenu.emplace_back(textMenu[1].getString(),this->font,70);
    this->textLoadMenu[0].setPosition(widthWindow / 5.5f, 100.f);

    // Big square
    this->squaresLoadMenu.emplace_back(Vector2f(310.f, 290.f));
    this->squaresLoadMenu[0].setFillColor(Color(165, 192, 191));
    this->squaresLoadMenu[0].setPosition(145.f,250.f);

    // Thin rectangle
    this->squaresLoadMenu.emplace_back(Vector2f(20.f, 280.f));
    this->squaresLoadMenu[1].setFillColor(Color(136, 146, 146));
    this->squaresLoadMenu[1].setPosition(430.f,255.f);

    // Mobile rectangle
    this->squaresLoadMenu.emplace_back(Vector2f(20.f, 280.f - ((static_cast<float>(mapFiles.size()) - 7.f)) * 21.f ));
    this->squaresLoadMenu[2].setFillColor(Color::White);
    this->squaresLoadMenu[2].setPosition(430.f,255.f);


    for (int i = 0; i < mapFiles.size(); i++){
        // File squares
        this->squaresLoadMenu.emplace_back(Vector2f(275.f, 40.f));
        this->squaresLoadMenu[i+3].setFillColor(Color(165, 192, 191));
        this->squaresLoadMenu[i+3].setPosition(150.f,255.f + var);

        // Text files squares
        this->textLoadMenu.emplace_back(mapFiles[i],this->font,24);
        this->textLoadMenu[i+1].setFillColor(Color::Black);
        this->textLoadMenu[i+1].setPosition(160.f,260.f + var);

        var += 40.f;
    }

}

void Game::initMenuCrear() {

}

void Game::initMapStart() {
    std::string directorio = "../../Mapas/" + this->loadMap, linea;
    float posX = 0.f, posY = 150.f;

    laberinto.clear();
    std::ifstream archivo(directorio);
    if (archivo.is_open()) {
        int i = 0;
        while (getline(archivo, linea)) {
            laberinto.emplace_back();
            for (char j : linea){
                if (j == ' '){
                    laberinto[i].emplace_back(Vector2f(30.f,30.f));
                    laberinto[i][laberinto[i].size()-1].setFillColor(Color::White);
                    laberinto[i][laberinto[i].size()-1].setPosition(posX,posY);
                    posX += 30.f;
                }
                else if (j == '#'){
                    laberinto[i].emplace_back(Vector2f(30.f,30.f));
                    laberinto[i][laberinto[i].size()-1].setFillColor(Color::Yellow);
                    laberinto[i][laberinto[i].size()-1].setPosition(posX,posY);
                    posX += 30.f;
                }
            }
            i++;
            posX = 0.f;
            posY += 30.f;
        }
        archivo.close();
    }
    this->lastSquare.setSize(Vector2f(30.f, 30.f));
    this->lastSquare.setFillColor(Color::Transparent);
    this->lastSquare.setOutlineThickness(2.f);
    this->lastSquare.setOutlineColor(Color::Blue);
}

void Game::initMap() {
    for (auto& row : this->laberinto){
        for (auto& element : row){
            if (element.getPosition() == lastSquare.getPosition()){
                element.setFillColor(Color::Green);
                this->logic.setCurrentSpot(element);
            }
        }
    }
}

Game::Game() {
    initVariables();
    initWindow();
    initMapas();
    initMenu();
    initMenuCargar();
}

Game::~Game() {
    delete this->window;
}

bool Game::isRunning() {
    return this->window->isOpen() && !this->exit;
}

void Game::updateMousePositions() {
    this->mousePosWindow = Mouse::getPosition(*window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateMenu() {
    for (int i = 0; i < buttonsMenu.size(); i++){
        if (buttonsMenu[i].getGlobalBounds().contains(mousePosView)){
            buttonsMenu[i].setFillColor(Color::Red);
            textMenu[i+1].setFillColor(Color::White);
        }
        else {
            buttonsMenu[i].setFillColor(Color::White);
            textMenu[i+1].setFillColor(Color::Black);
        }

    }
}

void Game::updateMenuCargar() {
    for (int i = 3; i < squaresLoadMenu.size(); i++){
        if (squaresLoadMenu[i].getGlobalBounds().contains(mousePosView)){
            squaresLoadMenu[i].setFillColor(Color(73, 150, 150));
            textLoadMenu[i-2].setFillColor(Color::White);
        }
        else {
            squaresLoadMenu[i].setFillColor(Color(165, 192, 191));
            textLoadMenu[i-2].setFillColor(Color::Black);
        }
    }
}

void Game::updateMenuCrear() {

}

void Game::updateMapStart() {
    for (auto& row : laberinto){
        for (auto& element : row){
            if (element.getGlobalBounds().contains(mousePosView)){
                this->lastSquare.setPosition(element.getPosition());
            }
        }
    }
}

void Game::updateMap() {
    // logic Solution of laberinto

    if (this->timer > 240 && this->timer % 240 == 0){
        this->logic.move(this->laberinto);
    }
    this->timer += 1;
}


void Game::update() {
    pollEvents();
    updateMousePositions();
    if (this->frame == 1) {
        updateMenu();
    }
    else if (this->frame == 2) {
        updateMenuCargar();
    }
    else if (this->frame == 3){
        updateMenuCrear();
    }
    else if (this->frame == 4) {
        updateMapStart();
    }
    else if (this->frame == 5) {
        updateMap();
    }

}

void Game::renderMenu() {
    for (auto& b : this->buttonsMenu){
        this->window->draw(b);
    }
    for (auto& a : this->textMenu){
        this->window->draw(a);
    }
}

void Game::renderMenuCargar() {
    for (int i = 0; i < 3; i++){
        this->window->draw(squaresLoadMenu[i]); // Big square, thin square and mobile square
    }
    this->window->draw(textLoadMenu[0]); // Tittle
    for (int i = 3; i < mapFiles.size() + 3; i++){
        if (squaresLoadMenu[i].getPosition().y > squaresLoadMenu[0].getPosition().y
            && squaresLoadMenu[i].getPosition().y + squaresLoadMenu[i].getSize().y < squaresLoadMenu[0].getSize().y + squaresLoadMenu[0].getPosition().y){
            this->window->draw(squaresLoadMenu[i]);
        }
    }
    for (int i = 1; i < mapFiles.size() + 1; i++){
        if (textLoadMenu[i].getPosition().y > squaresLoadMenu[0].getPosition().y
            && textLoadMenu[i].getPosition().y < squaresLoadMenu[0].getSize().y + squaresLoadMenu[0].getPosition().y){
            this->window->draw(textLoadMenu[i]);
        }
    }
    this->window->draw(this->spriteHome);
    this->window->draw(this->spriteBack);
    this->window->draw(this->spriteReload);
}

void Game::renderMenuCrear() {

}

void Game::renderMapStart() {
    for (auto& row : laberinto){
        for (auto& element : row){
            this->window->draw(element);
        }
    }
    this->window->draw(this->lastSquare);
    this->window->draw(this->spriteHome);
    this->window->draw(this->spriteBack);
    this->window->draw(this->spriteReload);
}

void Game::renderMap() {
    for (auto& row : laberinto){
        for (auto& element : row){
            this->window->draw(element);
        }
    }
    this->window->draw(this->spriteHome);
    this->window->draw(this->spriteBack);
    this->window->draw(this->spriteReload);
}

void Game::render() {
    // clean the window
    this->window->clear(Color::Black);

    // draw on the window
    if (this->frame == 1) { // 1: Initial menu
        renderMenu();
    }
    else if (this->frame == 2) { // 2: Load Map
        renderMenuCargar();
    }
    else if (this->frame == 3){ // 3: Create map
        renderMenuCrear();
    }
    else if (this->frame == 4) { // 4: Choose Initial Map Position
        renderMapStart();
    }
    else if (this->frame == 5) { // 5:
        renderMap();
    }

    // Show in the window
    this->window->display();
    //std::this_thread::sleep_for(std::chrono::milliseconds (95));
}


