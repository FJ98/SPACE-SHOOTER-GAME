// Created by felix on 5/28/2019.
#include "Game.h"

Game::Game(sf::Vector2f resolution, sf::String& titulo) {
    window = new sf::RenderWindow(sf::VideoMode(static_cast<int>(resolution.x), static_cast<int>(resolution.y)), titulo);
    window->setFramerateLimit(60);

    fps = 1/60.0f;

    clock1 = new sf::Clock();
    time1 = new sf::Time();
    time2 = 0.0f;

    player1 = new Jug();

}

void Game::gameLoop() {
    while(window->isOpen()){
        sf::Event event{};
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window->close();
        }

        *time1 = clock1->getElapsedTime();
        if ( (time1->asSeconds()) > (time2 + fps) ) {

            time2 = time1->asSeconds();

            window->clear();
            player1->update(time2);
            window->draw(player1->getSprite());

            window->display();
        }
    }
}
