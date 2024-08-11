#include "Point.h"

float Point::getX() const {
    return x;
}

// Getter for y
float Point::getY() const {
    return y;
}


int Point::getGroup() const {
    return group;
}


// Setter for x
void Point::setX(float xVal) {
    x = xVal;
}

// Setter for y
void Point::setY(float yVal) {
    y = yVal;
}


void Point::setGroup(int groupVal) {
    group = groupVal;
}