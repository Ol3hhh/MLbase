#pragma once
#include "Config.h"
#include <SFML/Graphics.hpp>
#include "Base.h"

class Iterating :public Base
{
private:
	float w[2] = { 0, -1 };
	float x[2];

	int Q = 0;
	int last_error_index = -1;
	int N = 500;//number of iteratings
	float mu = 0.1;//step of learning
	float e = 0.1; //shift of the line

	
public:
	int sign(float arg);
	float a(float x[], float w[]);
	float count(); //bc this is not void
	void drawLine(sf::RenderWindow& m_window) override;
	void counting() override;
	void x_init() override;
};

