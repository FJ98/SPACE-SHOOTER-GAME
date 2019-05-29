// Created by felix on 5/28/2019.
#ifndef PROYECTOPOO2_JUG_H
#define PROYECTOPOO2_JUG_H

#include <SFML/Graphics.hpp>

class Jug {
public:
    Jug();
    void update(float delta_t);
    sf::Sprite getSprite(){return *spriteJugador;}

private:
    sf::Sprite* spriteJugador;
    sf::Texture* texturaJugador;
    sf::Vector2f velocidad;
};


#endif //PROYECTOPOO2_JUG_H
