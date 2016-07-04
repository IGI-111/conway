#include "conway.hpp"
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

Conway::Board::Board(size_t width, size_t height)
    : width(width), height(height), current(width * height),
      next(width * height) {
          size_t x = width / 2;
        for (size_t y = 1; y < height-1; ++y) {
            set_next(x, y, true);
        }
        current = next;
}

void Conway::Board::tick(void) {
    for (size_t x = 0; x < width; ++x) {
        for (size_t y = 0; y < height; ++y) {
            auto neighbours = count_neighbours(x, y);
            if (neighbours > 3 || neighbours < 2) {
                set_next(x, y, false);
            } else if (neighbours == 3) {
                set_next(x, y, true);
            }
        }
    }
    current = next;
}

void Conway::Board::set_next(size_t x, size_t y, bool value) {
    next[y * width + x] = value;
}

bool Conway::Board::get_current(size_t x, size_t y) const {
    x = x % width;
    y = y % height;
    return current[y * width + x];
}

unsigned Conway::Board::count_neighbours(size_t x, size_t y) const {
    return (get_current(x + 1, y) ? 1 : 0) +
           (get_current(x + 1, y + 1) ? 1 : 0) +
           (get_current(x, y + 1) ? 1 : 0) +
           (get_current(x - 1, y + 1) ? 1 : 0) +
           (get_current(x - 1, y) ? 1 : 0) +
           (get_current(x - 1, y - 1) ? 1 : 0) +
           (get_current(x, y - 1) ? 1 : 0) +
           (get_current(x + 1, y - 1) ? 1 : 0);
}

void Conway::Board::render(sf::RenderTarget &target) const {
    for (size_t x = 0; x < width; ++x) {
        for (size_t y = 0; y < height; ++y) {
            sf::RectangleShape rect(sf::Vector2f(1,1));
            rect.setPosition(target.mapPixelToCoords(sf::Vector2i(x, y)));
            rect.setFillColor(get_current(x, y) ? sf::Color::Black : sf::Color::White);
            target.draw(rect);
        }
    }
}
