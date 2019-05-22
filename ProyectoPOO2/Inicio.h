// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_INICIO_H
#define PROYECTOPOO2_INICIO_H

#include <SFML/Graphics.hpp>
#include <vector>
//#include"Config.h"

class Inicio {
private:
    int id;
    std::vector<sf::Text> opciones;
    sf::CircleShape nave;
    sf::RectangleShape logo;
public:
    Inicio()= default;
    Inicio(sf::Font* tipoDeLetra, sf::Texture* texturaNave, sf::Texture* texturaLogo);
    ~Inicio()= default;
    void render(sf::RenderWindow& ventana);
    void mover(int lugar);
    inline int getId() const{return id;}
};


#endif //PROYECTOPOO2_INICIO_H
