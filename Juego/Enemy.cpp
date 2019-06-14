// Created by felix on 6/2/2019.
#include "Enemy.h"
const float ENEMY_SPEED = 5.0f;
enum eTypes {MOVELEFT, FOLLOW, FOLLOWFAST,FOLLOWSHOOT,FOLLOWFASTSHOOT};

Enemy::Enemy(sf::Texture *texture,  sf::Vector2u windowBounds,
            sf::Vector2f position,
            sf::Vector2f direction, sf::Vector2f scale,
            int type,int hpMax, int damageMax, int damageMin)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(scale);
    this->sprite.setPosition(windowBounds.x - this->sprite.getGlobalBounds().width,
                             (rand() % windowBounds.y) - this->sprite.getGlobalBounds().height);

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
            this->sprite.move(-ENEMY_SPEED,0.0f);
            break;
        default: break;
    }
}

void Enemy::draw(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

