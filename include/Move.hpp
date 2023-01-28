#pragma once

#include <vector>

#include "utils.hpp"

using namespace std;

struct Move {
	bool physical;
	float damage;
	int mana;
	vector<Tag> tags;

	Move(bool p, float d);
	Move(bool p, float d, int m);
}; 