// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_JUEGO_H
#define PROYECTOPOO2_JUEGO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"
#include "Inicio.h"
#include "Arena.h"
#include "Enemigo.h"
#include "Jugador.h"
#include "Salida.h"

//#include "Enemigo1.h"
//#include "Bala.h"

class Juego {
public:
    Juego() = default;
    ~Juego() = default;
    void run();

private:
    void mostrarContador();
    void mostrarMensajePausa();

    void procesarEventosDeJuego();
    void procesarEventosDeInicio();
    void procesarEventosDeSalida();
    void procesarEventosDeVentana();

    void manejarColisiones();
    void manejarColisionesConEnemigos();
    void manejarColisionesConJugadorBalas();
    void manejarColisionesConEnemigoBalas();

    void reset();
    void actualizar();
    void render(bool display = true);


    bool pausa;
    bool hayEventos;
    int score;
    int cntEnemigo1;

    Inicio intro;
    Salida exit;
    Arena arena;
    Jugador jugador;
    // Estado estado = Estado::PLAYING;

    sf::Event evento;
    sf::RenderWindow ventana;
    std::vector<Enemigo*> enemigo;
    sf::Font* tipoDeLetra;
    sf::Texture* texturaNave;
    sf::Texture* texturaEnemigo1;
    sf::Texture* texturaLogo;
    sf::Texture* texturaBala1;
    sf::Texture* texturaBala2;
    sf::Music musicaFondo;
};


#endif //PROYECTOPOO2_JUEGO_H
