// Created by felix on 5/30/2019.
#include "EscenaInicio.h"
#include "clasesBase/Game.h"
#include <iostream>
#include <sstream>
#include "EscenaJuego.h"
#include "Global.h"
EscenaInicio::EscenaInicio() {
    if(!titleFont.loadFromFile("./fonts/arial.ttf")){
        cerr<<"ERROR: no se encontro la fuente "<<"./fonts/arial.ttf"<<endl;
    }
    titleText.setFont(titleFont);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("Ejemplo SFML");
    titleText.setCharacterSize(120);
    // centra el texto
    titleText.setPosition(sf::Vector2f((640-titleText.getLocalBounds().width)/2.0, 0));

    scoreText.setFont(titleFont);
    scoreText.setFillColor(sf::Color::White);
    stringstream ss;
    ss<<"HIGH SCORE: "<<Global::highScore;
    scoreText.setString(ss.str());
    scoreText.setCharacterSize(40);
    scoreText.setPosition(sf::Vector2f((640-scoreText.getLocalBounds().width)/2.0, 150));

    pressStartText.setFont(titleFont);
    pressStartText.setFillColor(sf::Color::White);
    pressStartText.setString("Presione ENTER para comenzar");
    pressStartText.setCharacterSize(40);
    pressStartText.setPosition(sf::Vector2f((640-pressStartText.getLocalBounds().width)/2.0, 250));
}

void EscenaInicio::update(float elapsed) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        Game::getInstance().switchScene(new EscenaJuego());
    }
}

void EscenaInicio::draw(sf::RenderWindow &w) {
    BaseScene::draw(w);
    w.draw(titleText);
    w.draw(scoreText);
    w.draw(pressStartText);
}
