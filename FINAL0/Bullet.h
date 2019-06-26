// Created by felix on 6/1/2019.
#ifndef JUEGO_BULLET_H
#define JUEGO_BULLET_H

#include "Config.h"

class Bullet {
private:
    sf::Texture *texture;
    sf::Sprite sprite;

    float initialVelocity; float maxVelocity;
    sf::Vector2f currentVelocity; float acceleration;

    sf::Vector2f direction;

public:
    Bullet( sf::Texture *texture,sf::Vector2f position,
            sf::Vector2f direction,float initialVelocity,
            float maxVelocity,float acceleration);
    virtual ~Bullet() = default;

    //Access
    inline const sf::FloatRect getGlobalBounds() const {return this->sprite.getGlobalBounds();}
    inline const sf::Vector2f getPosition() const {return this->sprite.getPosition();}

    //Functions
    void movement();
    void update();
    void draw(sf::RenderTarget &target);

};


#endif //JUEGO_BULLET_H
