//
// Created by Juan on 12/18/2023.
//

#ifndef L4SFML_GAMELOGIC_H
#define L4SFML_GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

using namespace sf;

class GameLogic {
private:
    std::vector<RectangleShape> alternatives;
    std::vector<RectangleShape> visited;
    RectangleShape currentSpot;
    bool validPos(const float& x, const float& y, std::vector<std::vector<RectangleShape>>& laberinto);
    void findAlternatives(std::vector<std::vector<RectangleShape>>& laberinto);
    void paint(Color color, std::vector<std::vector<RectangleShape>>& laberinto);
    bool isExit(std::vector<std::vector<RectangleShape>>& laberinto);
public:
    bool succes;
    bool failurE;
    GameLogic();
    RectangleShape getCurrentSpot();
    void setCurrentSpot(RectangleShape& currentSpot);
    void move(std::vector<std::vector<RectangleShape>>& laberinto);
    void reset();
};


#endif //L4SFML_GAMELOGIC_H
