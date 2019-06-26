// Created by felix on 6/1/2019.
#ifndef JUEGO_PLAYER_H
#define JUEGO_PLAYER_H

#include "Bullet.h"

class Player {
private:
    sf::Sprite sprite;
    sf::Texture *texture;
    int hp; int hpMax;

    sf::Vector2f playerCenter;

    sf::Texture *bulletTexture;
    std::vector<Bullet> bullets;

    std::array<int, 5> controls;

    sf::Vector2f currentVelocity;
    float maxVelocity; float acceleration;
    sf::Vector2f direction;
    float stabilizerForce;

    int shootTimer; int shootTimerMax;
    int score;

public:
    Player(sf::Texture *texture, sf::Texture *bulletTexture,
            std::array<int,5> controls);
    virtual ~Player() = default;

    //Access
    inline std::vector<Bullet>& getBullets(){return this->bullets;}
    inline const  sf::String getHpAsString() const {return std::to_string(this->hp) + "/" + std::to_string(this->hpMax);}

    inline int getHp() { return this->hp; }
    inline FloatRect  getGlobalBounds() const {return this->sprite.getGlobalBounds();}
    inline const sf::Vector2f& getPosition() const {return this->sprite.getPosition();}
    inline sf::Sprite &getSprite() {return this->sprite ;}

    //Functions
    void combat();
    void movement();

    void takeDamage();
    void update();
    void draw(sf::RenderTarget &target);

};


#endif //JUEGO_PLAYER_H
