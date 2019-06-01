// Created by felix on 5/30/2019.
#include "Enemy.h"

Enemy::Enemy() {
    texEnemy.loadFromFile("/images/galagaEnemigo1.png");
    spEnemy.setTexture(texEnemy);

    srand(time(0));
    spEnemy.setPosition(rand()%608, rand()%200);
    velEnemy.x = 2+rand()%3;
    velEnemy.y = 2+rand()%3;

}

void Enemy::update(float elapsed) {
    // mover la pelota
    spEnemy.move(velEnemy);

    // limitar el movimiento de la pelota a la ventana
    sf::Vector2f enemyPos = spEnemy.getPosition();
    if(enemyPos.x < 0){
        enemyPos.x = 0;
        velEnemy.x *= -1;
    }
    if(enemyPos.x > 608){
        enemyPos.x = 608;
        velEnemy.x *= -1;
    }
    if(enemyPos.y < 0){
        enemyPos.y = 0;
        velEnemy.y *= -1;
    }
    if(enemyPos.y > 306){
        enemyPos.y = 306;
        velEnemy.y *= -1;
    }
    spEnemy.setPosition(enemyPos);
}

void Enemy::draw(sf::RenderWindow &w) {w.draw(spEnemy);}
sf::Sprite &Enemy::getSprite() {return spEnemy;}
