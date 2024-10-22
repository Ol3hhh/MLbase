#pragma once
#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include "Config.h"
#include "Base.h"
#include "Rescale.h"

class SGD : public Base {
private:
    float nu = 0.0005;  // learning rate
    int N = 500;        // number of iterations
    float ld = 0.01;    // lambda (regularization)
    float Q = 0.0;      // loss
    const float tolerance = 1e-5; // Early stopping tolerance
public:
    SGD();
    void x_init();
    float L(size_t i);
    Eigen::Matrix<float, 3, 1> gradL(int k);
    int generateK(int length_x);
    void drawLine(sf::RenderWindow& m_window) override;
    void counting() override;
    void separate();
};
