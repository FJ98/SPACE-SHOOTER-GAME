// Created by felix on 6/2/2019.
#ifndef JUEGO_ENEMY_H
#define JUEGO_ENEMY_H

#include "Entity.h"
#include "Bullet.h"

class Enemy : public Entity{
private:
    int type; // tipo de enemigo
public:
    Enemy(sf::Texture *texture, sf::Vector2f position, int type, int hpMax);
    ~Enemy() = default;

    //ACCESOS
    inline const int getHPMax() const { return this->hpMax; }

    //FUNCIONES
    void takeDamage(int damage);
    void update();
    void draw(sf::RenderTarget &target);
};


//inline const int getDamage() const { return rand() % this->damageMax + this->damageMin; }
//inline const bool isDamage() const { return this->hp <= 0; }


#endif //JUEGO_ENEMY_H
