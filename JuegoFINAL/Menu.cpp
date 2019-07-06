// Created by felix on 15/06/2019.
#include "Menu.h"

Menu::Menu(){
    cargar(this->texture_menu, T_MENU); // Cargar imagen menu
    cargar(this->texture_eleccion, T_PLAYER); // cargar imgagen nave
    this->sprite_menu.setTexture(this->texture_menu); // setear textura menu
    this->sprite_eleccion.setTexture(this->texture_eleccion); // setear textura nave
    this->sprite_menu.setScale(MenuScale::MENU_SCALE_X,MenuScale::MENU_SCALE_Y); // setear escala menu
    this->sprite_eleccion.setScale(MenuScale::MENU_NAVE_SCALE,MenuScale::MENU_NAVE_SCALE); //setear escala nave
    this->sprite_eleccion.setPosition(600.0f,MenuScale::MENU_NAVE_UP); // setear posicion nave
}

void Menu::draw(sf::RenderTarget &target){
    target.draw(this->sprite_menu); // Dibujar imagen menu
    target.draw(this->sprite_eleccion); // Dibujar imagen nave
}

void Menu::update(bool &_exit){
    // SUBIR EN LAS OPCIONES DE MENU
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite_eleccion.getPosition().y != MenuScale::MENU_NAVE_DOWN){
        this->sprite_eleccion.setPosition(600.0f,MenuScale::MENU_NAVE_DOWN);
    }
    // BAJAR EN LAS OPCIONES DE MENU
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite_eleccion.getPosition().y != MenuScale::MENU_NAVE_UP){
        this->sprite_eleccion.setPosition(600.0f,MenuScale::MENU_NAVE_UP);
    }
    // ENTRAR AL JUEGO DEPENDIENDO DE LA OPCION DE MENU QUE SE ELIJA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sprite_eleccion.getPosition().y == MenuScale::MENU_NAVE_UP){
        this->WINDOW = game;
    }
    // SALIR DEL JUEGO DEPENDIENDO DE LA OPCION DE MENU QUE SE ELIJA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sprite_eleccion.getPosition().y == MenuScale::MENU_NAVE_DOWN){
        _exit = true;
    }
}