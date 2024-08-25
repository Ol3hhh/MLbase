#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rescale.h"
#include "Config.h"
#include "Point.h"
#include "Iterating.h"
#include "Differentiation.h"



class Draw {
public:
    // Constructor to initialize the RenderWindow and font
    Draw(sf::RenderWindow& window);

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

    
    // Method to call all draw functions
    void draw(int mode);

private:
    Point points[length_x];       // Array of points to be drawn
    //Iterating iter;

    sf::RenderWindow& m_window;   // Reference to the SFML RenderWindow
    sf::Font font;                // Font for drawing text labels
    std::vector<sf::Text> xLabels;
    std::vector<sf::Text> yLabels;
    
    float w[2];
};
