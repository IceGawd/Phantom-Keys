#pragma once

#include <string>

#include "Fightable.hpp"

using namespace std;

enum ReferenceFrame {
	GLOBALCOORDS, 
	STARTINGCOORDS,
	ENEMYCOORDS,
	INFRONTENEMY
};

enum Interpolation {
	CONSTANT, 
	LINEAR, 
	EXPONENTIAL, 
	LOGARITHMIC, 
	SQUARE_ROOT
};

struct KeyFrame {
	int frame;
	string animation;
	int row;
	int x;
	int y;
	ReferenceFrame rf;
	Interpolation inter;
	bool damage;
	int framedelay;

	KeyFrame(int f, string a, int ro, int xTemp, int yTemp, ReferenceFrame r, Interpolation i, bool d = false, int fd = 0);
	void applyKeyframe(Fightable* attacker, KeyFrame& previous, int curFrame, Fightable* defender, bool reverse);
	pair<int, int> base(Fightable* attacker, Fightable* defender, bool reverse);
};
