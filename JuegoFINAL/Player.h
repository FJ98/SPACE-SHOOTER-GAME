// Created by felix on 6/1/2019.
#ifndef JUEGO_PLAYER_H
#define JUEGO_PLAYER_H

#include "Entity.h"
#include "Bullet.h"

class Player : public Entity {
private:
    sf::SoundBuffer bufferShoot;
    sf::Sound soundShoot;

    sf::Vector2f playerCenter;

    sf::Texture *bulletTexture;
    std::vector<Bullet> bullets;

    std::array<int,5> controls{};

    sf::Vector2f currentVelocity;
    float maxVelocity;
    float acceleration;
    sf::Vector2f direction;
    float stabilizerForce;

    int shootTimer; int shootTimerMax;


public:
    Player(sf::Texture *texture, sf::Texture *bulletTexture,
           std::array<int,5> controls);
    ~Player() = default;

    inline std::vector<Bullet>& getBullets(){return this->bullets;}
    inline const  sf::String getHpAsString() const {return std::to_string(this->hp) + "/" + std::to_string(this->hpMax);}
    inline sf::Sprite &getSprite() {return this->sprite;}

    //Funciones
    void takeDamage();
    void combat();
    void movement();
    void update();
    void draw(sf::RenderTarget &target);
};


#endif //JUEGO_PLAYER_H
