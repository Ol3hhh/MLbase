#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& text, sf::Font& font, unsigned int charSize) {
    buttonShape.setPosition(x, y);
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setFillColor(sf::Color(100, 149, 237)); // Cornflower blue color
    buttonShape.setOutlineThickness(3.f);
    buttonShape.setOutlineColor(sf::Color::White);

    normalColor = sf::Color(100, 149, 237); // Cornflower blue
    hoverColor = sf::Color(72, 118, 255);  // Lighter blue
    borderColor = sf::Color::White;

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(charSize);
    buttonText.setFillColor(sf::Color::White); // Text color
    buttonText.setPosition(
        x + (width / 2.f) - (buttonText.getGlobalBounds().width / 2.f),
        y + (height / 2.f) - (buttonText.getGlobalBounds().height / 2.f)
    );
}

void Button::draw(sf::RenderWindow& window) {
    if (isMouseOver(sf::Mouse::getPosition(window))) {
        buttonShape.setFillColor(hoverColor);
    }
    else {
        buttonShape.setFillColor(normalColor);
    }

    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(sf::Vector2i mousePos) {
    return buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::setText(const std::string& text) {
    buttonText.setString(text);
}

void Button::setPosition(float x, float y) {
    buttonShape.setPosition(x, y);
    buttonText.setPosition(
        x + (buttonShape.getSize().x / 2.f) - (buttonText.getGlobalBounds().width / 2.f),
        y + (buttonShape.getSize().y / 2.f) - (buttonText.getGlobalBounds().height / 2.f)
    );
}

bool Button::isMouseOver(sf::Vector2i mousePos) {
    return buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
