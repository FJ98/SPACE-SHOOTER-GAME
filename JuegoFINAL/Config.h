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
#include <algorithm>
#include "Funciones.h"
using namespace sf; using namespace std;

#define all(X) begin(X), end(X)

static int WIDTH = 1600, HEIGHT = 930;

static auto T_MENU = "./images/menu_background.jpg";
static auto T_PLAYER = "./images/nave2.png";
static auto T_BULLET = "./images/bala2.png";
static auto T_ENEMY = "./images/enemigo02.png";
static auto T_FONT = "./fonts/arial.ttf";
static auto MUSIC_BG = "./sound/background-music.wav";
static auto SND_CHOCK = "./sound/choque.ogg";

enum enem{enemy1};
namespace GameConfig{
    static int WIN_SCORE = 100;
    static int ENEMY_TIME_MAX = 20,
    CURRENT_ENEMY_TIME = 0, ENEMY_COUNTER = 0;
}

namespace PlayerConfig{
    const float NAVE_SPEED = 1.0f, NAVE_SCALE = 0.07f,
            NAVE_MAX_VEL = 25.0f, NAVE_ACCELERATION = 0.3f, NAVE_STABLE = 0.07f;
    const int SHOOT_TIMER_MAX = 15/*, DAMAGE_TIMER_MAX = 10*/;
    static auto MUSIC_SHOOT = "./sound/shoot.wav";
}

namespace EnemyConfig{
    const float ENEMY_SPEED = 12.0f, ENEMY_SCALE = 0.03f;
}

namespace Bala{
    const float BALA_DIRX = 1.0f,
    BALA_DIRY = 0.0f, BALA_INIT_VEL = 2.0f,
    BALA_MAX_VEL = 50.0f, BALA_ACCEL = 1.0f;
}

enum windows{menu,game};
namespace MenuScale{
    const float MENU_SCALE_X = 3.0f, MENU_SCALE_Y = 2.0f;
    const float MENU_NAVE_SCALE = 0.05f;
    const float MENU_NAVE_DOWN = 830.0f;
    const float MENU_NAVE_UP = 650.0f;
}


#endif //FINAL0_CONFIG_H
