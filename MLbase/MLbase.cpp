#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Draw.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "X and Y Axes");

    Draw drawer(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Draw the X and Y axes
        drawer.draw();
        window.display();
    }

    return 0;
}
