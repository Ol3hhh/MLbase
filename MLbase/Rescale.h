#pragma once
#include "Config.h"
inline float rescaleX(float x) {
	return (SIZE / 2) + (x * (SIZE/20));
}

inline float rescaleY(float y) {
	return (SIZE / 2) - (y * (SIZE / 20));
}