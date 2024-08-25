#pragma once
#include "Config.h"
#include <SFML/Graphics.hpp>
class Iterating
{
private:
	float w[2] = { 0, -1 };
	float x[2];

	int Q = 0;
	int last_error_index = -1;
	int N = 50;//number of iteratings
	float mu = 0.1;//step of learning
	float e = 0.1; //shift of the line

	std::vector<sf::Vertex> functionPoints;
public:
	int sign(float arg);
	float a(float x[], float w[]);
	float counting();
	void drawLine(sf::RenderWindow& m_window);
};

