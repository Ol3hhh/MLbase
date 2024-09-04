#pragma once
#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include <iostream>
#include "Config.h"
#include "Base.h"
#include "Rescale.h"
class SGD : public Base
{
private:
	float nu = 0.0005;
	int N = 500;
	float ld = 0.01; // lambda
	float Q =0;
public:
	SGD();
	void x_init();
	float L(size_t i);
	Eigen::Matrix<float, 3, 1> gradL(int k);

	int generateK(int length_x);
	void drawLine(sf::RenderWindow& m_window) override;
	void counting() override;
};

