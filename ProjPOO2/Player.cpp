// Created by felix on 5/30/2019.
#include "Player.h"

Player::Player(const sf::Vector2f &pos) {
    texturePlayer.loadFromFile("./images/galagaNave.png");
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(pos);
}

void Player::update(float elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        spritePlayer.move(-CHAR_VEL, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        spritePlayer.move(CHAR_VEL, 0);
    }

}

bool Player::collidesWithBall(Enemy *b) {
    sf::FloatRect charRect = getSprite().getGlobalBounds();
    sf::FloatRect enemyRect = b->getSprite().getGlobalBounds();
    return charRect.intersects(enemyRect);
}


