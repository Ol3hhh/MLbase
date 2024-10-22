#include "Differentiation.h"

Differentiation::Differentiation() {
    w.setZero();
    counting();
}

void Differentiation::x_init() {
    // Directly modify the class member variable 'x'
    for (size_t i = 0; i < length_x; i++) {
        for (size_t j = 0; j < 2; j++) {
            x[i](j, 0) = x_train[i][j];
        }
        x[i](2, 0) = 1;
    }
}

void Differentiation::counting() {
    x_init();  // No need to pass x

    Eigen::Matrix<float, 1, 3> a;
    a.setZero();
    Eigen::Matrix<float, 3, 3> b;
    b.setZero();

    for (size_t i = 0; i < length_x; i++) {
        a = a + x[i].transpose() * y_train[i];
        b = b + x[i] * x[i].transpose() * pow(y_train[i], 2);
    }

    w = a * b.inverse();

    std::cout << w << std::endl;
    std::cout << "<<<<<<<<" << std::endl;
}

void Differentiation::drawLine(sf::RenderWindow& m_window) {
    
    for (float x_ = 0; x_ <= SIZE; x_ += 10) { // x_ bc we have matrix x
        float y_ = -(w(2, 0) + x_ * w(0, 0)) / w(1, 0); // w(0,0) = w_1 | w(1, 0) = w_2 | w(2, 0) = w_0
        // Transform the point's position to fit in the window
        float xPos = SIZE / 2 + x_;
        float yPos = SIZE / 2 - y_;
        functionPoints.push_back(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::Green));
    }
    m_window.draw(&functionPoints[0], functionPoints.size(), sf::LinesStrip);
}
