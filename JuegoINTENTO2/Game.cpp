// Created by felix on 6/1/2019.
#include "Game.h"

int ENEMY_TIME_MAX=30; int CURRENT_ENEMY_TIME=0; int ENEMY_COUNTER=0;
enum textures{PLAYER, BULLET, ENEMY01, ENEMY02};
enum enem{enemy1,enemy2};


Game::Game(sf::RenderWindow *window) {
    this->window = window;
    this->window->setFramerateLimit(60);

    // Init fonts
    this->font.loadFromFile("./fonts/arial.ttf");

    // Init Textures
    this->playerTexture.loadFromFile("./images/nave2.png");
    this->bulletTexture.loadFromFile("./images/bala2.png");
    this->enemyTexture.loadFromFile("./images/enemigo02.png");

    //Init Player
    this->players.push_back(Player(&playerTexture, &bulletTexture)); // Jugador1

    //this->players.push_back(Player(&playerTexture, &bulletTexture,sf::Keyboard::I,
    //        sf::Keyboard::K, sf::Keyboard::J,sf::Keyboard::L, sf::Keyboard::M));// Jugador2

    // Init Enemy

    //Init UI
    this->initUI();

    //Init music
    cargarMusica(this->music, "./sound/background-music.wav");
    music.play();
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

    enemyupdate();
    playerupdate();


    //cout<<enemies.size()<<endl;
}

void Game::enemyupdate(){
    CURRENT_ENEMY_TIME++;
    if(CURRENT_ENEMY_TIME==ENEMY_TIME_MAX){
        this->enemies.push_back(Enemy(&enemyTexture,
                this->window->getSize(),
                Vector2f(1700.0f,(rand() %10) * 100),
                Vector2f(-1.0f,0.0f),enemy1 , 10));
        CURRENT_ENEMY_TIME=0;
    }
    for(int i=0;i<enemies.size();++i){
        this->enemies[i].update(this->window->getSize());
        if(this->enemies[i].getPosition().x<-100){
            ENEMY_COUNTER++;
            enemies.erase(enemies.begin()+i);

        }
        if(enemies[i].getHP()==0){
            enemies.erase(enemies.begin()+i);
        }
    }
}

void Game::playerupdate(){
    for (int i = 0; i < players.size(); ++i) {
        // PLAYERS UPDATE
        this->players[i].update(this->window->getSize());


        for(int j=0;j<enemies.size();++j) {

            if (players[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                enemies.erase(enemies.begin() + j);
                players[i].takedamage();
            }
        }

        // Bala update
        for (int k = 0; k < this->players[i].getBulltes().size(); ++k) {

            this->players[i].getBulltes()[k].update();

            if(players[i].getBulltes()[k].getPosition().x>1700){
                players[i].getBulltes().erase(players[i].getBulltes().begin()+k);
            }



            for(int j=0;j<enemies.size();++j){


                if(this->players[i].getBulltes()[k].getGlobalBounds().intersects(enemies[j].getGlobalBounds()) ){
                    enemies[j].takeDamage(10);
                    players[i].getBulltes().erase(players[i].getBulltes().begin()+k);

                }




            }
            // Bordes ventana para las balas revisar y modificar
            //if (this->players[i].getBulltes()[k].getPosition().y <= 0) {
            //    this->players[i].getBulltes().erase(this->players[k].getBulltes().begin() + k);
            //    break;// BREAK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //}
        }

        // UI UPDATE
        this->updateUI();
        this->controlBoundsNave();
        //cout<<players[i].getBulltes().size()<<endl;
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
    for(int i=0;i<this->enemies.size();++i){
        this->enemies[i].draw(*this->window);
    }
    this->drawUI();


    window->display();
}

void Game::controlBoundsNave() {
    for (int i = 0; i < players.size() ; ++i) {
        if (this->players[i].getSprite().getPosition().x <= 0) { this->players[i].getSprite().setPosition(0.0f, this->players[i].getSprite().getPosition().y); } //borde izquierdo
        if (this->players[i].getSprite().getPosition().x >= window->getSize().x - this->players[i].getSprite().getGlobalBounds().width) { //borde derecho
            this->players[i].getSprite().setPosition(window->getSize().x - this->players[i].getSprite().getGlobalBounds().width, this->players[i].getSprite().getPosition().y);
        }
        if (this->players[i].getSprite().getPosition().y <= 0) { this->players[i].getSprite().setPosition(this->players[i].getSprite().getPosition().x, 0.0f); } //borde de arriba
        if (this->players[i].getSprite().getPosition().y >= window->getSize().y - this->players[i].getSprite().getGlobalBounds().height) { //borde de abajo
            this->players[i].getSprite().setPosition(this->players[i].getSprite().getPosition().x, window->getSize().y - this->players[i].getSprite().getGlobalBounds().height);
        }
    }
}

void Game::cargarMusica (sf::Music& target, const std::string& path) {
    target.openFromFile(path);
}
