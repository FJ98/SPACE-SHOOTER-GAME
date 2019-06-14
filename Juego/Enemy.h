// Created by felix on 6/2/2019.
#ifndef JUEGO_ENEMY_H
#define JUEGO_ENEMY_H

#include "Bullet.h"
class Enemy {
private:
    sf::Texture *texture;
    sf::Sprite sprite;
    sf::Vector2u windowBounds;
    sf::Vector2f direction;
    int type;
    int hp;
    int hpMax;
    int damageMin;
    int damageMax;

public:
    Enemy(sf::Texture *texture, sf::Vector2u windowBounds,
            sf::Vector2f position,
          sf::Vector2f direction, sf::Vector2f scale,
          int type, int hpMax, int damageMax, int damageMin);

    virtual ~Enemy();

    //Accesos
    inline const int getDamage() const { return rand() % this->damageMax + this->damageMin; }
    inline const int getHP() const { return this->hp; }
    inline const int getHPMax() const { return this->hpMax; }
    inline const bool isDead() const { return this->hp <= 0; }
    inline sf::Sprite &getSprite() { return this->sprite;}
    inline sf::FloatRect getGlobalBounds() const { return this->sprite.getGlobalBounds(); }
    inline sf::Vector2f getPosition() const { return this->sprite.getPosition(); }

    //Funciones
    void takeDamage(int damage);
    void update();
    void draw(sf::RenderTarget &target);
};


#endif //JUEGO_ENEMY_H
