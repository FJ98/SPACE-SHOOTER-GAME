// Created by felix on 5/29/2019.
#ifndef PROJPOO2_GAME_H
#define PROJPOO2_GAME_H

#include <SFML/Graphics.hpp>
#include "../Bala.h"
#include "BaseScene.h"

/* Clase para manejar un bucle de juego con distintas escenas */
class Game {
public:
    void run();
    //cambiar la escena actual por otra
    void switchScene(BaseScene *scene);
    // obtener la instancia de juego (singleton)
    static Game &getInstance();
    // crear un juego especificando el modo de video y la escena inicial
    static Game &create(const sf::VideoMode &videoMode, BaseScene *scene, const sf::String &name = "");

    Game(sf::Vector2f resolution, sf::String& titulo);
    void gameLoop();

private:
    sf::RenderWindow* window;
    BaseScene *currentScene, *nextScene;
    sf::Clock* clock;
    void processEvents();
    void update();
    void draw();
    static Game *instance;
    Game() = default;

    sf::RenderWindow* window1;
    sf::Clock* clock1;
    sf::Time* time1;
    float time2;
    float fps;
    bool gameOver = false;
    Bala* bala;
    Bala* bala2;
};


#endif //PROJPOO2_GAME_H
