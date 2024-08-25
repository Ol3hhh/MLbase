#pragma once
#include "Config.h"
inline float rescaleX(float x) {
	if (x < 0) {
		return (SIZE / 2) - (x * (SIZE/20));
	} else if (x > 0) {
		return (SIZE / 2) + (x * (SIZE / 20));
	}
	return SIZE / 2;
}

inline float rescaleY(float y) {
	if (y < 0) {
		return (SIZE / 2) + (y * (SIZE / 20));
	}
	else if (y > 0) {
		return (SIZE / 2) - (y * (SIZE / 20));
	}
	return SIZE / 2;
}