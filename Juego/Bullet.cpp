// Created by felix on 6/1/2019.
#include "Bullet.h"


Bullet::Bullet(sf::Texture *texture,sf::Vector2f position,
               sf::Vector2f direction,float initialVelocity,
               float maxVelocity,float acceleration){
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->currentVelocity = sf::Vector2f(
            initialVelocity * this->direction.x,
            initialVelocity * this->direction.y);

    this->maxVelocity = maxVelocity;
    this->acceleration = acceleration;
    this->direction = direction;
    this->sprite.setPosition(sf::Vector2f(
            position.x - this->sprite.getGlobalBounds().width/2,
            position.y - this->sprite.getGlobalBounds().height / 2)); // Revisar
}

Bullet::~Bullet() {

}

void Bullet::movement() {
    if (this->acceleration > 0.0f) {
        if (this->currentVelocity.x < this->maxVelocity) {
            this->currentVelocity.x += this->acceleration * this->direction.x;
        }
        if (this->currentVelocity.y < this->maxVelocity) {
            this->currentVelocity.y += this->acceleration * this->direction.y;
        }
    } else{
        this->currentVelocity = sf::Vector2f(
                this->maxVelocity * this->direction.x,
                this->maxVelocity * this->direction.y);
    }
    this->sprite.move(this->currentVelocity);
}

void Bullet::update() {
    this->movement();
}

void Bullet::draw(sf::RenderTarget &target) {
    target.draw(this->sprite);
}
