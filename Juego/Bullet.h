// Created by felix on 6/1/2019.
#ifndef JUEGO_BULLET_H
#define JUEGO_BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace sf; using namespace std;

const float BALA_DIRX = 1.0f, BALA_DIRY = 0.0f,
BALA_INIT_VEL = 2.0f, BALA_MAX_VEL = 50.0f, //revisar bordes ventana y modificar
BALA_ACCEL = 1.0f;

class Bullet {
private:
    sf::Texture *texture;
    sf::Sprite sprite;

    sf::Vector2f currentVelocity;
    float initialVelocity;
    float maxVelocity;
    float acceleration;
    sf::Vector2f direction;

public:
    Bullet( sf::Texture *texture,sf::Vector2f position,
            sf::Vector2f direction,float initialVelocity,
            float maxVelocity,float acceleration);
    virtual ~Bullet();

    //Accesos
    inline const sf::FloatRect getGlobalBounds() const {return this->sprite.getGlobalBounds();}
    inline const sf::Vector2f getPosition() const {return this->sprite.getPosition();}

    //Funciones
    void movement();
    void update();
    void draw(sf::RenderTarget &target);

};


#endif //JUEGO_BULLET_H
