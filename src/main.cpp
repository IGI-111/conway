#include "conway.hpp"
#include <SFML/Graphics.hpp>
#include <thread>
#include <string>

int main(int argc, char *argv[]) {
    int width = 100, height = 100;
    if(argc == 2){
        width = height = std::stoi(std::string(argv[1]));
    } else if(argc == 3){
        width = std::stoi(std::string(argv[1]));
        height = std::stoi(std::string(argv[2]));
    }

    sf::RenderWindow window(sf::VideoMode(width, height, 1), "Life", sf::Style::None);
    Conway::Board state(width, height);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        state.render(window);
        window.display();

        state.tick();
    }
}
