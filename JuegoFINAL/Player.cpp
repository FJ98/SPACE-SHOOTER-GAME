// Created by felix on 6/1/2019.
#include "Player.h"
enum controls{UP, DOWN, LEFT, RIGHT, SHOOT};
Player::Player(sf::Texture *texture, sf::Texture *bulletTexture,
               std::array<int,5> controls){
    this->texture = texture; // Cargar textura jugador
    this->bulletTexture = bulletTexture; // Cargar textura bala
    this->sprite.setTexture(*this->texture); // setear textura jugador
    this->sprite.setScale(PlayerConfig::NAVE_SCALE,PlayerConfig::NAVE_SCALE); // escala jugador
    //this->sprite.setPosition(300.0f, 800.0f); // Iniciar jugador en una posicion determinada
    this->controls = controls; // controles para controlar al jugador
    this->hp = PlayerConfig::NAVE_LIFE; // Vida del jugador
    this->hpMax = PlayerConfig::NAVE_LIFE; // Vida maxima del jugador
    this->shootTimerMax = PlayerConfig::SHOOT_TIMER_MAX; // Tiempo maximo de disparo
    this->shootTimer = this->shootTimerMax; // Tiempo de disparo
    this->maxVelocity = PlayerConfig::NAVE_MAX_VEL; // Velocidad maxima
    this->acceleration = PlayerConfig::NAVE_ACCELERATION; // Aceleracion
    this->stabilizerForce = PlayerConfig::NAVE_STABLE; // Estabilidad de la nave
    this->bufferShoot.loadFromFile(PlayerConfig::MUSIC_SHOOT); // cargar sonido de disparo
}


void Player::movement() {
    // Configurado para que la nave tenga un movimiento suave y algo inestable
    // ARRIBA
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key(this->controls[controls::UP]) ) ){
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
    // DERECHA
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
    // Movimiento final del jugador
    this->sprite.move(this->currentVelocity);
}

void Player::takeDamage() { this->hp--; } // Dano que recibe el jugador

void Player::update() {
    // update timers
    if (this->shootTimer < this->shootTimerMax){
        shootTimer++;
    }
    // PARA QUE LA BALA SALGA DEL CENTRO DE LA NAVE
    this->playerCenter.x = this->sprite.getPosition().x +
            this->sprite.getGlobalBounds().width;
    this->playerCenter.y = this->sprite.getPosition().y +
            this->sprite.getGlobalBounds().height / 2;

    this->movement(); // movimento de la nave
    this->combat(); // disparos de la nave
}
void Player::combat() {
    // DISPARAR APRETANDO barra espaciadora Y QUE LAS BALAS SALGAN CADA CIERTO TIEMPO
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::SHOOT]))
         && this->shootTimer >= this->shootTimerMax ){
        this->soundShoot.setBuffer(bufferShoot); // Setear sonido de disparo
        this->bullets.emplace_back( Bullet(bulletTexture, this->playerCenter,
                                           sf::Vector2f(Bala::BALA_DIRX,Bala::BALA_DIRY), Bala::BALA_INIT_VEL, Bala::BALA_MAX_VEL, Bala::BALA_ACCEL) );
        this->soundShoot.play(); // Reproducir sonido de disparo
        this->shootTimer = 0; // RESET TIMER
    }
}
void Player::draw(sf::RenderTarget &target) {
    target.draw(this->sprite); // DIBUJAR JUGADOR
    // DIBUJAR BALAS DEL JUGADOR
    for (int i = 0; i < bullets.size(); ++i) {
        this->bullets[i].draw(target);
    }
}


