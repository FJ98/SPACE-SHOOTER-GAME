#include "Game.h"
#include <thread>
#include <exception>
int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Shooter", sf::Style::Default);
        Game *game = new Game(&window);
        bool isPaused = false;
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed || game->getExit()) { window.close(); }
                if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); }
                if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::R &&
                    ((game->getScore() >= 20) || (game->getPlayers()[0].getHP() <= 0))) {
                    delete game;
                    game = new Game(&window);
                    std::cout << "RESET" << std::endl;
                }
                if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                    isPaused = true;
                    game->getMusic().pause();
                    std::cout << "PAUSAA" << std::endl;
                }
                if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::C) {
                    isPaused = false;
                    game->getMusic().play();
                    std::cout << "Continue" << std::endl;
                }
            }
            if (!isPaused) {
//            game->update();
                std::thread t1(&Game::update, game);
                t1.join();
                isPaused = false;
            }

            game->draw();
        }
        delete game;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}