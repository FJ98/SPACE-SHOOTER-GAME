// Created by felix on 5/30/2019.
#ifndef PROJPOO2_ENEMY_H
#define PROJPOO2_ENEMY_H


#include "clasesBase/Entity.h"

class Enemy : public Entity {
public:
    Enemy();
    void update(float elapsed) override;
    void draw(sf::RenderWindow &w) override;
    sf::Sprite &getSprite();
private:
    sf::Texture texEnemy;
    sf::Sprite spEnemy;
    sf::Vector2f velEnemy;
};


#endif //PROJPOO2_ENEMY_H
