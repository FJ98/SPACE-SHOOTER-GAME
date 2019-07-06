#include "Game.h"

Game::Game(sf::RenderWindow *window) : mt{rd()}{
    this->window = window;
    this->window->setFramerateLimit(60);
    this->exit = false; this->score = 0;

    // INIT TIPO DE LETRA
    cargar(this->font,T_FONT);

    // INIT IMAGENES
    cargar(this->playerTexture, T_PLAYER);
    cargar(this->bulletTexture, T_BULLET);
    cargar(this->enemyTexture, T_ENEMY);

    // INIT PLAYER(S)
    this->players.push_back(Player(&playerTexture, &bulletTexture,
                                   {sf::Keyboard::W, sf::Keyboard::S,
                                    sf::Keyboard::A, sf::Keyboard::D,
                                    sf::Keyboard::Space}) ); // P1
    //this->players.push_back(Player(&playerTexture, &bulletTexture,sf::Keyboard::I,
    //        sf::Keyboard::K, sf::Keyboard::J,sf::Keyboard::L, sf::Keyboard::M));// Jugador2

    // INIT UI
    this->initUI();

    // INIT MUSIC
    cargar(this->music, MUSIC_BG);
    this->music.play();
    this->music.setLoop(true);

    // INIT SONIDO CHOQUE
    this->chockBuff.loadFromFile(SND_CHOCK);
}

void Game::initUI(){
    sf::Text tempText;
    sf::Text scoreText;
//    for_each(all(players), confText(
//            tempText, &this->font, 14, &this->followPlayerTexts
//            ));

    // INIT FOLLOW PLAYER TEXTS
    for (int i = 0; i < this->players.size(); ++i) {
        confText(tempText, &this->font, 14, &this->followPlayerTexts);
    }
    
    // INIT STATIC TEXT
    confText(scoreText, &this->font, 14, &this->staticPlayerTexts);

    // GAME OVER TEXT
    confText(this->gameOverText, &this->font, 60, "GAME OVER",
             sf::Color::Red, {650.0f, 350.0f}, sf::Text::Bold);

    // YOU WIN TEXT
    confText(this->youWinText, &this->font, 40, "YOU WIN",
             sf::Color::Green, {650.0f, 350.0f}, sf::Text::Bold);

    // RESTART TEXT
    confText(this->restartText, &this->font, 40, "Presiona R para restart",
             sf::Color::Green, {static_cast<float>(window->getSize().x)/2-200,
                                static_cast<float>(window->getSize().y)/2}
                                ,sf::Text::Bold);
//    restartText.setFont(font);
//    restartText.setCharacterSize(40);
//    restartText.setFillColor(sf::Color::Green);
//    restartText.setPosition(static_cast<float>(window->getSize().x)/2-200,
//                            static_cast<float>(window->getSize().y)/2);
//    restartText.setString("Presiona R para restart");

}
void Game::updateUI() {
    for (int i = 0; i < this->followPlayerTexts.size(); ++i) {
        this->followPlayerTexts[i].setPosition(this->players[i].getPosition().x, this->players[i].getPosition().y - 20.0f);
        this->followPlayerTexts[i].setString(std::to_string(i) +
                                             "\t\t" + this->players[i].getHpAsString());
    }
//    for (auto & staticPlayerText : this->staticPlayerTexts) {
//        staticPlayerText.setString("Score: " + std::to_string(this->score));
//    }
    // SCORE
    for_each (all(this->staticPlayerTexts),[&](sf::Text & staticPlayerText) {
        staticPlayerText.setString("Score: " + std::to_string(this->score));
    });

}

void Game::update() {
    if (wind.get_WINDOW()== menu){
        wind.update(this->exit);
    }
    if(wind.get_WINDOW() == game){
        if((this->players[0].getHP() > 0) && (this->score < GameConfig::WIN_SCORE)){
            enemyupdate();
            playerupdate();
        } else {
            this->music.pause();
        }
    }

}

void Game::enemyupdate(){
    // HACER QUE LOS ENEMIGOS APAREZCAN CADA CIERTO TIEMPO
    GameConfig::CURRENT_ENEMY_TIME++;
    if(GameConfig::CURRENT_ENEMY_TIME == GameConfig::ENEMY_TIME_MAX){
        this->enemies.emplace_back( Enemy(&enemyTexture,
                Vector2f(this->window->getSize().x,(this->mt() % 10) * 100),
                enemy1 , 10) );
        GameConfig::CURRENT_ENEMY_TIME = 0; // Reset enemy timer appear
    }

    //
    for(int i=0; i < enemies.size(); ++i){
        this->enemies[i].update(); // Para que cada enemigo se mueva
        if(this->enemies[i].getPosition().x < 0){ // Si llegan a borde de la ventana
            GameConfig::ENEMY_COUNTER++; // Para llevar un conteo de cada enemigo
            this->enemies.erase(this->enemies.begin() + i); // Se borra a cada enemigo
        }
        // ENEMIGOS RECIBEN DANOS
        if(this->enemies[i].getHP() == 0){ // SI LA VIDA DEL ENEMIGO LLEGA A 0
            this->score += this->enemies[i].getHPMax(); // SCORE AUMENTA EN RELACION A LO QUE VALGA EL ENEMIGO
            this->enemies.erase(this->enemies.begin()+i); // SE BORRA AL ENEMIGO
        }
    }
}

void Game::colissionBulletEnemy(){
    // BUCLE FOR PARA QUE SE CUMPLA PARA CADA JUGADOR
    for (int i = 0; i < players.size(); ++i) {
        // Colision bala con enemigo
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
    }
}

void Game::colissionPlayerEnemy(){
    // BUCLE FOR PARA QUE SE CUMPLA PARA CADA JUGADOR
    for_each (all(players),[&](Player & player) {
        // Colision jugador con enemigo
        for(int j=0; j<enemies.size(); ++j) {
            if (player.getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                enemies.erase(enemies.begin() + j); // Se borra el enemigo al chocar con la nave
                player.takeDamage(); // La nave recibe dano al chocar con la el enemigo
                this->chock.setBuffer(chockBuff); // Setear sonido cuando choca con el enemigo
                this->chock.play(); // Reproducir sonido cuando choca con el enemigo
            }
        }
    });
                                                                    /*for(auto & player: players) {
                                                                        // Colision nave con enemigo
                                                                        for (int j = 0; j < enemies.size(); ++j) {
                                                                            if (player.getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                                                                                enemies.erase(enemies.begin() + j); // Se borra el enemigo al chocar con la nave
                                                                                player.takeDamage(); // La nave recibe dano al chocar con la el enemigo
                                                                                this->chock.setBuffer(chockBuff); // Setear sonido cuando choca con el enemigo
                                                                                this->chock.play(); // Reproducir sonido cuando choca con el enemigo
                                                                            }
                                                                        }
                                                                    }*/
}
//----------------------------------------------------------------------------------------
void Game::playerupdate(){
    colissionBulletEnemy(); // COLISIONES ENTRE LA BALA DEL JUGADOR Y EL ENEMIGO
    colissionPlayerEnemy(); // COLISIONES ENTRE EL JUGADOR Y EL ENEMIGO

    // BUCLE FOR PARA QUE SE CUMPLA PARA CADA JUGADOR
//    for (int i = 0; i < players.size(); ++i) {
//        this->players[i].update(); // Para que cada jugador pueda moverse, disparar ,etc
//        this->updateUI(); // UI UPDATE
//        this->controlBoundsNave(); // Controlar que la nave no se salga de los bordes la ventana
//    }
    for_each (all(players),[&](Player & player) {
        player.update(); // Para que cada jugador pueda moverse, disparar ,etc
        this->updateUI(); // UI UPDATE
        this->controlBoundsNave(); // Controlar que la nave no se salga de los bordes la ventana
    });
}
//----------------------------------------------------------------------------------------
void Game::drawUI(){
    // DIBUJAR TEXTO QUE SIGUE AL JUGADOR
//    for (const auto & followPlayerText : this->followPlayerTexts) {
//        this->window->draw(followPlayerText);
//    }
    for_each (all(this->followPlayerTexts),[&](sf::Text & followPlayerText) {
        this->window->draw(followPlayerText);
    });

    // DIBUJAR TEXTO ESTATICO (el Score)
//    for (const auto & staticPlayerText : this->staticPlayerTexts) {
//        this->window->draw(staticPlayerText);
//    }
    for_each (all(this->staticPlayerTexts),[&](sf::Text & staticPlayerText) {
        this->window->draw(staticPlayerText);
    });

    // DIBUJAR GAME OVER
    if(this->players[0].getHP() <= 0){
        this->window->draw(gameOverText); // dibujar texto game over
        this->window->draw(restartText); // dibujar texto restart over
    }

    // DIBUJAR YOU WIN
    if(this->score >= GameConfig::WIN_SCORE) {
        this->window->draw(youWinText); // dibujar texto you win
        this->window->draw(restartText); // dibujar texto you win
    }
}

void Game::draw() {
    window->clear(); // "PROTOCOLO SFML"

    // SI LA VENTANA ESTA EN ESTADO GAME
    if(wind.get_WINDOW() == game){
        // DIBUJAR JUGADOR(ES)
        for (auto & player : this->players) {
            player.draw(*this->window);
        }
        // DIBUJAR ENEMIGOS
        for(auto & enemie : this->enemies){
            enemie.draw(*this->window);
        }
        this->drawUI(); // DIBUJAR TODOS LOS TEXTO (INTERFAZ GRAFICA)
    }
    // SI LA VENTANA ESTA EN ESTADO MENU
    if(wind.get_WINDOW() == menu){
        wind.draw(*this->window); // DIBUJAR LA VENTANA DEL MENU
    }

    window->display(); // PARA QUE APAREZCAN LAS COSAS DIBUJADAS
}

void Game::controlBoundsNave() {
    // BUCLE FOR PARA QUE SE CUMPLA PARA TODOS LOS JUGADORES
    for (int i = 0; i < players.size() ; ++i) {
        //BORDE IZQUIERDO
        if (this->players[i].getSprite().getPosition().x <= 0) {
            this->players[i].getSprite().setPosition(
                0.0f, this->players[i].getSprite().getPosition().y);
        }
        // BORDE DERECHO
        if (this->players[i].getSprite().getPosition().x >= window->getSize().x -
        this->players[i].getSprite().getGlobalBounds().width) {
            this->players[i].getSprite().setPosition(window->getSize().x
            - this->players[i].getSprite().getGlobalBounds().width, this->players[i].getSprite().getPosition().y);
        }
        // BORDE ARRIBA
        if (this->players[i].getSprite().getPosition().y <= 0) {
            this->players[i].getSprite().setPosition(
                this->players[i].getSprite().getPosition().x, 0.0f);
        }
        // BORDE ABAJO
        if (this->players[i].getSprite().getPosition().y >= window->getSize().y
        - this->players[i].getSprite().getGlobalBounds().height) {
            this->players[i].getSprite().setPosition(this->players[i].getSprite().getPosition().x,
                    window->getSize().y - this->players[i].getSprite().getGlobalBounds().height);
        }
    }
}

