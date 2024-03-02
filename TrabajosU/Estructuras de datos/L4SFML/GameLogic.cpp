//
// Created by Juan on 12/18/2023.
//

#include "GameLogic.h"

GameLogic::GameLogic(){
    this->alternatives = {};
    this->visited = {};
    this->succes = false;
    this->failurE = false;
}

bool GameLogic::validPos(const float& x, const float& y, std::vector<std::vector<RectangleShape>>& laberinto) {
    bool valid = false;
    for (auto& row : laberinto){
        for (auto& element : row){
            if (element.getPosition() == Vector2f(x,y) && element.getFillColor() == Color::White && ( visited.empty() || element.getPosition() != visited[visited.size()-1].getPosition())){
                valid = true;
                break;
            }
        }
    }
    std::cout<< ( x >= laberinto[0][0].getPosition().x ) << " - " << ( x <= laberinto[0][laberinto[0].size()-1].getPosition().x ) << " - " << ( y >= laberinto[0][0].getPosition().y ) << " - " << ( y <= laberinto[laberinto.size()-1][0].getPosition().y ) <<std::endl;
    return valid && ( x >= laberinto[0][0].getPosition().x )
            && ( x <= laberinto[0][laberinto[0].size()-1].getPosition().x )
            && ( y >= laberinto[0][0].getPosition().y )
            && ( y <= laberinto[laberinto.size()-1][0].getPosition().y );
}

void GameLogic::findAlternatives(std::vector<std::vector<RectangleShape>>& laberinto) {
    RectangleShape square(Vector2f(30.f,30.f));

    if (validPos(currentSpot.getPosition().x,currentSpot.getPosition().y + 30.f,laberinto)){
        square.setPosition(currentSpot.getPosition().x,currentSpot.getPosition().y + 30.f);
        alternatives.push_back(square);
    }
    if (validPos(currentSpot.getPosition().x - 30.f,currentSpot.getPosition().y,laberinto)){
        square.setPosition(currentSpot.getPosition().x - 30.f,currentSpot.getPosition().y);
        alternatives.push_back(square);
    }
    if (validPos(currentSpot.getPosition().x + 30.f,currentSpot.getPosition().y,laberinto)){
        square.setPosition(currentSpot.getPosition().x + 30.f,currentSpot.getPosition().y);
        alternatives.push_back(square);
    }
    if (validPos(currentSpot.getPosition().x,currentSpot.getPosition().y - 30.f,laberinto)){
        square.setPosition(currentSpot.getPosition().x,currentSpot.getPosition().y - 30.f);
        alternatives.push_back(square);
    }
}

void GameLogic::paint(Color color, std::vector<std::vector<RectangleShape>>& laberinto) {
    for (auto& row : laberinto){
        for (auto& element : row){
            if (element.getPosition() == currentSpot.getPosition()){
                element.setFillColor(color);
            }
        }
    }
}

bool GameLogic::isExit(std::vector<std::vector<RectangleShape>>& laberinto){
    for (int i = 0; i < laberinto.size(); i++){
        for (int j = 0; j < laberinto[0].size(); j++){
            if (currentSpot.getPosition() == laberinto[i][j].getPosition()
                && ( i == 0 || i == laberinto.size()-1 || j == 0 || j == laberinto[0].size()-1 ) ){
                return true;
            }
        }
    }
    return false;
}

RectangleShape GameLogic::getCurrentSpot() {
    return currentSpot;
}

void GameLogic::setCurrentSpot(RectangleShape& currentSpot) {
    this->currentSpot = currentSpot;
}

void GameLogic::move(std::vector<std::vector<RectangleShape>>& laberinto) {
    std::cout << "Move" << std::endl;
    /*std::cout << alternatives.size() << std::endl;
    std::cout << visited.size() << std::endl;*/
    if (isExit(laberinto)){
        this->succes = true;
    }
    else if (alternatives.empty() && visited.size() == 1){
        this->failurE = true;
    }
    else if (alternatives.empty() && visited.empty()){
        findAlternatives(laberinto);
    }
    else if (alternatives.size() == 1){
        currentSpot = alternatives[alternatives.size()-1];
        alternatives.pop_back();
        findAlternatives(laberinto);
        visited.push_back(currentSpot);
        paint(Color::Green,laberinto);
    }
    else if (alternatives.empty() && visited.size() > 1){
        visited.pop_back();
        findAlternatives(laberinto);
        currentSpot = visited[visited.size()-1];
        paint(Color::Red,laberinto);
    }
    else if (alternatives.size() > 1){
        currentSpot = alternatives[alternatives.size()-1];
        alternatives.clear();
        findAlternatives(laberinto);
        visited.push_back(currentSpot);
        paint(Color::Green,laberinto);
    }
}

void GameLogic::reset() {
    this->alternatives.clear();
    this->visited.clear();
}




