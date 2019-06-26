// Created by felix on 6/1/2019.
#include "Game.h"

enum enem{enemy1};

Game::Game(sf::RenderWindow *window): mt{rd()}, score{0} {
    this->window = window;
    this->window->setFramerateLimit(60);
    // Init Textures
    cargar(this->playerTexture, T_PLAYER);
    cargar(this->bulletTexture, T_BULLET);
    cargar(this->enemyTexture, T_ENEMY);
    //Init Player
    this->players.emplace_back( Player(&playerTexture, &bulletTexture,
                                       {sf::Keyboard::W, sf::Keyboard::S,
                                        sf::Keyboard::A, sf::Keyboard::D,
                                        sf::Keyboard::Space}) ); // Player1
    //this->players.emplace_back( Player(&playerTexture, &bulletTexture,{sf::Keyboard::I,
    //        sf::Keyboard::K, sf::Keyboard::J,sf::Keyboard::L, sf::Keyboard::M}) );// Player2

    //Init UI (fonts)
    this->initUI();

    //Init music
    cargar(this->music, MUSIC_BG);
    music.play();
    music.setLoop(true);
}

Game::~Game() = default;

void Game::initUI(){
    sf::Text tempText; sf::Text scoreText;

    cargar(this->font,T_FONT);

    // Init followText
    for (int i = 0; i < this->players.size(); ++i) {
        confText(tempText, &this->font, 14, &this->followPlayerTexts);
    }
    // Init static Text
    confText(scoreText, &this->font, 14, &this->staticPlayerTexts);

    // GAME OVER TEXT
    confText(this->gameOverText, &this->font, 30, "GAME OVER",
     sf::Color::Red, {600.0f, 450.0f}, sf::Text::Bold);

    // YOU WIN TEXT
    confText(this->youWinText, &this->font, 40, "YOU WIN",
             sf::Color::Green, {600.0f, 450.0f}, sf::Text::Bold);
}
void Game::updateUI() {
    for (int i = 0; i < this->followPlayerTexts.size(); ++i) {
        this->followPlayerTexts[i].setPosition(this->players[i].getPosition().x, this->players[i].getPosition().y - 20.0f);
        this->followPlayerTexts[i].setString(std::to_string(i) +
                                             "\t\t" + this->players[i].getHpAsString());
    }
    for (auto & staticPlayerText : this->staticPlayerTexts) {
        staticPlayerText.setString("Score: " + std::to_string(this->score));
    }
}

void Game::update() {
    if((this->players[0].getHp() > 0) && (this->score < GameConfig::WIN_SCORE)){
        enemyUpdate();
        playerUpdate();
    } else {
        this->music.pause();
    }
}

void Game::enemyUpdate(){
    int ENEMY_COUNTER{0};
    EnemyConfig::CURRENT_ENEMY_TIME++;
    if(EnemyConfig::CURRENT_ENEMY_TIME == EnemyConfig::ENEMY_TIME_MAX){
        // Hacer que aprezcan enemigos cada cierto tiempo
        this->enemies.emplace_back( Enemy(&enemyTexture, /*this->window->getSize(),*/
                Vector2f(this->window->getSize().x,(this->mt() %10) * 100),
                enem::enemy1 , EnemyConfig::ENEMY_LIFE) );
        EnemyConfig::CURRENT_ENEMY_TIME = 0; // Reset enemy timer appear
    }

    for(int i=0; i < enemies.size(); ++i){
        this->enemies[i].update();
        if(this->enemies[i].getPosition().x < 0){
            ENEMY_COUNTER++;
            this->enemies.erase(this->enemies.begin() + i);
        }
        if(this->enemies[i].getHP() == 0){
            this->score += this->enemies[i].getHPMax();
            this->enemies.erase(this->enemies.begin() + i);
        }
    }
}

void Game::playerUpdate(){
    for (int i = 0; i < players.size(); ++i) {

        this->players[i].update();

        // Collision nave con enemy
        for(int j=0; j < enemies.size(); ++j) {
            if (players[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                enemies.erase(enemies.begin() + j); // Se borra el enemigo al chocar con la nave
                players[i].takeDamage(); // La nave recibe dano al chocar con la el enemigo
            }
        }

        // Bala update
        for (int k = 0; k < this->players[i].getBullets().size(); ++k) {

            this->players[i].getBullets()[k].update(); // Permite el movimiento de las balas

            // Bala desaparece al chocar con el borde de la ventana
            if(players[i].getBullets()[k].getPosition().x > window->getSize().x){
                players[i].getBullets().erase(players[i].getBullets().begin() + k);
            }
            // Colision balas de la nave con enemigo
            for(auto & enemie : enemies){
                if(this->players[i].getBullets()[k].getGlobalBounds().intersects(enemie.getGlobalBounds()) ){
                    enemie.takeDamage(10); // Enemigo recibe dano al chocar con la bala
                    players[i].getBullets().erase(players[i].getBullets().begin() + k); // Enemigo desaparece al chocar con la bala
                }
            }
        }

        // UI UPDATE
        this->updateUI();
        this->controlBoundsNave(); // Controlar que la nave no se salga de los bordes la ventana
    }
}

void Game::drawUI(){
    // Draw texto que sigue al jugador
    for (const auto & followPlayerText : this->followPlayerTexts) {
        this->window->draw(followPlayerText);
    }
    // Draw texto estatico (ejemplo: el Score)
    for (const auto & staticPlayerText : this->staticPlayerTexts) {
        this->window->draw(staticPlayerText);
    }
    // Draw Game over
    if(this->players[0].getHp() <= 0)
        this->window->draw(gameOverText);
    // Draw You Win
    if(this->score >= GameConfig::WIN_SCORE)
        this->window->draw(youWinText);
}

void Game::draw() {
    window->clear();
    // Dibujar al jugador
    for (auto & player : this->players) {
        player.draw(*this->window);
    }
    // Dibujar al enemigo
    for(auto & enemie : this->enemies){
        enemie.draw(*this->window);
    }
    this->drawUI(); // Dibujar todos los textos (Interfaz Grafica)

    window->display();
}

void Game::controlBoundsNave() {
    for (int i = 0; i < players.size() ; ++i) {
        if (this->players[i].getSprite().getPosition().x <= 0) { //borde izquierdo
            this->players[i].getSprite().setPosition(0.0f, this->players[i].getSprite().getPosition().y);
        }
        if (this->players[i].getSprite().getPosition().x >= window->getSize().x - this->players[i].getSprite().getGlobalBounds().width) { //borde derecho
            this->players[i].getSprite().setPosition(window->getSize().x - this->players[i].getSprite().getGlobalBounds().width, this->players[i].getSprite().getPosition().y);
        }
        if (this->players[i].getSprite().getPosition().y <= 0) { //borde de arriba
            this->players[i].getSprite().setPosition(this->players[i].getSprite().getPosition().x, 0.0f);
        }
        if (this->players[i].getSprite().getPosition().y >= window->getSize().y - this->players[i].getSprite().getGlobalBounds().height) { //borde de abajo
            this->players[i].getSprite().setPosition(this->players[i].getSprite().getPosition().x, window->getSize().y - this->players[i].getSprite().getGlobalBounds().height);
        }
    }
}