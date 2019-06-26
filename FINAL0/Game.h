#include <utility>

// Created by felix on 6/1/2019.
#ifndef JUEGO_GAME_H
#define JUEGO_GAME_H

#include "Player.h"
#include "Enemy.h"

class Game {
private:
    sf::RenderWindow *window;
    // std::thread first; //std::thread second;
    // Random Numbers
    std::random_device rd;
    std::mt19937 mt;
    // Texto
    sf::Font font;
    std::vector<sf::Text> followPlayerTexts;
    std::vector<sf::Text> staticPlayerTexts;
    sf::Text gameOverText;
    sf::Text youWinText;

    // Players
    std::vector<Player> players;
    int score;

    //Textures
    sf::Texture playerTexture;
    sf::Texture bulletTexture;
    sf::Texture enemyTexture;

    //Enemies
    std::vector<Enemy> enemies;

    sf::Music music ;

public:
    explicit Game(sf::RenderWindow *window);
    virtual ~Game();

    //Accesos
    //inline sf::RenderWindow& getWindow(){return *this->window;}

    //Funciones
    void enemyUpdate();
    void playerUpdate();
    void initUI();
    void updateUI();
    void drawUI();
    void update();
    void draw();
    void controlBoundsNave();

};





#endif //JUEGO_GAME_H
