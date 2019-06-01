// Created by felix on 5/30/2019.
#ifndef PROJPOO2_PLAYER_H
#define PROJPOO2_PLAYER_H

#include "clasesBase/Entity.h"
#include <SFML/Graphics.hpp>
#include "Bala.h"
#include "Enemy.h"

class Player : public Entity {
private:
    sf::Sprite spritePlayer;
    sf::Texture texturePlayer;

    const float CHAR_VEL = 5;
public:
    explicit Player(const sf::Vector2f &pos);
    void update(float elapsed) override ;
    void draw(sf::RenderWindow& window) override {
        window.draw(spritePlayer);
    }
    sf::Sprite &getSprite(){return spritePlayer;}
    bool collidesWithBall(Enemy *b);
};

#endif //PROJPOO2_PLAYER_H
