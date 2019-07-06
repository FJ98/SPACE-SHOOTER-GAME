// Created by felix on 7/4/2019.
#ifndef JUEGO_ENTITY_H
#define JUEGO_ENTITY_H

#include "Config.h"

class Entity{
protected:
    sf::Sprite sprite;
    sf::Texture *texture;
    int hp; int hpMax;
public:
    // Accesos
    inline const int getHP() const { return this->hp; }
    inline const FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    inline const sf::Vector2f getPosition() const { return sprite.getPosition(); }
};

#endif //JUEGO_ENTITY_H
