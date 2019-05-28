// Created by felix on 5/21/2019.
#include "Jugador.h"
#include "Config.h"

Jugador::Jugador(sf::Texture *texturaNave, sf::Texture *texturaBala) {
    jugador.setRadius(JUGADOR::RADIO); // setRadius propio de SFML
    jugador.setPosition(JUGADOR::posicion);  //
    jugador.setTexture(texturaNave); // cargar nave
    this->texturaBala = texturaBala;
    dirY = DIR::NOMOVE;
    dirX = DIR::RIGHT;
}

Jugador::~Jugador() {
    for (auto item: bala){delete item;}
}

void Jugador::setDireccion(int dirX, int dirY) {
    if (dirX != DIR::UNCHANGED) {this->dirX = dirX;}
    if (dirY != DIR::UNCHANGED) {this->dirY = dirY;}
}

void Jugador::actualizarJugador() {
    if (dirY != DIR::NOMOVE) {
        sf::Vector2f pos = jugador.getPosition();
        if (dirY == DIR::UP) pos.y -= JUGADOR::movVelocY;
        if (dirY == DIR::DOWN) pos.y += JUGADOR::movVelocY;
        if (0 < pos.y and pos.y + 2 * JUGADOR::RADIO < ALTO) jugador.setPosition(pos);
    }
    if (dirX != DIR::NOMOVE) {
        sf::Vector2f pos = jugador.getPosition();
        if (dirX == DIR::LEFT) pos.x -= JUGADOR::movVelocX;
        if (dirX == DIR::RIGHT) pos.x += JUGADOR::movVelocX;
        if (0 < pos.x and pos.x + 2 * JUGADOR::RADIO < ANCHO) jugador.setPosition(pos);
    }
}

void Jugador::actualizarBala() {
    /*
    int id = 0;
    for_each(all(bala), [&] (auto item) {
        if (item -> getPosicion().x > ANCHO) borrar[id] = true;
        id++;
    });
    id = 0;
    auto toDelete1 = remove_if(all(bala), [&] (auto bullet_i) {
        return borrar[id++];
    });
    bala.erase(toDelete1, end(bala));
    auto toDelete2 = remove_if(all(borrar), [&] (bool elem) {
        return elem;
    });
    borrar.erase(toDelete2, end(borrar));
    for_each(all(bala), [&] (auto bullet_i) {
        bullet_i -> actualizar();
    });
     */
}

void Jugador::actualizar() {
    actualizarJugador();
    actualizarBala();
}

void Jugador::render(sf::RenderWindow& ventana) {
    /*
    std::for_each( all(bala), [&ventana](auto item) {
        item->render(ventana);
    } );
    ventana.draw(jugador);
     */
}

void Jugador::setBorrarBala(int id) {borrar[id] = true;}

inline const sf::Vector2f &Jugador::getPosicion() const {return jugador.getPosition();}
inline const sf::CircleShape Jugador::getJugador() const {return jugador;}

std::vector<Bala *> Jugador::getBalas() {return bala;}

void Jugador::disparar() {
    sf::Vector2f pos = jugador.getPosition(); //
    pos.x += 2 * JUGADOR::RADIO;
    pos.y += JUGADOR::RADIO;

    bala.emplace_back(new Bala(pos, DIR::RIGHT, texturaBala));
    borrar.push_back(false);
}

