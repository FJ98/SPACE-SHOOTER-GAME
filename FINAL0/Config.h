// Created by felix on 6/14/2019.
#ifndef FINAL0_CONFIG_H
#define FINAL0_CONFIG_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <random>

using namespace sf; using namespace std;

#define all(X) begin(X), end(X)

static int WIDTH = 1600, HEIGHT = 1000;

static auto T_PLAYER = "./images/nave2.png";
static auto T_BULLET = "./images/bala2.png";
static auto T_ENEMY = "./images/enemigo02.png";
static auto T_FONT = "./fonts/arial.ttf";
static auto MUSIC_BG = "./sound/background-music.wav";

namespace GameConfig{
    static int WIN_SCORE = 100;
}

namespace PlayerConfig{
    static float NAVE_SPEED = 1.0f; static float NAVE_SCALE = 0.07f;
    static float NAVE_MAX_VEL = 25.0f;
    static float NAVE_ACCELERATION = 0.3f; static float NAVE_STABLE = 0.07f;
    static int SHOOT_TIMER_MAX = 15; static int DAMAGE_TIMER_MAX = 10;
}

namespace EnemyConfig{
    static float ENEMY_SPEED = 12.0f; static float ENEMY_SCALE = 0.03f;

    static int ENEMY_LIFE = 10; static int ENEMY_TIME_MAX = 20;
    static int CURRENT_ENEMY_TIME = 0;
}

namespace Bala{
    static float BALA_DIRX = 1.0f; static float BALA_DIRY = 0.0f;
    static float BALA_INIT_VEL = 2.0f;
    static float BALA_MAX_VEL = 50.0f;
    static float BALA_ACCEL = 1.0f;
}

// Funciones Utiles se utilizan para minimizar el codigo
// al cargar (inicializar) las texturas, fonts y musica.
template <typename T>
void cargar(T& target, std::string path) {
    target.loadFromFile(path);
}

template <>
inline void cargar<sf::Music>(sf::Music& target, std::string path) {
    target.openFromFile(path);
}

template <typename T>
void confText(T& text,
              sf::Font* font, int tamLetra,
              std::vector<T>* textVector,
              const sf::String& str = "Default Text",
              sf::Color color = sf::Color::White,
              sf::Vector2f position = {0.0f,0.0f},
              sf::Uint32 style = sf::Text::Italic){
    text.setFont(*font);
    text.setString(str);
    text.setCharacterSize(tamLetra);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(position);
    textVector->emplace_back(text);
}
template <typename T>
void confText(T& text,
              sf::Font* font, int tamLetra,
              const sf::String& str = "Default Text",
              sf::Color color = sf::Color::White,
              sf::Vector2f position = {0.0f,0.0f},
              sf::Uint32 style = sf::Text::Regular){
    text.setFont(*font);
    text.setString(str);
    text.setCharacterSize(tamLetra);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(position);
}


#endif //FINAL0_CONFIG_H
