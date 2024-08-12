#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Point.h"

class Draw {
public:
    // Constructor to initialize the RenderWindow and font
    Draw(sf::RenderWindow& window, float w_);

    // Method to draw the X-axis
    void drawXAxis();

    // Method to draw the Y-axis
    void drawYAxis();

    // Method to draw the grid and labels on the axes
    void drawGridAndLabels();

    // Method to initialize the points based on the data
    void initPoints();

    // Method to draw the points on the graph
    void drawPoints();

    void drawLine(float w[]);
    // Method to call all draw functions
    void draw();

private:
    Point points[length_x];       // Array of points to be drawn
    //Iterating iter;

    sf::RenderWindow& m_window;   // Reference to the SFML RenderWindow
    sf::Font font;                // Font for drawing text labels
    std::vector<sf::Text> xLabels;
    std::vector<sf::Text> yLabels;
    std::vector<sf::Vertex> functionPoints;
    float w[2];
};
