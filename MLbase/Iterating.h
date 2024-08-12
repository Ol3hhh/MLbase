#pragma once
#include "Config.h"
class Iterating
{
private:
	float w[2] = { 0, -1 };
	float x[2];

	int Q = 0;
	int last_error_index = -1;
	int N = 50;//number of iteratings
	float mu = 0.1;//step of learning
	float e = 0.1; //shift of the line
public:
	int sign(float arg);
	float a(float x[], float w[]);
	float counting();
};

