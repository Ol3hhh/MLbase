#include <iostream>
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Button.h"
#include "Iterating.h"

bool isMenu = true;

int main() {
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "X and Y Axes");

    // Load font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }

    // Create button
    Button It(100, 100, 200, 50, "Iterating", font, 24);
    Button Df(100, 200, 200, 50, "Differentiation ", font, 24);

    // Iterating and Draw setup
    Iterating iter;
    float w = iter.counting();
    Draw drawer(window, w);

    std::cout << w << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (It.isClicked(sf::Mouse::getPosition(window))) {
                        std::cout << "Button clicked" << std::endl;
                        isMenu = false;
                    }
                }
            }
        }

        // Clear window with white background
        window.clear(sf::Color::White);

        if (isMenu) {
            It.draw(window);
            Df.draw(window);
        }
        else {
            drawer.draw();
        }

        window.display();
    }

    return 0;
}
