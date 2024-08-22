#include "Differentiation.h"

Differentiation::Differentiation() {
    w.setZero();
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


}
