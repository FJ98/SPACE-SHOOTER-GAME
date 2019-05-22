// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_ENEMIGO_H
#define PROYECTOPOO2_ENEMIGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bala.h"

class Enemigo {
public:
    Enemigo() = default;
    virtual ~Enemigo() = default;
    virtual void render(sf::RenderWindow& ventana) = 0;
    virtual void actualizar(sf::Vector2f posJugador) = 0;
    virtual void setParaBorrar(int id) = 0;
    virtual std::vector <sf::CircleShape>& getEnemigos() = 0;
    virtual int getScore() = 0;
    inline std::vector<Bala*> getBalas(){ return balas;}

    int direccionX, direccionY, score;
    float x, y;
    std::vector<Bala*> balas;
};


#endif //PROYECTOPOO2_ENEMIGO_H
