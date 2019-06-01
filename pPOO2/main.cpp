#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
using namespace std;
using namespace sf;
const int SCREEN_WIDTH = 900; const int SCREEN_HEIGHT = 600; const float PLAYER_WIDTH = 50.0f; const float PLAYER_HEIGHT = 50.0f;
const float PLAYER_X_POSITION = static_cast<float>(SCREEN_WIDTH)/2.1f;
const float PLAYER_Y_POSITION = static_cast<float>(SCREEN_HEIGHT) - 100.0f; const float NAVE_SPEED = 4.0f;
const float BALA_X_POSITION = 100.0f; const float BALA_Y_POSITION = 200.0f; const float BALA_SPEED = 20.0f; const int TIME_BALA_APPEAR = 20;
const float ENEMY_SPEED = 2.0f; const int TIME_ENEMY_APPEAR = 50;
class Bala{
public:
    sf::Sprite sprite;
    Bala(sf::Texture *texture, sf::Vector2f pos){this->sprite.setTexture(*texture); this->sprite.setPosition(pos);}
    explicit Bala(sf::Texture *texture){this->sprite.setTexture(*texture);}
    ~Bala()= default;
};
class Player{
public:
    int HP;
    int HPMax;
    sf::Sprite sprite;
    sf::Texture *texture;
    std::vector<Bala> balas;
    sf::Vector2f vecP;

    explicit Player(sf::Texture *texture){
        this->texture = texture;
        this->HPMax = 10; this->HP = this->HPMax;
        this->sprite.setTexture(*texture); this->sprite.setScale(0.05f,0.05f);
    }
    ~Player() = default;
};

class Enemy;
void crearVentana();

int main() {
    std::random_device rd;
    srand(time(nullptr));
    std::cout << "Hello, World!" << std::endl;
    crearVentana();
    return 0;
}

class Enemy{
public:
    int HP;
    int HPMax;
    sf::Sprite sprite;
    //sf::Texture *texture;
    Enemy(sf::Texture *texture, sf::Vector2u windowSize) {
        this->HPMax = rand()%3+1;
        this->HP = this->HPMax;
        this->sprite.setTexture(*texture);
        this->sprite.setScale(0.03f, 0.03f);
        this->sprite.setPosition(rand() %
        static_cast<int>(windowSize.x - this->sprite.getGlobalBounds().width), 0.0f); // ENEMY en posicion random
    }
    ~Enemy() = default;
};

void controlarTeclado(Player p){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {p.sprite.move(-NAVE_SPEED, 0.0f);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {p.sprite.move(NAVE_SPEED, 0.0f);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {p.sprite.move(0.0f, -NAVE_SPEED);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {p.sprite.move(0.0f, NAVE_SPEED);}
}

void crearVentana(){
    // INIT VARIABLES
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "FelixSolano",sf::Style::Default); // Init WINDOW
    window.setFramerateLimit(60);

    sf::Font font; //Init TEXTO
    font.loadFromFile("./fonts/arial.ttf");

    //Init textures
    sf::Texture playerTexture;
    playerTexture.loadFromFile("./images/nave.png");
    sf::Texture balaTexture;
    balaTexture.loadFromFile("./images/bala.png");
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("./images/enemigo1.png");
/*
    // UI Init
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f,10.0f);

    // Game Over Init
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(static_cast<float>(window.getSize().x)/2, static_cast<float>(window.getSize().y)/2);
    gameOverText.setString("GAME OVER!");
*/
    // Init PLAYER
    //sf::RectangleShape player(sf::Vector2f(PLAYER_WIDTH,PLAYER_HEIGHT)); player.setPosition(PLAYER_X_POSITION, PLAYER_Y_POSITION); player.setTexture(&playerTexture);
    Player p(&playerTexture);
    int shootTimer = TIME_BALA_APPEAR;
    int score{0};
    p.sprite.setPosition(PLAYER_X_POSITION, PLAYER_Y_POSITION);
//    sf::Text hpText; hpText.setFont(font);
//    hpText.setCharacterSize(12); hpText.setFillColor(sf::Color::White);

    // Init ENEMY
    std::vector<Enemy> enemigos;
    int enemyAppearTimer = 0;
//    sf::Text eHpText; eHpText.setFont(font);
//    eHpText.setCharacterSize(12); eHpText.setFillColor(sf::Color::White);
//----------------------------------------------------------------------------------------------------------------------
    while(window.isOpen()){
        sf::Event evnt{};
        while(window.pollEvent(evnt)){
            switch (evnt.type){
                case sf::Event::Closed :
                    window.close();
                    break;
            }
        }
//----------------------------------------------------------------------------------------------------------------------
  //      if (p.HP > 0){
        // PLAYER
        // Teclas para mover nave
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { p.sprite.move(-NAVE_SPEED, 0.0f); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { p.sprite.move(NAVE_SPEED, 0.0f); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { p.sprite.move(0.0f, -NAVE_SPEED); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { p.sprite.move(0.0f, NAVE_SPEED); }
        if (shootTimer < TIME_BALA_APPEAR){shootTimer++;}  // Controlar tiempo de disparo
        // Unir nave con balas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= TIME_BALA_APPEAR) {// Disparar
            p.balas.emplace_back(Bala(&balaTexture, p.sprite.getPosition())); //Nave dispara balas
            shootTimer = 0; //reset timer
        }
//        hpText.setPosition(p.sprite.getPosition().x, p.sprite.getPosition().y - hpText.getGlobalBounds().height);
//        hpText.setString(std::to_string(p.HP) + "/" + std::to_string(p.HPMax));
        // Nave dentro de los bordes de la ventana
        if (p.sprite.getPosition().x <= 0) { p.sprite.setPosition(0.0f, p.sprite.getPosition().y); } //borde izquierdo
        if (p.sprite.getPosition().x >= window.getSize().x - p.sprite.getGlobalBounds().width) { //borde derecho
            p.sprite.setPosition(window.getSize().x - p.sprite.getGlobalBounds().width, p.sprite.getPosition().y);
        }
        if (p.sprite.getPosition().y <= 0) { p.sprite.setPosition(p.sprite.getPosition().x, 0.0f); } //borde de arriba
        if (p.sprite.getPosition().y >= window.getSize().y - p.sprite.getGlobalBounds().height) { //borde de abajo
            p.sprite.setPosition(p.sprite.getPosition().x, window.getSize().y - p.sprite.getGlobalBounds().height);
        }
//-------------------------------------------------------------------------------------------------------------------------
        // BALAS
        for (int i = 0; i < p.balas.size(); i++) {
            // Mover
            p.balas[i].sprite.move(0.0f,-BALA_SPEED);
            // Fuera de bordes
            if (p.balas[i].sprite.getPosition().y > window.getSize().y){
                p.balas.erase(p.balas.begin()+i);
                break;
            }
            // Colisiones con enemigo
            for (int j = 0; j < enemigos.size() ; j++) {

                if ( p.balas[i].sprite.getGlobalBounds().intersects(enemigos[j].sprite.getGlobalBounds()) ){
//                    if (enemigos[j].HP <= 1){
//                        score += enemigos[j].HP;
//                        enemigos.erase(enemigos.begin() + j); // enemigo se muere
//                    }else{
//                        enemigos[j].HP--; // enemigo se dana
//                    }
                    enemigos.erase(enemigos.begin() + j); // se borran enemigos cuando chocan con la bala
                    p.balas.erase(p.balas.begin() + i); // se borra la bala cuando choca con enemigos
                    break;
                }
            }
        }

//-----------------------------------------------------------------------------------------------------------------------
        // ENEMY
        if (enemyAppearTimer < TIME_ENEMY_APPEAR){enemyAppearTimer++;} // Tiempo de aparicion para cada enemigo
        // Enemigo aparicion
        if (enemyAppearTimer >= TIME_ENEMY_APPEAR){
            enemigos.emplace_back( Enemy(&enemyTexture,window.getSize()) ); // Aparece el enemigo
            enemyAppearTimer = 0; // reset Timer
        }
        // Mover enemigos
        for (int i = 0; i < enemigos.size(); i++) {
            enemigos[i].sprite.move(0.0f, ENEMY_SPEED); //enemigos se mueven solos
            if (enemigos[i].sprite.getPosition().y <= 0 - enemigos[i].sprite.getGlobalBounds().height){
                enemigos.erase(enemigos.begin() + i);
                break;
            }
            // Colisiones Enemigo
            if (enemigos[i].sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds())){
                enemigos.erase(enemigos.begin() + i); //enemigo desaparece cuando entra en contacto con la nave
                p.HP--; // Nave se dana
                break;
            }
        }
        // UI Update
//        scoreText.setString("Score: " + std::to_string(score));
//        }
//-------------------------------------------------------------------------------------------------------------------------
        // Draw
        window.clear();
        // Draw Player
        window.draw(p.sprite);
        //Draw Balas
        for (auto & bala : p.balas) {
            window.draw(bala.sprite);
        }
        // Draw Enemigos
        for (auto & enemigo : enemigos) {
//            eHpText.setString(std::to_string(enemigos[k].HP)+"/"+std::to_string(enemigos[k].HPMax));
//            eHpText.setPosition(enemigos[k].sprite.getPosition().x, enemigos[k].sprite.getPosition().y - eHpText.getGlobalBounds().height);
//            window.draw(eHpText);
            window.draw(enemigo.sprite);
        }
        // UI
//        window.draw(scoreText);
//        window.draw(hpText);
//        if (p.HP <= 0){window.draw(gameOverText);}
//-------------------------------------------------------------------------------------------------------------------------
        window.display();
    }
}


/*
void controlarMouse(sf::RectangleShape& player, sf::RenderWindow& window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    player.setOrigin(PLAYER_WIDTH/2, PLAYER_HEIGHT/2);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

}
 */


/*
        for (int j = 0; j < p.balas.size(); j++) {
            // balas se mueven solas
            p.balas[j].sprite.move(0.0f,-20.0f);

            //fuera de los bordes de la ventana
            if(p.sprite.getPosition().x  > window.getSize().x){
                p.balas.erase(p.balas.begin() + j);
            }
        }
        for(auto & bala: p.balas){
            bala.sprite.move(0.0f,-BALA_SPEED); // balas se mueven solas
            //fuera de los bordes de la ventana
            if(bala.sprite.getPosition().y  > window.getSize().y){p.balas.erase(p.balas.begin() + static_cast<long long>(bala.sprite.getPosition().y));}
        }
*/

/*
 *      for(auto & enemigo: enemigos){
            enemigo.sprite.move(0.0f, ENEMY_SPEED);
            if ( enemigo.sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds()) ){
                enemigos.erase(enemigos.begin() + static_cast<long long>(enemigo.sprite.getPosition().y));
            }
        }
        for (int i = 0; i < enemigos.size(); i++) {
            enemigos[i].sprite.move(0.0f, ENEMY_SPEED); //enemigos se mueven solos
            //if (enemigos[i].sprite.getPosition().y <= 0 - enemigos[i].sprite.getGlobalBounds().height){enemigos.erase(enemigos.begin() + i);}
            if (enemigos[i].sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds())){
                enemigos.erase(enemigos.begin() + i); //enemigo desaparece cuando entra en contacto con la nave
            }
        }

        for(const auto& enemigo: enemigos){
            window.draw(enemigo.sprite);
        }
        */