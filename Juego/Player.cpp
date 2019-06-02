// Created by felix on 6/1/2019.
#include "Player.h"
const float NAVE_SPEED = 4.0f, NAVE_SCALE = 0.05f;
const int SHOOT_TIMER_MAX = 25, DAMAGE_TIMER_MAX = 10;
unsigned Player::players = 0;
enum controls{UP, DOWN, LEFT, RIGHT, SHOOT};

Player::Player(sf::Texture *texture, sf::Texture *bulletTexture,
        int UP,int DOWN, int LEFT, int RIGHT, int SHOOT) :
        level{1}, exp{0}, expNext{100}, hp{10},
        hpMax{10},damage{1},damageMax{2},score{0}
{
    this->texture = texture;
    this->bulletTexture = bulletTexture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(NAVE_SCALE,NAVE_SCALE);
    this->sprite.setPosition(300.0f, 800.0f);

    this->shootTimerMax = SHOOT_TIMER_MAX;
    this->shootTimer = this->shootTimerMax;
    this->damageTimerMax = DAMAGE_TIMER_MAX;
    this->damageTimer = this->damageTimerMax;

    this->controls[controls::UP] = UP;
    this->controls[controls::DOWN] = DOWN;
    this->controls[controls::LEFT] = LEFT;
    this->controls[controls::RIGHT] = RIGHT;
    this->controls[controls::SHOOT] = SHOOT;

    this->playerNr = Player::players;
    Player::players++;
}

Player::~Player() {

}

void Player::movement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::UP]))){
        this->sprite.move(0.0f, -NAVE_SPEED);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::DOWN]))){
        this->sprite.move(0.0f, NAVE_SPEED);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::LEFT]))){
        this->sprite.move(-NAVE_SPEED, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::RIGHT]))){
        this->sprite.move(NAVE_SPEED, 0.0f);
    }

}

void Player::combat() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::SHOOT]))
        && this->shootTimer >= this->shootTimerMax){
        this->bullets.push_back( Bullet(bulletTexture, this->sprite.getPosition()) );
        this->shootTimer = 0; // RESET TIMER
    }
}

void Player::update(sf::Vector2u windowBounds) {
    // update timers
    if (this->shootTimer < this->shootTimerMax){
        shootTimer++;
    }
    if (this->damageTimer < this->damageTimerMax){
        damageTimer++;
    }
    this->movement();
    this->combat();
}

void Player::draw(sf::RenderTarget &target) {
    target.draw(this->sprite);
    for (int i = 0; i < bullets.size(); ++i) {
        this->bullets[i].draw(target);
    }
}


