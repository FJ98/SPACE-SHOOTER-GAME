// Created by felix on 6/1/2019.
#include "Game.h"

Game::Game(sf::RenderWindow *window) {
    this->window = window;
    this->window->setFramerateLimit(60);

    // Init fonts
    this->font.loadFromFile("./fonts/arial.ttf");

    // Init Textures
    this->playerTexture.loadFromFile("./images/nave2.png");
    this->bulletTexture.loadFromFile("./images/bala2.png");

    //Init Player
    this->players.push_back(Player(&playerTexture, &bulletTexture)); // Jugador1
    //this->players.push_back(Player(&playerTexture, &bulletTexture,sf::Keyboard::I,
    //        sf::Keyboard::K, sf::Keyboard::J,sf::Keyboard::L, sf::Keyboard::M));// Jugador2
    //Init UI
    this->initUI();
}

Game::~Game() {

}
void Game::initUI(){
    sf::Text tempText;
    for (int i = 0; i < this->players.size(); ++i) {
        // Init followText
        tempText.setFont(font);
        tempText.setCharacterSize(14);
        tempText.setFillColor(sf::Color::White);
        tempText.setString(std::to_string(i));

        this->followPlayerTexts.push_back(sf::Text(tempText));

        // Init static Text
        tempText.setFont(font);
        tempText.setCharacterSize(14);
        tempText.setFillColor(sf::Color::White);
        tempText.setString("HOLA!");

        this->staticPlayerTexts.push_back(sf::Text(tempText));
    }
}
void Game::updateUI() {
    for (int i = 0; i < this->followPlayerTexts.size(); ++i) {
        this->followPlayerTexts[i].setPosition(this->players[i].getPosition().x, this->players[i].getPosition().y - 20.0f);
        this->followPlayerTexts[i].setString(std::to_string(i) +
                                             "\t\t" + this->players[i].getHpAsString());
    }
    for (int i = 0; i < this->staticPlayerTexts.size(); ++i) {
    }
}

void Game::CombatUpdate() {
    // windows bordes
}

void Game::update() {
    for (int i = 0; i < players.size(); ++i) {
        // PLAYERS UPDATE
        this->players[i].update(this->window->getSize());

        // Bala update
        for (int k = 0; k < this->players[i].getBulltes().size(); ++k) {

            this->players[i].getBulltes()[k].update();

            // Bordes ventana para las balas revisar y modificar
            //if (this->players[i].getBulltes()[k].getPosition().y <= 0) {
            //    this->players[i].getBulltes().erase(this->players[k].getBulltes().begin() + k);
            //    break;// BREAK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //}
        }

        // UI UPDATE
        this->updateUI();

    }
}

void Game::drawUI(){
    for (int i = 0; i < this->followPlayerTexts.size(); ++i) {
        this->window->draw(this->followPlayerTexts[i]);
    }
    for (int i = 0; i < this->staticPlayerTexts.size(); ++i) {
        this->window->draw(this->staticPlayerTexts[i]);
    }
}


void Game::draw() {
    window->clear();

    for (int i = 0; i < this->players.size(); ++i) {
        this->players[i].draw(*this->window);
    }

    this->drawUI();


    window->display();
}

