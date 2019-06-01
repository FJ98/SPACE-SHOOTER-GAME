// Created by felix on 5/29/2019.
#include "Bala.h"

Bala::Bala() {
    texturaBala = new sf::Texture;
    texturaBala->loadFromFile("./images/bala.png");
    spriteBala = new sf::Sprite(*texturaBala);

    spriteBala->setPosition(250, 250);

    velocidad.x = 0.0f;
    velocidad.y = -1.5f;
}

void Bala::move(float delta_t){
    spriteBala->setPosition(spriteBala->getPosition().x + velocidad.x*delta_t, spriteBala->getPosition().y + velocidad.y * delta_t);
}