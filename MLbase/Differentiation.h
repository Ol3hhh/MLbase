#pragma once
#include <Eigen/Dense>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include <iostream>
class Differentiation {
private:
    Eigen::Matrix<float, 3, 1> w;
    Eigen::Matrix<float, 3, 1> x[length_x]; // Array of Eigen matrices
    std::vector<sf::Vertex> functionPoints;
public:
    Differentiation();
    void counting();
    void drawLine(sf::RenderWindow& m_window);
    void x_init();  // No need to pass x as a parameter
};
