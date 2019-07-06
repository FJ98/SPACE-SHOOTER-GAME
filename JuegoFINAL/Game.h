// Created by felix on 6/1/2019.
#ifndef JUEGO_GAME_H
#define JUEGO_GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Menu.h"


class Game {
private:
    sf::RenderWindow *window;
    Menu wind;
    sf::Sound chock;
    sf::SoundBuffer chockBuff;
   // std::thread first;
    //std::thread second;
   // Random Numbers
   std::random_device rd;
    std::mt19937 mt;
    // Texto
    bool exit;
    //bool isExit = false;
    sf::Font font;
    std::vector<sf::Text> followPlayerTexts;
    std::vector<sf::Text> staticPlayerTexts;
    sf::Text gameOverText;
    sf::Text youWinText;
    sf::Text restartText;
    // Players
    std::vector<Player> players;
    int score;
    //Textures
    //std::vector<sf::Texture*> textures;

    sf::Texture playerTexture;
    sf::Texture bulletTexture;
    sf::Texture enemyTexture;

    //Enemies
    std::vector<Enemy> enemies;

    sf::Music music ;

public:
    explicit Game(sf::RenderWindow *window);
    ~Game() = default;

    //Accesos
    //inline sf::RenderWindow& getWindow(){return *this->window;}

    //Funciones
    void colissionBulletEnemy();
    void colissionPlayerEnemy();
    void enemyupdate();
    void playerupdate();

    void initUI();
    void updateUI();
    void drawUI();
    void update();
    void draw();
    void controlBoundsNave();
    bool getExit() { return exit;}
    //Menu getMenu(){return this->wind;}
    int getScore(){return this->score;}
    std::vector<Player> getPlayers(){return this->players;}
    sf::Music &getMusic() {return this->music;}
};


#endif //JUEGO_GAME_H
