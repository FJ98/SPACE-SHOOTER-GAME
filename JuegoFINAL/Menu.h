// Created by luis0 on 15/06/2019.
#ifndef SFMLAPP_MENU_H
#define SFMLAPP_MENU_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Config.h"


class Menu {
    bool exit = false;
    sf::Texture texture_menu, texture_eleccion;
    sf::Sprite sprite_menu, sprite_eleccion;

public:
    Menu();
    void draw( sf::RenderTarget &target );
    void update( bool & );
    int get_WINDOW(){ return WINDOW; }
    int WINDOW = menu;
};


#endif //SFMLAPP_MENU_H
