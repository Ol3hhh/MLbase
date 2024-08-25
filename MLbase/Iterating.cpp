#include "Iterating.h"
int Iterating::sign(float arg) {
	if (arg < 0) {
		return -1;
	}
	else if (arg > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

float Iterating::a(float x[], float w[]) {
	return sign(w[0] * x[0] + w[1] * x[1]);
}

float Iterating::counting() {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < length_x; j++) {
			x[0] = x_train[j][0];
			x[1] = x_train[j][1];
			if (a(x, w)*y_train[j] < 0) {
				w[0] = w[0] + mu * y_train[j];
				Q++;
			}
		}

		

		if (Q == 0) {
			return w[0];
		}
	}
	return w[0];
}

void Iterating::drawLine(sf::RenderWindow& m_window) {
	float w[2];
	w[0] = counting();
	w[1] = -1;
	for (float x = 0; x <= SIZE; x += 10) {
		float y = (-x) * w[0] / w[1];
		// Transform the point's position to fit in the window
		float xPos = SIZE / 2 + x;
		float yPos = SIZE / 2 - y;
		functionPoints.push_back(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color::Green));
	}
	m_window.draw(&functionPoints[0], functionPoints.size(), sf::LinesStrip);
}