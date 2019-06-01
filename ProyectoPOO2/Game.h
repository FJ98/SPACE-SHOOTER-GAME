// Created by felix on 5/28/2019.
#ifndef PROYECTOPOO2_GAME_H
#define PROYECTOPOO2_GAME_H

#include <SFML/Graphics.hpp>
#include "Jug.h"
#include <random>

class Game {
public:
    Game(sf::Vector2f resolution, sf::String& titulo);
    void gameLoop();

private:

    sf::RenderWindow* window;

    sf::Clock* clock1;
    sf::Time* time1;
    float time2;

    float fps;
    bool gameOver = false;

    Jug* player1;
    Enemy* enemy1;
};


#endif //PROYECTOPOO2_GAME_H
