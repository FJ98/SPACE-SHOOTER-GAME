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
   // std::thread first;
    //std::thread second;
    // Texto
    bool exit;
    bool isExit = false;
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
    Game(sf::RenderWindow *window);
    virtual ~Game();

    //Accesos
    inline sf::RenderWindow& getWindow(){return *this->window;}

    //Funciones
    void enemyupdate();
    void playerupdate();

    void initUI();
    void updateUI();
    void drawUI();
    void CombatUpdate();
    void update();
    void draw();
    void controlBoundsNave();
    //void cargarMusica (sf::Music& target, const std::string& path);
    bool getExit() { return exit;}
    Menu getMenu(){return this->wind;}
    int getScore(){return this->score;}
    std::vector<Player> getPlayers(){return this->players;}
};

template <typename T>
void cargar(T& target, std::string path) {
    target.loadFromFile(path);
}

template <>
inline void cargar<sf::Music>(sf::Music& target, std::string path) {
    target.openFromFile(path);
}


#endif //JUEGO_GAME_H
