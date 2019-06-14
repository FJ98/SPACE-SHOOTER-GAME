// Created by felix on 6/1/2019.
#include "Game.h"

int ENEMY_TIME_MAX = 20, CURRENT_ENEMY_TIME = 0, ENEMY_COUNTER = 0;
string T_PLAYER = "./images/nave2.png", T_BULLET = "./images/bala2.png",
        T_ENEMY = "./images/enemigo02.png", T_FONT="./fonts/arial.ttf",
        MUSIC_BG = "./sound/background-music.wav";
enum enem{enemy1,enemy2};
int winScore = 100;

Game::Game(sf::RenderWindow *window) {
    this->window = window;
    this->window->setFramerateLimit(60);
    this->score = 0;
    
    // Init fonts
    cargar(this->font,T_FONT);

    // Init Textures
    cargar(this->playerTexture, T_PLAYER);
    cargar(this->bulletTexture, T_BULLET);
    cargar(this->enemyTexture, T_ENEMY);

    //Init Player
    this->players.push_back(Player(&playerTexture, &bulletTexture)); // Jugador1

    //this->players.push_back(Player(&playerTexture, &bulletTexture,sf::Keyboard::I,
    //        sf::Keyboard::K, sf::Keyboard::J,sf::Keyboard::L, sf::Keyboard::M));// Jugador2

    //Init UI
    this->initUI();

    //Init music
    cargar(this->music, MUSIC_BG);
    music.play();
    music.setLoop(true);
}

Game::~Game() {

}
void Game::initUI(){
    sf::Text tempText;
    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Text youWinText;
    
    for (int i = 0; i < this->players.size(); ++i) {
        // Init followText
        tempText.setFont(font);
        tempText.setCharacterSize(14);
        tempText.setFillColor(sf::Color::White);
        tempText.setString(std::to_string(i));

        this->followPlayerTexts.push_back(sf::Text(tempText));
    }
    
    // Init static Text
    scoreText.setFont(font);
    scoreText.setCharacterSize(14);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("Score: ");
    this->staticPlayerTexts.push_back(sf::Text(scoreText));

    // GAME OVER TEXT
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(200.f, 200.f);
    gameOverText.setString("GAME OVER");
    this->gameOverText = gameOverText;

    // YOU WIN TEXT
    youWinText.setFont(font);
    youWinText.setCharacterSize(40);
    youWinText.setFillColor(sf::Color::Green);
    youWinText.setPosition(300.f, 300.f);
    youWinText.setString("YOU WIN");
    this->youWinText = youWinText;
}
void Game::updateUI() {
    for (int i = 0; i < this->followPlayerTexts.size(); ++i) {
        this->followPlayerTexts[i].setPosition(this->players[i].getPosition().x, this->players[i].getPosition().y - 20.0f);
        this->followPlayerTexts[i].setString(std::to_string(i) +
                                             "\t\t" + this->players[i].getHpAsString());
    }
    for (int i = 0; i < this->staticPlayerTexts.size(); ++i) {
        this->staticPlayerTexts[i].setString("Score: " + std::to_string(this->score));
    }
}

void Game::CombatUpdate() {
    // windows bordes
}

void Game::update() {
    if((this->players[0].getHp() > 0) && (this->score < winScore)){
        enemyupdate();
        playerupdate();
    } else {
        this->music.pause();
    }
}

void Game::enemyupdate(){
    CURRENT_ENEMY_TIME++;
    if(CURRENT_ENEMY_TIME == ENEMY_TIME_MAX){
        // Hacer que aprezcan enemigos cada cierto tiempo
        this->enemies.push_back(Enemy(&enemyTexture,
                this->window->getSize(),
                Vector2f(this->window->getSize().x,(rand() %10) * 100),
                Vector2f(-1.0f,0.0f),enemy1 , 10));
        CURRENT_ENEMY_TIME = 0; // Reset enemy timer appear
    }

    for(int i=0; i < enemies.size(); ++i){
        this->enemies[i].update(this->window->getSize());
        if(this->enemies[i].getPosition().x < 0){
            ENEMY_COUNTER++;
            this->enemies.erase(this->enemies.begin() + i);
        }
        if(this->enemies[i].getHP() == 0){
            this->score += this->enemies[i].getHPMax();
            this->enemies.erase(this->enemies.begin()+i);
        }
    }
}

void Game::playerupdate(){
    for (int i = 0; i < players.size(); ++i) {
        //
        this->players[i].update(this->window->getSize());

        // Colision nave con enemigo
        for(int j=0; j<enemies.size(); ++j) {
            if (players[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                enemies.erase(enemies.begin() + j); // Se borra el enemigo al chocar con la nave
                players[i].takedamage(); // La nave recibe dano al chocar con la el enemigo
            }
        }

        // Bala update
        for (int k = 0; k < this->players[i].getBulltes().size(); ++k) {

            this->players[i].getBulltes()[k].update(); // Permite el movimiento de las balas

            // Bala desaparece al chocar con el borde de la ventana
            if(players[i].getBulltes()[k].getPosition().x > window->getSize().x){
                players[i].getBulltes().erase(players[i].getBulltes().begin() + k);
            }
            // Colision balas de la nave con enemigo
            for(int j=0;j<enemies.size();++j){
                if(this->players[i].getBulltes()[k].getGlobalBounds().intersects(enemies[j].getGlobalBounds()) ){
                    enemies[j].takeDamage(10); // Enemigo recibe dano al chocar con la bala
                    players[i].getBulltes().erase(players[i].getBulltes().begin() + k); // Enemigo desaparece al chocar con la bala
                }
            }
        }

        // UI UPDATE
        this->updateUI();
        this->controlBoundsNave(); // Controlar que la nave no se salga de los bordes la ventana
        //cout<<players[i].getBulltes().size()<<endl;
    }
}

void Game::drawUI(){
    // Draw texto que sigue al jugador
    for (int i = 0; i < this->followPlayerTexts.size(); ++i) {
        this->window->draw(this->followPlayerTexts[i]);
    }
    // Draw texto estatico (ejemplo: el Score)
    for (int i = 0; i < this->staticPlayerTexts.size(); ++i) {
        this->window->draw(this->staticPlayerTexts[i]);
    }
    // Draw Game over
    if(this->players[0].getHp() <= 0)
        this->window->draw(gameOverText);
    // Draw You Win
    if(this->score >= winScore)
        this->window->draw(youWinText);
}

void Game::draw() {
    window->clear();
    // Dibujar al jugador
    for (int i = 0; i < this->players.size(); ++i) {
        this->players[i].draw(*this->window);
    }
    // Dibujar al enemigo
    for(int i=0;i<this->enemies.size();++i){
        this->enemies[i].draw(*this->window);
    }
    this->drawUI(); // Dibujar todos los textos (Interfaz Grafica)

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
