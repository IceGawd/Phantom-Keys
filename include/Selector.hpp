#pragma once

#include "Entity.hpp"

struct Selector {
	Entity* note;
	float angle = 0;
	bool snap = true;
	int selection = 0;
	int radius = 0;
	int xCenter = 0;
	int yCenter = 0;
	int radiusAim = 0;
	int xCenterAim = 0;
	int yCenterAim = 0;

	bool prevLeft = true;
	bool prevRight = true;
	bool prevEnter = true;

	Selector(RenderWindow& window);
	void render(RenderWindow* window);
};

void sIncrement(vector<void*> passingArgument);
void sDecrement(vector<void*> passingArgument);
void sEnter(vector<void*> passingArgument);