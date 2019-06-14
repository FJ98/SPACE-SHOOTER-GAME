// Created by felix on 6/1/2019.
#ifndef JUEGO_PLAYER_H
#define JUEGO_PLAYER_H

#include "Bullet.h"

class Player {
private:
    unsigned playerNr;

    sf::Vector2f playerCenter;

    int shootTimer;
    int shootTimerMax;

    int damageTimer;
    int damageTimerMax;

    sf::Sprite sprite;
    sf::RectangleShape hitBox;
    sf::Texture *texture;

    sf::Texture *bulletTexture;
    std::vector<Bullet> bullets;

    int controls[5];

    sf::Vector2f currentVelocity;
    float maxVelocity;
    float acceleration;
    sf::Vector2f direction;
    float stabilizerForce;

    int level;
    int exp;
    int expNext;

    int hp;
    int hpMax;

    int damage;
    int damageMax;

    int score;

public:
    /* Player(sf::Texture *texture); */
    Player(sf::Texture *texture, sf::Texture *bulletTexture,
            int UP = 22,int DOWN = 18,
            int LEFT = 0, int RIGHT = 3, int SHOOT = 57);
    virtual ~Player();

    //Accesos
    inline std::vector<Bullet>& getBulltes(){return this->bullets;}
    inline const sf::Vector2f& getPosition() const {return this->sprite.getPosition();}
    inline const  sf::String getHpAsString() const {return std::to_string(this->hp) + "/" + std::to_string(this->hpMax);}
    inline FloatRect  getGlobalBounds() const {return this->sprite.getGlobalBounds();}
    inline sf::Sprite &getSprite() {return this->sprite ;}

    //Funciones
    void takedamage();
    void combat();
    void movement();
    void update(sf::Vector2u windowBounds);
    void draw(sf::RenderTarget &target);


    //statics
    static unsigned players;
};


#endif //JUEGO_PLAYER_H