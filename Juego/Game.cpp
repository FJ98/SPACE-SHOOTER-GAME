// Created by felix on 6/1/2019.
#include "Game.h"
enum textures{PLAYER, BULLET, ENEMY01, ENEMY02};

static std::string FONT_PATH = "./fonts/arial.ttf";
static std::string NAVE_PATH = "./images/nave2.png";
static std::string ENEMY01_PATH = "./images/enemigo01.png";
static std::string BALA_PATH = "./images/bala2.png";
static std::string BACKGROUND_MUSIC_PATH = "./sound/background-music.wav";
static int ENEMY_APPEAR_TIME = 20;
//const int WIDTH = 1600, HEIGHT = 900;
Game::Game(){
    //sf::RenderWindow &w =  (sf::RenderWindow(sf::VideoMode(WIDTH,HEIGHT),"Juego",sf::Style::Default)) ;
    //this->window = w;
}
Game::Game(sf::RenderWindow *window) {
    this->window = window;
    this->window->setFramerateLimit(60);

    // Init fonts
    this->font.loadFromFile("./fonts/arial.ttf");

    // Init Textures
    cargar(this->playerTexture, NAVE_PATH);
    cargar(this->bulletTexture, "./images/bala2.png");
    this->enemyTexture.loadFromFile("./images/enemigo01.png");

    //Init Player
    this->players.push_back(Player(&playerTexture, &bulletTexture)); // Jugador1
    //this->players.push_back(Player(&playerTexture, &bulletTexture,sf::Keyboard::I,
    //        sf::Keyboard::K, sf::Keyboard::J,sf::Keyboard::L, sf::Keyboard::M));// Jugador2

    // Init Enemy
    Enemy e1(&this->enemyTexture,
             this->window->getSize(),
             sf::Vector2f(0.0f,0.0f),
             sf::Vector2f(-1.0f,0.0f),
             sf::Vector2f(0.04f,0.04f),
    0, rand()%3+1, 3, 1);
    this->enemies.push_back(e1);
    this->enemyAppearTimerMax = ENEMY_APPEAR_TIME;
    this->enemyAppearTimer = this->enemyAppearTimerMax;

    // Init MainMenu


    //Init UI
    this->initUI();

    //Init Musica
    cargarMusica(music, "./sound/background-music.wav");
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
    // Actualizando temporizadores
    if (enemyAppearTimer < enemyAppearTimerMax) {enemyAppearTimer++;}

    // APARECEN ENEMIGOS!
    if (enemyAppearTimer > enemyAppearTimerMax) {
        this->enemies.push_back(Enemy(&this->enemyTexture,
                this->window->getSize(),sf::Vector2f(0.0f,0.0f),
                sf::Vector2f(-1.0f,0.0f),sf::Vector2f(0.04f,0.04f),
                0, rand()%3+1, 3, 1));
        enemyAppearTimer = 0;
    }

    for (int i = 0; i < players.size(); ++i) {
        //bool enemyRemoved = false, bulletRemoved = false;
        // PLAYERS UPDATE
        this->players[i].update(this->window->getSize());
        // Bala update
        for (int k = 0; k < this->players[i].getBulltes().size(); ++k) {
            this->players[i].getBulltes()[k].update();
            // Checkear Colision Enemigo
            for (int j = 0; j < this->enemies.size(); ++j) {
                // Se elimina bala y enemigos al chocarse
                if ( this->players[i].getBulltes()[k].getGlobalBounds().intersects(this->enemies[j].getGlobalBounds()) ){
                    this->players[i].getBulltes().erase(this->players[i].getBulltes().begin() + k);
                    this->enemies.erase(this->enemies.begin() + j);
                    return; // RETURN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                }
            }
            // Bordes ventana para que las balas desaparezcan un poco antes de llegar al borde la ventana
            if (this->players[i].getBulltes()[k].getPosition().x > this->window->getSize().x - 100) {
                this->players[i].getBulltes().erase(this->players[k].getBulltes().begin() + i);
                return; // RETURN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }
        }
        /*//ENEMY UPDATE
        for (int j = 0; j < this->enemies.size() && !enemyRemoved; ++j) {//this->enemies[j].update();// Enemigo y bala se eliminan al chocar entre si
            if ( this->players[i].getSprite().getGlobalBounds().intersects(this->enemies[j].getGlobalBounds()) ){this->enemies.erase(this->enemies.begin() + j);enemyRemoved = true; // BREAK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
            // Enemigo se elimina antes de chocar el borde de la pantalla
            if (this->enemies[j].getPosition().x < 0 + this->enemies[j].getGlobalBounds().width) {this->enemies.erase(this->enemies.begin() + j);enemyRemoved = true; // BREAK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
        }*/
    }
    // ENEMIES UPDATE
    for (int j = 0; j < this->enemies.size(); ++j) {
        this->enemies[j].update();

        if (this->enemies[j].getPosition().x < 0 - this->enemies[j].getGlobalBounds().width) {
            this->enemies.erase(this->enemies.begin() + j);
            break; //BREAK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }
    // UI UPDATE
    this->updateUI();
    this->controlBoundsNave();

    /*for (int i = 0; i < this->players.size(); ++i) {for (int j = 0; j < this->enemies.size(); ++j) {this->enemies[j].update();if (this->enemies[j].getPosition().x < 0 + this->enemies[j].getGlobalBounds().width) {this->enemies.erase(this->enemies.begin() + j);return;}if ( this->players[i].getSprite().getGlobalBounds().intersects(this->enemies[j].getGlobalBounds()) ){this->enemies.erase(this->enemies.begin() + j);return;}}}*/// ENEMIES UPDATE
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

    for (int j = 0; j < this->enemies.size() ; ++j) {
        this->enemies[j].draw(*this->window);
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


void Game::cargarMusica (sf::Music& target, std::string path) {
    target.openFromFile(path);
}
