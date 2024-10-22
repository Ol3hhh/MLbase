#include "Gradient.h"

SGD::SGD() {
	w.setZero();
    x_init();
    counting();

}

void SGD::x_init() {
    for (size_t i = 0; i < length_x; i++) {
        for (size_t j = 0; j < 2; j++) {
            x[i](j, 0) = x_train[i][j];
        }
        x[i](2, 0) = 1;
    }
}

float SGD::L(size_t i) {
    float e = 0.0;
    e = 1.0 / length_x * (2.0 / (1.0 + exp(w.dot(x[i]) * y_train[i])));
    return e;
}

Eigen::Matrix<float, 3, 1> SGD::gradL(int k) {
    return -2.0 / pow((1.0 + exp(w.dot(x[k]) * y_train[k])), 2.0) * exp(w.dot(x[k]) * y_train[k]) * x[k] * y_train[k];
}

void SGD::counting() {
    float e;
    int k;
    for (size_t i = 0; i < length_x; i++) {
        Q = Q + L(i);
    }

    
    for (size_t i = 0; i < N; i++) {
        k = generateK(length_x);
        w = w - nu * gradL(k);
        e = L(k);
        Q = ld * e + (1 - ld) * Q;
    }    
    std::cout << 1 << std::endl;
}

void SGD::drawLine(sf::RenderWindow& m_window) {
    std::cout << "draw";
    for (float x_ = 0; x_ <= SIZE; x_ += 10) { // x_ bc we have matrix x
        float y_ = -(w(2, 0) + x_ * w(0, 0)) / w(1, 0); // w(0,0) = w_1 | w(1, 0) = w_2 | w(2, 0) = w_0
        // Transform the point's position to fit in the window
        float xPos = SIZE / 2 + x_;
        float yPos = SIZE / 2 - y_;
        functionPoints.push_back(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::Green));
    }
    m_window.draw(&functionPoints[0], functionPoints.size(), sf::LinesStrip);
}

int SGD::generateK(int length_x) {
    // Use the current time as the seed for the random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed); // Mersenne Twister engine seeded with current time

    // Create a distribution in the range [0, length_x)
    std::uniform_int_distribution<> distrib(0, length_x - 1);

    // Generate and return the random number
    return distrib(gen);
}