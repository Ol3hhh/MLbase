#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& text, sf::Font& font, unsigned int charSize);
    void draw(sf::RenderWindow& window);
    bool isClicked(sf::Vector2i mousePos);
    void setText(const std::string& text);
    void setPosition(float x, float y);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Color normalColor;
    sf::Color hoverColor;
    sf::Color borderColor;

    bool isMouseOver(sf::Vector2i mousePos);
};


