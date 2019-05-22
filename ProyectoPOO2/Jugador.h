// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_JUGADOR_H
#define PROYECTOPOO2_JUGADOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bala.h"
class Jugador {
private:
    int dirX, dirY;
    sf::CircleShape jugador;
    std::vector<Bala*> bala;
    std::vector<bool> borrar;
    sf::Texture texturaBala;
    void actualizarJugador();
    void actualizarBala();
public:
    Jugador() = default;
    Jugador(sf::Texture* texturaNave, sf::Texture* texturaBala);
    ~Jugador() = default;
    void render(sf::RenderWindow& ventana);
    void actualizar();
    void setDireccion(int dirX, int dirY);
    void setBorrarBala(int id);
    inline sf::Vector2f& getPosicion();
    inline sf::CircleShape getJugador();
    inline std::vector<Bala*> getBalas();
    void disparar();
};


#endif //PROYECTOPOO2_JUGADOR_H
