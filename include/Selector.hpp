#pragma once

#include "Entity.hpp"

struct Selector {
	Entity* note;
	float angle = 0;
	int radius = 0;
	int xCenter = 0;
	int yCenter = 0;
	int radiusAim = 0;
	int xCenterAim = 0;
	int yCenterAim = 0;

	Selector(RenderWindow& window);
	void render(RenderWindow* window);
};
