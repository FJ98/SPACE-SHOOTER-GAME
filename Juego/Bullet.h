// Created by felix on 6/1/2019.
#ifndef JUEGO_BULLET_H
#define JUEGO_BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
using namespace sf; using namespace std;
const float BALA_SPEED = 4.0f; //revisar bordes ventana y modificar
class Bullet {
private:
    sf::Texture *texture;
    sf::Sprite sprite;

    sf::Vector2f maxVelocity;
public:
    Bullet( sf::Texture *texture, sf::Vector2f position,
            sf::Vector2f maxVelocity = sf::Vector2f(0.0f,-BALA_SPEED) );
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
