// Created by felix on 6/2/2019.
#include "Enemy.h"

Enemy::Enemy(sf::Texture *texture,  sf::Vector2u windowBounds,
            sf::Vector2f position,
            sf::Vector2f direction, sf::Vector2f scale,
            int type,int hpMax, int damageMax, int damageMin)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(scale);
    this->type = type;

    this->hpMax = hpMax;
    this->hp = this->hpMax;

    this->damageMax = damageMax;
    this->damageMin = damageMin;

}

Enemy::~Enemy() {

}

void Enemy::takeDamage(int damage) {
    this->hp -= damage;
    if(this->hp <= 0){
        this->hp = 0;
    }
}

void Enemy::update() {
    switch (this->type) {
        case 0:
            this->sprite.move(-10.0f,0.0f);
            break;
        default: break;
    }
}

void Enemy::draw(sf::RenderTarget &target) {

}
