#include "Point.h"

float Point::getX1() const {
    return x1;
}

// Getter for y
float Point::getX2() const {
    return x2;
}


int Point::getGroup() const {
    return group;
}


// Setter for x
void Point::setX1(float xVal) {
    x1 = xVal;
}

// Setter for y
void Point::setX2(float yVal) {
    x2 = yVal;
}


void Point::setGroup(int groupVal) {
    group = groupVal;
}