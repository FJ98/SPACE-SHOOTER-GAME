// Created by felix on 5/30/2019.
#include "EscenaJuego.h"
#include "clasesBase/Game.h"
#include "EscenaInicio.h"
#include <iostream>
#include <sstream>
#include "Global.h"

void EscenaJuego::createNewBall(float minVel) {
    Enemy *b = new Enemy();
    enemigos.push_back(b);
    add(b);
}

EscenaJuego::EscenaJuego() {
    player = new Player(sf::Vector2f(304, 306));
    add(player);

    minVel = 150;
    createNewBall(minVel);
    timeToNewBall.restart();
    if(!fontScoreText.loadFromFile("./fonts/arial.ttf")){
        cerr<<"ERROR: no se encontro la fuente " << "./fonts/arial.ttf" << endl;
    }

    texBackground.loadFromFile("images/galagaLogo.png");
    spBackground.setTexture(texBackground);

    score = 0;
    scoreText.setFont(fontScoreText);
    scoreText.setFillColor(sf::Color::White);
}

void EscenaJuego::update(float elapsed) {
    // actualiza al personaje
    BaseScene::update(elapsed);

    // crear nueva pelota
    if(timeToNewBall.getElapsedTime().asSeconds()>10){
        minVel += 50;
        createNewBall(minVel);
        timeToNewBall.restart();
    }

    // revisa colisiones entre el personaje y las pelotas
    for(const auto &item: enemigos){
        if(player->collidesWithBall(item)){
            if(score > Global::highScore){
                Global::highScore = score;
            }
            Game::getInstance().switchScene(new EscenaInicio());
        }
    }

    // actualiza el puntaje
    score += elapsed;
    stringstream tmp;
    tmp << "SCORE: "<< int(score);
    scoreText.setString(tmp.str());
}

void EscenaJuego::draw(sf::RenderWindow &w) {
    BaseScene::draw(w);
}
