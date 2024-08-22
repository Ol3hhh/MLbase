#pragma once
#include <Eigen/Dense>
#include "Config.h"

class Differentiation {
private:
    Eigen::Matrix<float, 3, 1> w;
    Eigen::Matrix<float, 3, 1> x[length_x]; // Array of Eigen matrices

public:
    Differentiation();
    void counting();

private:
    void x_init();  // No need to pass x as a parameter
};
