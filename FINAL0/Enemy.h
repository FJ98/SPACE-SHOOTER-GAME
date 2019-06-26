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
    Enemy(sf::Texture *texture, sf::Vector2f position, int type, int hpMax);
    ~Enemy() = default;

    //Accesos
    inline const int getHP() const { return this->hp; }
    inline const int getHPMax() const { return this->hpMax; }
    inline const FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    inline const sf::Vector2f getPosition() const { return sprite.getPosition(); }
    //inline const int getDamage() const { return rand() % this->damageMax + this->damageMin; }
    //inline const bool isDamage() const { return this->hp <= 0; }
    //Funciones
    void takeDamage(int damage);
    void update();
    void draw(sf::RenderTarget &target);

};


#endif //JUEGO_ENEMY_H
