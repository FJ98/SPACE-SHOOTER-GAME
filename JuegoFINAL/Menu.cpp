// Created by luis0 on 15/06/2019.
#include "Menu.h"
static auto T_MENU = "./images/menu_background.jpg";

Menu::Menu(){
    this->texture_menu.loadFromFile(T_MENU);
    this->texture_eleccion.loadFromFile(T_PLAYER);
    this->sprite_menu.setTexture(this->texture_menu);
    this->sprite_menu.setScale(MenuScale::MENU_SCALE_X,MenuScale::MENU_SCALE_Y);
    this->sprite_eleccion.setTexture(this->texture_eleccion);
    this->sprite_eleccion.setScale(MenuScale::MENU_NAVE_SCALE,MenuScale::MENU_NAVE_SCALE);
    this->sprite_eleccion.setPosition(600.0f,MenuScale::MENU_NAVE_UP);
}

void Menu::draw(sf::RenderTarget &target){
    target.draw(this->sprite_menu);
    target.draw(this->sprite_eleccion);
}

void Menu::update(bool &exit){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite_eleccion.getPosition().y != MenuScale::MENU_NAVE_DOWN){
        this->sprite_eleccion.setPosition(600.0f,MenuScale::MENU_NAVE_DOWN);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite_eleccion.getPosition().y != MenuScale::MENU_NAVE_UP){
        this->sprite_eleccion.setPosition(600.0f,MenuScale::MENU_NAVE_UP);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sprite_eleccion.getPosition().y == MenuScale::MENU_NAVE_UP){
        this->WINDOW = game;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sprite_eleccion.getPosition().y == MenuScale::MENU_NAVE_DOWN){
        exit=true;
    }
}