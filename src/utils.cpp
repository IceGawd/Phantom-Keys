#include "utils.hpp"
#include "Fightable.hpp"
#include "Enemy.hpp"
#include "RenderWindow.hpp"

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

float weighted(vector<Fightable*> party) {
	return 0.39 * pow(party.size(), 0.79) + 1.15 * average(party);
}

float weighted(vector<Enemy*> party) {
	vector<Fightable*> ugh;
	for (Enemy* e : party) {
		ugh.push_back((Fightable*) e);
	}
	return weighted(ugh);
}


float average(vector<Fightable*> party) {
	float answer = 0;
	for (Fightable* member : party) {
		answer += member->stats.getLevel();
	}
	return answer / party.size();
}

int diffSum(int a, int b) {
	int accuracy = a - b; // -x to x
	int evasion = a + b; // 0 to 2x
	return accuracy / evasion; // -1 to 1
}

float quadratic(float a, float b, float c) {
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

float increase(float initial, float percent) {
	return initial + percent * (1 - initial);
}

float distanceFrom(float x, float y) {
	return sqrt(x * x + y * y);
}

// From 0 to 2pi
float angleFromCoords(float x, float y) {
	float angle;
	if (x == 0) {
		if (y >= 0) {
			angle = 3.0 * M_PI / 2.0;
		}
		else {
			angle = M_PI / 2.0;
		}
	}
	else if (x > 0) {
		angle = -atan(y / x);
		if (angle < 0) {
			angle += 2.0 * M_PI;
		}
	}
	else {
		angle = M_PI - atan(y / x);
	}
	return angle;
}

void arrowChange(RenderWindow* window, vector<SDL_Scancode>& keys, bool* direction, void (*foo)(vector<void*>), vector<void*> passingArgument) {
	bool unpressed = true;
	for (SDL_Scancode key : keys) {
		if (window->keyboard[key]) {
			if (!(*direction)) {
				if (foo != nullptr) {
					foo(passingArgument);
				}
				*direction = true;
			}
			unpressed = false;
		}
	}
	if (unpressed) {
		*direction = false;
	}
}