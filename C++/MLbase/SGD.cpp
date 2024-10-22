#include "SGD.h"

SGD::SGD() {
    w.setZero();  // Initialize weights to zero
    x_init();     // Initialize the x matrix with training data
}

void SGD::x_init() {
    for (size_t i = 0; i < length_x; i++) {
        for (size_t j = 0; j < 2; j++) {
            x[i](j, 0) = x_train[i][j];  // Set features
        }
        x[i](2, 0) = 1;  // Bias term
    }
}

float SGD::L(size_t i) {
    // Logistic loss function to prevent numerical instability
    float z = w.dot(x[i]) * y_train[i];
    return log(1 + exp(-z));  // Logistic loss function
}

Eigen::Matrix<float, 3, 1> SGD::gradL(int k) {
    // Gradient of logistic loss
    float z = w.dot(x[k]) * y_train[k];
    float multiplier = -1.0 / (1.0 + exp(z));
    return multiplier * x[k] * y_train[k];
}

void SGD::counting() {
    float prev_Q = std::numeric_limits<float>::max();  // For early stopping
    float e;
    int k;

    // Initial calculation of Q (Loss)
    for (size_t i = 0; i < length_x; i++) {
        Q += L(i);
    }

    // SGD iterations
    for (size_t iter = 0; iter < N; iter++) {
        k = generateK(length_x);
        w = w - nu * gradL(k);  // Update weights
        e = L(k);  // Loss for sample k
        Q = ld * e + (1 - ld) * Q;  // Update the loss using lambda

        // Early stopping condition
        if (std::abs(prev_Q - Q) < tolerance) {
            std::cout << "Converged after " << iter << " iterations." << std::endl;
            break;
        }
        prev_Q = Q;  // Update previous loss

        // Optional: visualize line classification logic
    }
}

void SGD::drawLine(sf::RenderWindow& m_window) {
    for (float x_ = 0; x_ <= SIZE; x_ += 10) {
        float y_ = -(w(2, 0) + x_ * w(0, 0)) / w(1, 0);
        float xPos = SIZE / 2 + x_;
        float yPos = SIZE / 2 - y_;
        functionPoints.push_back(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::Green));
    }
    m_window.draw(&functionPoints[0], functionPoints.size(), sf::LinesStrip);
}

int SGD::generateK(int length_x) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);  // Random number generator
    std::uniform_int_distribution<> distrib(0, length_x - 1);
    return distrib(gen);  // Return random index
}

void SGD::separate() {
    // Separation logic placeholder
}
