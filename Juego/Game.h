// Created by felix on 6/1/2019.
#ifndef JUEGO_GAME_H
#define JUEGO_GAME_H

#include "Player.h"

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
    sf::Texture playerTexture;
    sf::Texture bulletTexture;

public:
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


};


#endif //JUEGO_GAME_H
