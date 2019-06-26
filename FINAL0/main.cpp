#include "Game.h"
#include <stdlib.h>
#include <thread>


int main() {

    srand(time(nullptr));
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Juego",sf::Style::Default) ;

    Game *game = new Game(&window);
    // loop
    while(window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) {window.close();}
            if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
            }

        }
        game->update();
        //std::thread t1(&Game::enemyUpdate, game);
        //std::thread t2(&Game::playerUpdate, game);
        //t1.join();
        //t2.join();

        game->draw();
    }

    delete game;
    return 0;
}