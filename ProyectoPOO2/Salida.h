// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_SALIDA_H
#define PROYECTOPOO2_SALIDA_H

#include <SFML/Graphics.hpp>
#include <vector>

class Salida {
private:
    int id;
    std::vector<sf::Text> opciones;
    sf::CircleShape nave;
public:
    Salida() = default;
    Salida(sf::Font* tipoDeLetra, sf::Texture* texturaNave);
    ~Salida() = default;
    int getId();
    void render(sf::RenderWindow ventana);
    void mover(int lugar);
};


#endif //PROYECTOPOO2_SALIDA_H
