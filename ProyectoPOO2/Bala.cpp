// Created by felix on 5/21/2019.
#include "Bala.h"
#include "Config.h"
#include <iostream>

Bala::Bala (sf::Vector2f pos, int dir, sf::Texture* textura):
        dir(dir),
        bala(BalaConfig::dimensiones) {
    bala.setPosition(pos);
    bala.setTexture(textura);
}

void Bala::render (sf::RenderWindow& ventana) {
    ventana.draw(bala);
}

void Bala::actualizar () {
    auto pos = bala.getPosition();
    pos.x = pos.x + dx[dir] * BalaConfig::dx;
    bala.setPosition(pos);
}