// Created by felix on 6/1/2019.
#include "Bullet.h"


Bullet::Bullet(sf::Texture *texture, sf::Vector2f position,
        sf::Vector2f maxVelocity){
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->maxVelocity = maxVelocity;
    this->sprite.setPosition(position);//No entiendo
}

Bullet::~Bullet() {

}

void Bullet::movement() {
this->sprite.move(this->maxVelocity.x,this->maxVelocity.y);
}

void Bullet::update() {
    this->movement();
}

void Bullet::draw(sf::RenderTarget &target) {
    target.draw(this->sprite);
}
