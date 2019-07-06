// Created by felix on 6/1/2019.
#include "Bullet.h"

Bullet::Bullet(sf::Texture *texture,sf::Vector2f position,
               sf::Vector2f direction,float initialVelocity,
               float maxVelocity,float acceleration){
    this->texture = texture; // Cargar textura
    this->sprite.setTexture(*this->texture); // Setear textura
    this->initialVelocity = initialVelocity; // Setear velocidad inicial
    this->currentVelocity = sf::Vector2f(
            this->initialVelocity * this->direction.x,
            this->initialVelocity * this->direction.y); // Setear velocidad actual

    this->maxVelocity = maxVelocity; // Setear velocidad maxima
    this->acceleration = acceleration; // Setear aceleracion
    this->direction = direction; // Setear direccion
    // Para que la bala salga justo del medio del jugador (comentarlo para ver lo que pasa)
    this->sprite.setPosition(sf::Vector2f(
            position.x - this->sprite.getGlobalBounds().width / 2,
            position.y - this->sprite.getGlobalBounds().height / 2));
}

void Bullet::movement() {
    // MRUV
    if (this->acceleration > 0.0f) {
        if (this->currentVelocity.x < this->maxVelocity) {
            this->currentVelocity.x += this->acceleration * this->direction.x;
        }
        if (this->currentVelocity.y < this->maxVelocity) {
            this->currentVelocity.y += this->acceleration * this->direction.y;
        }
    } else{ // MRU
        this->currentVelocity = sf::Vector2f(
                this->maxVelocity * this->direction.x,
                this->maxVelocity * this->direction.y);
    }
    this->sprite.move(this->currentVelocity);
}

void Bullet::update() {
    this->movement(); // MOVER LA BALA
}

void Bullet::draw(sf::RenderTarget &target) {
    target.draw(this->sprite); // DIBUJAR LA BALA EN LA VENTANA
}
