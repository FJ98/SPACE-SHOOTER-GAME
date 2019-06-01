// Created by felix on 5/30/2019.
#ifndef PROJPOO2_ESCENAINICIO_H
#define PROJPOO2_ESCENAINICIO_H

#include <SFML/Graphics.hpp>
#include "clasesBase/BaseScene.h"


class EscenaInicio : public BaseScene {
private:
    sf::Text titleText;
    sf::Text scoreText;
    sf::Text pressStartText;
    sf::Font titleFont;

public:
    EscenaInicio();
    void update(float elapsed);
    void draw(sf::RenderWindow &w);
};


#endif //PROJPOO2_ESCENAINICIO_H
