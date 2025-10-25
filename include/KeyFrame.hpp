#pragma once

#include <string>

#include "Fightable.hpp"
#include "utils.hpp"

using namespace std;

struct KeyFrame {
	int frame;
	string animation;
	int row;
	int x;
	int y;
	int rf;
	int inter;
	bool damage;
	int framedelay;

	KeyFrame(int f, string a, int ro, int xTemp, int yTemp, int r, int i, bool d = false, int fd = 0);
	void applyKeyframe(Fightable* attacker, KeyFrame& previous, int curFrame, Fightable* defender, bool reverse);
	pair<int, int> base(Fightable* attacker, Fightable* defender, bool reverse);
};
