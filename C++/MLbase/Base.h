#pragma once
#include <Eigen/Dense>
#include <SFML/Graphics.hpp>
#include "Config.h"
// this class is going to be a base class for some others which will have similar methods
class Base
{
protected:
	Eigen::Matrix<float, 3, 1> w;
	Eigen::Matrix<float, 3, 1> x[length_x]; // Array of Eigen matrices
	std::vector<sf::Vertex> functionPoints;
public:
	virtual void counting() = 0;
	virtual void drawLine(sf::RenderWindow& m_window) = 0;
	virtual void x_init() = 0;  // No need to pass x as a parameter
};

