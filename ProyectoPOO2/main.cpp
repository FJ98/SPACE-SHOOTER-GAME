#include <SFML/Graphics.hpp>
#include "Juego.h"
#include <exception>
#include <iostream>

sf::RenderWindow crearVentanta();
void controlarTeclado(sf::RectangleShape& player);
void controlarMouse(sf::RectangleShape& player, sf::RenderWindow& window);
int WIDTH = 500;
int HEIGHT = 500;
static float PLAYER_WIDTH = 100.0f;
static float PLAYER_HEIGHT = 100.0f;
static float PLAYER_X_POSITION = 200.0f;
static float PLAYER_Y_POSITION = 200.0f;
static float LEFT = -10.0f;
static float RIGHT = 10.0f;
static float UP = -10.0f;
static float DOWN = 10.0f;

int main(){
    std::cout << "Hello World!" << std::endl;

    crearVentanta();

    /* sf::RenderWindow window(sf::VideoMode(800, 300), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }*/

    return 0;
}

sf::RenderWindow crearVentanta(){
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "FelixSolano",sf::Style::Default);
    sf::RectangleShape player(sf::Vector2f(PLAYER_WIDTH,PLAYER_HEIGHT));
    player.setPosition(PLAYER_X_POSITION, PLAYER_Y_POSITION);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./images/galagaNave.png");
    player.setTexture(&playerTexture);
    while(window.isOpen()){
        sf::Event evnt{};
        while(window.pollEvent(evnt)){
            switch (evnt.type){
                case sf::Event::Closed :
                    window.close();
                    break;
            }
            controlarTeclado(player);
            //controlarMouse(player, window);
            window.clear();
            window.draw(player);
            window.display();
        }
    }
}

void controlarTeclado(sf::RectangleShape& player){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(LEFT, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(RIGHT, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.move(0.0f, UP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(0.0f, DOWN);
            }
}

void controlarMouse(sf::RectangleShape& player, sf::RenderWindow& window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    player.setOrigin(PLAYER_WIDTH/2, PLAYER_HEIGHT/2);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

}




/*
 sf::RenderWindow crearVentanta(){
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "FelixSolano",sf::Style::Default);
    sf::RectangleShape player(sf::Vector2f(PLAYER_WIDTH,PLAYER_HEIGHT));
    player.setFillColor(sf::Color::Blue);
    while(window.isOpen()){
        sf::Event evnt{};
        while(window.pollEvent(evnt)){
            switch (evnt.type){
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::Resized :
                    std::cout << "New window width: " << evnt.size.width << " New window height: " <<evnt.size.height << std::endl;
                    //WIDTH = evnt.size.width;  //HEIGHT = evnt.size.width;
                    break;
                case sf::Event::TextEntered :
                    if (evnt.text.unicode < 128) {
                        std::cout << static_cast<char>(evnt.text.unicode);
                    }
                    break;
            }
            //controlarTeclado(player);
            controlarMouse(player, window);
            window.clear();
            window.draw(player);
            window.display();
        }
    }
}
 */