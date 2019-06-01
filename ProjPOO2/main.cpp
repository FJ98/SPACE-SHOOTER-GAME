#include <iostream>
#include <SFML/Graphics.hpp>
#include "clasesBase/Game.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    //sf::String title = "Tit";

    //Game game1({500,500}, title);
    //game1.gameLoop();

    BaseScene *scene = new EscenaInicio();
    Game &g = Game::create(sf::VideoMode(640, 400), scene,"FelixSolano");
    g.run();

    return 0;
}