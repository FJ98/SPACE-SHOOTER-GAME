// Created by felix on 6/2/2019.
#ifndef JUEGO_ENEMY_H
#define JUEGO_ENEMY_H

#include "Bullet.h"

class Enemy {
private:
    sf::Texture *texture;
    sf::Sprite sprite;
    int hp; int hpMax;

    int type;
public:
    Enemy(sf::Texture *texture, sf::Vector2u windowBounds,
          sf::Vector2f position,
          sf::Vector2f direction,
          int type, int hpMax);

    ~Enemy();

    //Accesos
    inline const int getHP() const { return this->hp; }
    inline const int getHPMax() const { return this->hpMax; }
    inline const bool isDamage() const { return this->hp <= 0; }
    inline const FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    inline const sf::Vector2f getPosition() const { return sprite.getPosition(); }

    //Funciones
    void takeDamage(int damage);
    void update(sf::Vector2u windowBounds);
    void draw(sf::RenderTarget &target);

};


#endif //JUEGO_ENEMY_H
