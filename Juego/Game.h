// Created by felix on 6/1/2019.
#ifndef JUEGO_GAME_H
#define JUEGO_GAME_H

#include "Player.h"
#include "Enemy.h"
class Game {
private:
    sf::RenderWindow *window;

    // Texto
    sf::Font font;
    std::vector<sf::Text> followPlayerTexts;
    std::vector<sf::Text> staticPlayerTexts;

    // Players
    std::vector<Player> players;

    //Textures
    //std::vector<sf::Texture*> textures;
    sf::Texture playerTexture;
    sf::Texture bulletTexture;
    sf::Texture enemyTexture;

    //Enemies
    std::vector<Enemy> enemies;
    std::vector<Enemy> enemiesSaved;
    int enemyAppearTimer;
    int enemyAppearTimerMax;
    // MainMenu

    //Musica
    sf::Music music ;

public:
    Game();
    Game(sf::RenderWindow *window);
    virtual ~Game();

    //Accesos
    inline sf::RenderWindow& getWindow(){return *this->window;}

    //Funciones
    void initUI();
    void updateUI();
    void drawUI();
    void CombatUpdate();
    void update();
    void draw();
    void controlBoundsNave();
    void cargarMusica (sf::Music& target, std::string path);
};

template <typename T>
void cargar(T& target, std::string path) { 
    target.loadFromFile(path);
}



#endif //JUEGO_GAME_H
