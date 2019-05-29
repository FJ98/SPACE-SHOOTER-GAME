// Created by felix on 5/28/2019.
#include "Jug.h"


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