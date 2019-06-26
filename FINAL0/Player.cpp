// Created by felix on 6/1/2019.
#include "Player.h"

enum controls{UP, DOWN, LEFT, RIGHT, SHOOT};

Player::Player(sf::Texture *texture, sf::Texture *bulletTexture,
        std::array<int,5> controls) : controls{controls},
        hp{10}, hpMax{10}, score{0} {
    this->texture = texture;
    this->bulletTexture = bulletTexture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(PlayerConfig::NAVE_SCALE, PlayerConfig::NAVE_SCALE);
    //this->sprite.setPosition(300.0f, 800.0f);

    this->shootTimerMax = PlayerConfig::SHOOT_TIMER_MAX;
    this->shootTimer = PlayerConfig::SHOOT_TIMER_MAX;
    this->maxVelocity = PlayerConfig::NAVE_MAX_VEL;
    this->acceleration = PlayerConfig::NAVE_ACCELERATION;
    this->stabilizerForce = PlayerConfig::NAVE_STABLE;
}

void Player::movement() {
    // Configurado para que la nave tenga un movimiento suave y algo inestable
    // ARRIBA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::UP]))){
        this->direction.x = 0.0f;
        this->direction.y = -PlayerConfig::NAVE_SPEED;

        if (this->currentVelocity.y > -this->maxVelocity && this->direction.y < 0) {
            this->currentVelocity.y += this->direction.y * acceleration;
        }
    }
    // ABAJO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::DOWN]))){
        this->direction.x = 0.0f;
        this->direction.y = PlayerConfig::NAVE_SPEED;
        if (this->currentVelocity.y < this->maxVelocity && this->direction.y > 0) {
            this->currentVelocity.y += this->direction.y * acceleration;
        }
    }
    //IZQUIERDA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::LEFT]))){
        this->direction.x = -PlayerConfig::NAVE_SPEED;
        this->direction.y = 0.0f;
        if (this->currentVelocity.x > -this->maxVelocity && this->direction.x < 0) {
            this->currentVelocity.x += this->direction.x * acceleration;
        }
    }
    // DERECHA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::RIGHT]))){
        this->direction.x = PlayerConfig::NAVE_SPEED;
        this->direction.y = 0.0f;
        if (this->currentVelocity.x < this->maxVelocity && this->direction.x > 0) {
            this->currentVelocity.x += this->direction.x * acceleration;
        }
    }
    // Estabilizador de la nave
    // IZQUIERDA
    if (this->currentVelocity.x > 0){
        this->currentVelocity.x -= this->stabilizerForce;
        if (this->currentVelocity.x < 0){
            this->currentVelocity.x = 0;
        }
    }

    else if (this->currentVelocity.x < 0){
        this->currentVelocity.x += this->stabilizerForce;
        if (this->currentVelocity.x > 0){
            this->currentVelocity.x = 0;
        }
    }
    // ABAJO
    if (this->currentVelocity.y > 0){
        this->currentVelocity.y -= this->stabilizerForce;
        if (this->currentVelocity.y < 0){
            this->currentVelocity.y = 0;
        }
    }
    // ARRIBA
    else if (this->currentVelocity.y < 0){
        this->currentVelocity.y += this->stabilizerForce;
        if (this->currentVelocity.y > 0){
            this->currentVelocity.y = 0;
        }
    }
    // mov final
    this->sprite.move(this->currentVelocity);

}

void Player::combat() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::SHOOT]))
        && this->shootTimer >= this->shootTimerMax){
        this->bullets.emplace_back( Bullet(bulletTexture, this->playerCenter,
                sf::Vector2f(Bala::BALA_DIRX,Bala::BALA_DIRY), Bala::BALA_INIT_VEL, Bala::BALA_MAX_VEL, Bala::BALA_ACCEL));
        this->shootTimer = 0; // RESET TIMER
    }
}

void Player::takeDamage() { this->hp--; }

void Player::update() {
    // update timers
    if (this->shootTimer < this->shootTimerMax){
        shootTimer++;
    }
    // Para que la bala salga del centro de la nave
    this->playerCenter.x = this->sprite.getPosition().x + this->sprite.getGlobalBounds().width;
    this->playerCenter.y = this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2;

    this->movement(); // movimento de la nave
    this->combat(); // disparos de la nave
}

void Player::draw(sf::RenderTarget &target) {
    target.draw(this->sprite);
    for (int i = 0; i < bullets.size(); ++i) {
        this->bullets[i].draw(target);
    }
}
