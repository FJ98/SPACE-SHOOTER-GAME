// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_BALA_H
#define PROYECTOPOO2_BALA_H

#include <SFML/Graphics.hpp>

class Bala {
private:
    int dir;
    sf::RectangleShape bala;
public:
    Bala() = default;
    Bala(sf::Vector2f pos, int dir, sf::Texture textura);
    ~Bala() = default;
    void render(sf::RenderWindow& ventana);
    void actualizar();
    inline sf::RectangleShape getBala();
    inline sf::Vector2f getPosicion();
};


#endif //PROYECTOPOO2_BALA_H
