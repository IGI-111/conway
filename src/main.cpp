#include "conway.hpp"
#include <SFML/Graphics.hpp>
#include <thread>

int main(void) {
    float width = 400;
    float height = 400;
    sf::RenderWindow window(sf::VideoMode(width, height, 1), "Life", sf::Style::Default & ~sf::Style::Resize);
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
