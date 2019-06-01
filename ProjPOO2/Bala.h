// Created by felix on 5/29/2019.
#ifndef PROJPOO2_BALA_H
#define PROJPOO2_BALA_H

#include <SFML/Graphics.hpp>

class Bala {
public:
    Bala();
    void move(float delta_t);
    sf::Sprite getSprite(){return *spriteBala;}

private:
    sf::Sprite* spriteBala;
    sf::Texture* texturaBala;
    sf::Vector2f velocidad;
};


#endif //PROJPOO2_BALA_H
