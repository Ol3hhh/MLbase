#include "Draw.h"
#include <iostream>
#include <cmath>

// Constructor to initialize the RenderWindow and load the font
Draw::Draw(sf::RenderWindow& window) : m_window(window) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }
}

// Draw the X-axis
void Draw::drawXAxis() {
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(0, m_window.getSize().y / 2);
    xAxis[1].position = sf::Vector2f(m_window.getSize().x, m_window.getSize().y / 2);
    xAxis[0].color = sf::Color::Black;
    xAxis[1].color = sf::Color::Black;
    m_window.draw(xAxis);
}

// Draw the Y-axis
void Draw::drawYAxis() {
    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(m_window.getSize().x / 2, 0);
    yAxis[1].position = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y);
    yAxis[0].color = sf::Color::Black;
    yAxis[1].color = sf::Color::Black;
    m_window.draw(yAxis);
}



// Draw grid and labels for both axes
void Draw::drawGridAndLabels() {
    const int step = 50; // Distance between grid lines
    int x = 0;
    int y = 0;
    for (size_t i = 0; i < SIZE / step; i++) {
        sf::VertexArray xAxis(sf::Lines, 2);
        xAxis[0].position = sf::Vector2f(0, y);
        xAxis[1].position = sf::Vector2f(SIZE, y);
        xAxis[0].color = sf::Color(210, 210, 210);
        xAxis[1].color = sf::Color(210, 210, 210);
        m_window.draw(xAxis); 
        y += step;

        sf::VertexArray yAxis(sf::Lines, 2);
        yAxis[0].position = sf::Vector2f(x, 0);
        yAxis[1].position = sf::Vector2f(x, SIZE);
        yAxis[0].color = sf::Color(210, 210, 210);
        yAxis[1].color = sf::Color(210, 210, 210);
        m_window.draw(yAxis);
        x += step;
        
    }
    



    // Create labels for X axis
    for (int i = -10; i <= 10; ++i) {
        sf::Text label;
        label.setFont(font);
        label.setString(std::to_string(i * 10));
        label.setCharacterSize(12);
        label.setFillColor(sf::Color::Black);
        label.setPosition(SIZE / 2 + i * 100 - 10, SIZE / 2 + 10); // Adjust x position and y position below the X axis
        xLabels.push_back(label);
    }

    // Create labels for Y axis
    for (int i = -10; i <= 10; ++i) {
        sf::Text label;
        label.setFont(font);
        label.setString(std::to_string(i * 10));
        label.setCharacterSize(12);
        label.setFillColor(sf::Color::Black);
        label.setPosition(SIZE / 2 + 10, SIZE / 2 - i * 100 - 10); // Adjust x position right of the Y axis
        yLabels.push_back(label);
    }
}

// Initialize points based on the data in Config.h
void Draw::initPoints() {
    for (size_t i = 0; i < length_x; i++) {
        points[i].setX(SIZE / 2 + x_train[i][0] * 5);
        points[i].setY(SIZE / 2 - x_train[i][1] * 5);
        points[i].setGroup(y_train[i]);
    }
}

// Draw points on the graph
void Draw::drawPoints() {
    for (size_t i = 0; i < length_x; i++) {
        sf::CircleShape circle(5);
        if (points[i].getGroup() == 1) {
            circle.setFillColor(sf::Color::Blue);
        }
        else {
            circle.setFillColor(sf::Color::Red);
        }
        circle.setPosition(points[i].getX(), points[i].getY());
        m_window.draw(circle);
    }
}







// Call all drawing functions
void Draw::draw() {
    drawGridAndLabels();
    for (const auto& label : xLabels) {
        m_window.draw(label);
    }
    for (const auto& label : yLabels) {
        m_window.draw(label);
    }
    drawXAxis();
    drawYAxis();
    initPoints();
    drawPoints();
}
