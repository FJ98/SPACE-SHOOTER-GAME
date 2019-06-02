#include "Game.h"

const int WIDTH = 600, HEIGHT = 900;
int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Juego",sf::Style::Default) ;

    Game game(&window);

    // loop
    while(window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) {window.close();}
            if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }
        game.update();
        game.draw();
    }
    return 0;
}