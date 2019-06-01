// Created by felix on 5/30/2019.
#ifndef PROJPOO2_ENTITY_H
#define PROJPOO2_ENTITY_H


#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void update(float elapsed) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};


#endif //PROJPOO2_ENTITY_H
