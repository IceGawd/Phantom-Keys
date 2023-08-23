#pragma once

#include "Fightable.hpp"

struct HealthBar {
	Entity* base;
	Entity* fullHealth;
	Entity* noHealth;

	double internalScaling;

	HealthBar(RenderWindow* window, int x, int y, int w, int h);
	~HealthBar();
	void represent(RenderWindow* window, Fightable* fighter);
};
