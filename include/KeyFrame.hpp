#pragma once

#include <string>

using namespace std;

enum ReferenceFrame {
	STARTINGCOORDS,
	ENEMYCOORDS,
	INFRONTENEMY
};

struct KeyFrame {
	int frame;
	string animation;
	int x;
	int y;
	ReferenceFrame rf;

	KeyFrame(int f, string a, int xTemp, int yTemp, ReferenceFrame r);
};
