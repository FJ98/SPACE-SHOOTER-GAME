// Created by felix on 5/21/2019.
#ifndef PROYECTOPOO2_CONFIG_H
#define PROYECTOPOO2_CONFIG_H

#include <SFML/Graphics.hpp>
#include <vector>

#define all(X) begin(X), end(X)

// TITULO
static std::string NOMBRE_JUEGO = "Galaga - Felix Solano";

// DIMENSIONES DE LA VENTANA
static int ANCHO = 1200;
static int ALTO = 600;

// RECURSOS DIRECTIORIO
static std::string DIRECTORIO_TEXTO = "./fonts/arial.ttf";
static std::string DIRECTORIO_NAVE  = "./images/spaceship1.png";
static std::string DIRECTORIO_ENEMIGO1 = "./images/enemy01.png";
static std::string DIRECTORIO_CAMINO = "./images/logo.png";
static std::string DIRECTORIO_BALA1 = "./images/bullet1.png";
static std::string DIRECTORIO_BALA2 = "./images/bullet2.png";
static std::string DIRECTORIO_MUSICA_FONDO = "./sound/background-music.wav";

// Inicio
namespace InicioConfig {
    static int PLAY = 0;
    static int EXIT = 1;
    static int TAMANO_TEXTO = 80;
    static int MARGEN = 10;
    static std::string OPCION1 = "PLAY";
    static sf::Vector2f POS1(ANCHO / 2.f, ALTO / 2.f);
    static std::string OPCION2 = "EXIT";
    static sf::Vector2f POS2(ANCHO / 2.f, ALTO / 2.f + TAMANO_TEXTO + MARGEN);
    static float RADIUS = TAMANO_TEXTO / 2.f;
    static std::vector <sf::Vector2f> POS_NAVE = {
            {ANCHO / 2.f - 3 * RADIUS, ALTO / 2.f},
            {ANCHO / 2.f - 3 * RADIUS, ALTO / 2.f + TAMANO_TEXTO + MARGEN}};
    static sf::Vector2f LOGO_TAMANO(600.f, 130.f);
    static sf::Vector2f POS_LOGO(2 * ANCHO / 7.f, 100.f);
}

// Salida
namespace SalidaConfig {
    static int AGAIN = 0;
    static int EXIT = 1;
    static int TEXT_SIZE = 80;
    static int PADDING = 10;
    static std::string OPTION1 = "AGAIN";
    static sf::Vector2f POS1(ANCHO / 2.f, ALTO / 2.f);
    static std::string OPTION2 = "EXIT";
    static sf::Vector2f POS2(ANCHO / 2.f, ALTO / 2.f + TEXT_SIZE + PADDING);
    static float RADIUS = TEXT_SIZE / 2.f;
    static std::vector <sf::Vector2f> SPACESHIP_POS = {
            {ANCHO / 2.f - 3 * RADIUS, ALTO / 2.f},
            {ANCHO / 2.f - 3 * RADIUS, ALTO / 2.f + TEXT_SIZE + PADDING}};
}

// CONTADOR
namespace COUNTER {
    static std::vector <std::string> MSG = {"1", "2", "3", "GO"};
    static int TEXT_SIZE = 50;
    static int LAPSE = 1000;
}

// PAUSA
namespace PAUSE {
    static std::string MSG = "PAUSA";
    static int TEXT_SIZE = 50;
}

// SCORE
namespace SCORE {
    static int TAM_TEXTO = 40;
    static sf::Vector2f POS(0, ALTO - TAM_TEXTO);
}

// TECLADO
namespace KEY {
    static std::vector <int> UP = {sf::Keyboard::Up, sf::Keyboard::W};
    static std::vector <int> DOWN = {sf::Keyboard::Down, sf::Keyboard::S};
    static std::vector <int> LEFT = {sf::Keyboard::Left, sf::Keyboard::D};
    static std::vector <int> RIGHT = {sf::Keyboard::Right, sf::Keyboard::A};
    static std::vector <int> ATTACK = {sf::Keyboard::Space};
    static int SPACE = sf::Keyboard::Space;
    static int EXIT = sf::Keyboard::Escape;
    static int PAUSE = sf::Keyboard::P;
    static int ENTER = sf::Keyboard::Return;
}

// ESTADOS EN EL JUEGO
enum class Estado {
    PERDIO,
    JUGANDO,
    INICIO,
    SALIDA
};

// Frames per second
static int FRAMES = 60;

// up, left, down, right vector directions
static std::vector <int> dx = {0, -1, 0, 1};
static std::vector <int> dy = {-1, 0, 1, 0};

// JUGADOR
namespace JUGADOR{
    static float RADIO = 40.f;
    static sf::Vector2f posicion = {100.f, 100.f};
    static float movVelocX = ANCHO * 0.015F / FRAMES;
    static float movVelocY = ANCHO * 0.015F / FRAMES;
}

// Directions
namespace DIR {
    static int UNCHANGED = -2;
    static int NOMOVE = -1;
    static int UP = 0;
    static int LEFT = 1;
    static int DOWN = 2;
    static int RIGHT = 3;
}

// Enemy 01
namespace E01 {
    static int score = 50;
    static float movVelocY = ANCHO * 0.015f / FRAMES;
    static float radius = 30.f;
    static sf::Color color = sf::Color::Green;
    static double d = E01::radius * 2.5f;
    static double x = ANCHO;
    static double y = ALTO / 2.f;
    static int nEnemies = 5;
    static std::vector <std::pair <float, float>> positions = {
            {0, 0},
            {d, -d}, {d, d},
            {2 * d, -2 * d}, {2 * d, 2 * d}
    };
    static float frec = 0.5;
    static int cnt = FRAMES * 50;
}

// Terrain
namespace Start {
    static int N_STARTS = ANCHO * ALTO / 5000;
    static float radius = 0.7f;
    static float var = 0.3f;
    static sf::Color color = sf::Color::White;
    static float xVel = ANCHO * 0.012f / FRAMES;
    static float yVel = ALTO * 0.0001f / FRAMES;
}

// Bullet
namespace BalaConfig {
    static sf::Vector2f dimensiones(35.f, 15.f);
    static sf::Color color = sf::Color::Yellow;
    static float dx = 0.3f;
}

#endif //PROYECTOPOO2_CONFIG_H
