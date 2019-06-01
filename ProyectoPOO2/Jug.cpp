// Created by felix on 5/28/2019.
#include "Jug.h"
#include <random>

Jug::Jug() {
    texturaJugador = new sf::Texture;
    texturaJugador->loadFromFile("./images/bala.png");
    spriteJugador = new sf::Sprite(*texturaJugador);

    spriteJugador->setPosition(400, 300);

    velocidad.x = 0.0f;
    velocidad.y = -1.5f;
}

void Jug::update(float delta_t){
    spriteJugador->setPosition(spriteJugador->getPosition().x + velocidad.x*delta_t, spriteJugador->getPosition().y + velocidad.y * delta_t);
}

Enemy::Enemy() {
    texturaEnemy = new sf::Texture;
    texturaEnemy->loadFromFile("./images/galagaEnemigo1.png");
    spriteEnemy = new sf::Sprite(*texturaEnemy);
    spriteEnemy->setPosition(200, 100);
}

void Enemy::updateVel(float delta_t) {

}

void Enemy::update() {

}
