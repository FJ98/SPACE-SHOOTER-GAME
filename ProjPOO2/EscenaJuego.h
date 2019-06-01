// Created by felix on 5/30/2019.
#ifndef PROJPOO2_ESCENAJUEGO_H
#define PROJPOO2_ESCENAJUEGO_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "clasesBase/BaseScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bala.h"

using namespace std;

class EscenaJuego : public BaseScene {
private:
    Player *player;						// el jugador
    std::vector<Enemy *> enemigos;				// arreglo con las pelotas
    float minVel;						// velocidad m�nima de la pr�xima pelota que se creara
    sf::Clock timeToNewBall;		    // reloj para medir cu�ndo crear una nueva pelota
    float score;						// puntaje
    sf::Text scoreText;					// texto para mostrar el puntaje
    sf::Font fontScoreText;				// fuente del texto
    void createNewBall(float minVel);	// agregar una nueva pelota
    sf::Texture texBackground;			// textura del fondo
    sf::Sprite spBackground;			// sprite del fondo

public:
    EscenaJuego();
    void update(float elapsed);
    void draw(sf::RenderWindow &w);
};




#endif //PROJPOO2_ESCENAJUEGO_H
