#pragma once
#include <Eigen/Dense>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Base.h"
#include <iostream>
class Differentiation : public Base{
public:
    Differentiation();
    void counting() override;
    void drawLine(sf::RenderWindow& m_window) override;
    void x_init() override;  // No need to pass x as a parameter
};
