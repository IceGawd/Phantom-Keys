#include "utils.hpp"

float random(){
	return (float) rand() / RAND_MAX;
}

float rand(float std, float m) {
	return m + std * invNorm(random());
}

float invNorm(float x) {
	if (x < 0.5) {
		return -RationalApproximation(sqrt(-2.0 * log(x)));
	}
	else {
		return RationalApproximation(sqrt(-2.0 * log(1 - x)));
	}
}

float RationalApproximation(float t) {
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) / (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}

template <typename T>
float weighted(vector<T> levels) {
	return 0.39 * pow(levels.size(), 0.79) + 1.15 * average(levels);
}

template <typename T>
float average(vector<T> levels) {
	float answer = 0;
	for (T level : levels) {
		answer += level;
	}
	return answer / levels.size();
}

float quadratic(float a, float b, float c) {
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

float increase(float initial, float percent) {
	return initial + percent * (1 - initial);
}