// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_ARENA_H
#define PROYECTOPOO2_ARENA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class Arena {
private:
    std::mt19937 rango;
    std::vector<sf::CircleShape> inicios;
public:
    Arena() = default;
    ~Arena() = default;
    void render(sf::RenderWindow& ventana);
    void actualizar();
};


#endif //PROYECTOPOO2_ARENA_H
