#include <iostream>
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Button.h"


bool isMenu = true;
unsigned int mode;

int main() {
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "X and Y Axes");

    // Load font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }

    // Create button
    Button It(100, 100, 200, 50, "Iterating", font, 24); // mode = 1 
    Button Df(100, 200, 200, 50, "Differentiation ", font, 24); // mode = 2
    Button Exit(100, 100, 200, 50, "Exit", font, 24); 
    
    // Iterating and Draw setup
    Draw drawer(window);

    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (It.isClicked(sf::Mouse::getPosition(window)) && isMenu) {
                        std::cout << "Button 1 clicked" << std::endl;
                        isMenu = false;
                        mode = 1;
                    }
                    else if (Df.isClicked(sf::Mouse::getPosition(window)) && isMenu) {
                        std::cout << "Button 2 clicked" << std::endl;
                        isMenu = false;
                        mode = 2;
                    }
                    else if (Exit.isClicked(sf::Mouse::getPosition(window)) && !isMenu) {
                        std::cout << "Button Exit clicked" << std::endl;
                        isMenu = true;
                        mode = 0;
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
            drawer.draw(mode);
            Exit.draw(window);
        }

        window.display();
    }


    return 0;
}
