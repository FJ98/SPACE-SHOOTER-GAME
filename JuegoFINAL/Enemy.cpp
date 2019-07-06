// Created by felix on 6/2/2019.
#include "Enemy.h"

Enemy::Enemy(sf::Texture *texture, sf::Vector2f position, int type, int hpMax){
    this->texture = texture; // Cargar textura
    this->sprite.setTexture(*this->texture); // Setear textura
    this->sprite.setScale(EnemyConfig::ENEMY_SCALE,EnemyConfig::ENEMY_SCALE); // Tamano del enemigo
    this->type = type; // Setear tipo de enemigo
    this->sprite.setPosition(position); // Posicion del enemigo

    this->hpMax = hpMax; // Maximo de vida
    this->hp = this->hpMax; // Vida actual
}
void Enemy::takeDamage(int damage) {
    // Nos permite decidir el numero de disparos que
    // el enemigo va a recibir antes de que muera
    this->hp -= damage;
    if(this->hp <= 0){
        this->hp = 0;
    }
}
void Enemy::update() {
    // Se hizo este switch porque la idea es que hayan mas tipos de enemigos
    switch (this->type) {
        case 0:
            this->sprite.move(-EnemyConfig::ENEMY_SPEED,0.0f);
            break;
        default: break;
    }
}
void Enemy::draw(sf::RenderTarget &target) {
    // Dibujar al enemigo sobre una ventana que es pasada como parametro
    target.draw(this->sprite);
}
