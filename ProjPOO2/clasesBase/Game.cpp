// Created by felix on 5/29/2019.
#include "Game.h"

Game *Game::instance = nullptr;


void Game::run() {

}

void Game::switchScene(BaseScene *scene) {

}

Game &Game::getInstance() {
    if(!instance){
        instance = new Game();
    }
    return *instance;
}

Game &Game::create(const sf::VideoMode &videoMode, BaseScene *scene, const sf::String &name) {
    return getInstance();
}

void Game::processEvents() {

}

void Game::update() {

}

void Game::draw() {

}



Game::Game(sf::Vector2f resolution, sf::String& titulo) {
    window1 = new sf::RenderWindow(sf::VideoMode(static_cast<int>(resolution.x), static_cast<int>(resolution.y)), titulo);
    window1->setFramerateLimit(60);

    fps = 1/60.0f;

    clock1 = new sf::Clock();
    time1 = new sf::Time();
    time2 = 0.0f;

    bala = new Bala();
    //bala2 = new Bala();
    //bala->getSprite().setPosition(300,300);
    //bala2->getSprite().setPosition(300,300);

}

void Game::gameLoop() {
    while(window1->isOpen()){
        sf::Event event{};
        while (window1->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window1->close();
        }

        *time1 = clock1->getElapsedTime();
        if ( (time1->asSeconds()) > (time2 + fps) ) {

            time2 = time1->asSeconds();

            window1->clear();
            bala->move(time2);
            //bala2->move(time2);

            window1->draw(bala->getSprite());
            //bala2->getSprite().setPosition(150,150);
            //window1->draw(bala2->getSprite());
            window1->display();
        }

    }
}
